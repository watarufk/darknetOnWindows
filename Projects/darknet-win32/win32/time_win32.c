#include "time_win32.h"

// https://stackoverflow.com/questions/5404277/porting-clock-gettime-to-windows

LARGE_INTEGER getFILETIMEoffset()
{
    SYSTEMTIME s;
    FILETIME f;
    LARGE_INTEGER t;

    s.wYear = 1970;
    s.wMonth = 1;
    s.wDay = 1;
    s.wHour = 0;
    s.wMinute = 0;
    s.wSecond = 0;
    s.wMilliseconds = 0;
    SystemTimeToFileTime(&s, &f);
    t.QuadPart = f.dwHighDateTime;
    t.QuadPart <<= 32;
    t.QuadPart |= f.dwLowDateTime;
    return (t);
}

// time.h @ linux
int clock_gettime(int X, struct timeval *tv)
{
    LARGE_INTEGER           t;
    FILETIME            f;
    double                  microseconds;
    static LARGE_INTEGER    offset;
    static double           frequencyToMicroseconds;
    static int              initialized = 0;
    static BOOL             usePerformanceCounter = 0;

    if (!initialized) {
        LARGE_INTEGER performanceFrequency;
        initialized = 1;
        usePerformanceCounter = QueryPerformanceFrequency(&performanceFrequency);
        if (usePerformanceCounter) {
            QueryPerformanceCounter(&offset);
            frequencyToMicroseconds = (double)performanceFrequency.QuadPart / 1000000.;
        }
        else {
            offset = getFILETIMEoffset();
            frequencyToMicroseconds = 10.;
        }
    }
    if (usePerformanceCounter) QueryPerformanceCounter(&t);
    else {
        GetSystemTimeAsFileTime(&f);
        t.QuadPart = f.dwHighDateTime;
        t.QuadPart <<= 32;
        t.QuadPart |= f.dwLowDateTime;
    }

    t.QuadPart -= offset.QuadPart;
    microseconds = (double)t.QuadPart / frequencyToMicroseconds;
    t.QuadPart = microseconds;
    tv->tv_sec = t.QuadPart / 1000000;
    tv->tv_usec = t.QuadPart % 1000000;
    return (0);
}

// http://programmer-toy-box.sblo.jp/article/8848902.html
#define EPOCHFILETIME (116444736000000000i64)

int gettimeofday(struct timeval *tv, struct timezone *tz)
{
    FILETIME        tagFileTime;
    LARGE_INTEGER   largeInt;
    __int64         val64;
    static int      tzflag;

    if (tv)
    {
        GetSystemTimeAsFileTime(&tagFileTime);

        largeInt.LowPart = tagFileTime.dwLowDateTime;
        largeInt.HighPart = tagFileTime.dwHighDateTime;
        val64 = largeInt.QuadPart;
        val64 = val64 - EPOCHFILETIME;
        val64 = val64 / 10;
        tv->tv_sec = (long)(val64 / 1000000);
        tv->tv_usec = (long)(val64 % 1000000);
    }

    if (tz)
    {
        if (!tzflag)
        {
            _tzset();
            tzflag++;
        }

        //tz->tz_minuteswest = _timezone / 60;
        //tz->tz_dsttime = _daylight;

        long _Timezone = 0;
        _get_timezone(&_Timezone);
        tz->tz_minuteswest = _Timezone / 60;

        int _Daylight = 0;
        _get_daylight(&_Daylight);
        tz->tz_dsttime = _Daylight;
    }

    return 0;
}
