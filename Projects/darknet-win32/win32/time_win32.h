#pragma once

#include <Windows.h>
#include <time.h>

struct timezone
{
    int tz_minuteswest;
    int tz_dsttime;
};

extern int gettimeofday(struct timeval *tv, struct timezone *tz);

// http://www.fireproject.jp/feature/c-language/basic-library/high-accuracy-time.html
#define timeradd(a, b, result) \
  do { \
    (result)->tv_sec = (a)->tv_sec + (b)->tv_sec; \
    (result)->tv_usec = (a)->tv_usec + (b)->tv_usec; \
    if ((result)->tv_usec >= 1000000) \
      { \
        ++(result)->tv_sec; \
        (result)->tv_usec -= 1000000; \
      } \
  } while (0)
#define timersub(a, b, result) \
  do { \
    (result)->tv_sec = (a)->tv_sec - (b)->tv_sec; \
    (result)->tv_usec = (a)->tv_usec - (b)->tv_usec; \
    if ((result)->tv_usec < 0) { \
      --(result)->tv_sec; \
      (result)->tv_usec += 1000000; \
    } \
  } while (0)
