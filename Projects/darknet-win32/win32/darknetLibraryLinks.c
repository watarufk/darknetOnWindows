#include "darknet.h"

// pthread.h
// When building the library, you should define PTW32_BUILD so that
// the variables/functions are exported correctly. When using the library,
// do NOT define PTW32_BUILD, and then the variables/functions will
// be imported correctly.

//#if !defined(PTW32_STATIC_LIB)
//#  if defined(PTW32_BUILD)
//#    define PTW32_DLLPORT __declspec (dllexport)
//#  else
//#    define PTW32_DLLPORT __declspec (dllimport)
//#  endif
//#else
//#  define PTW32_DLLPORT
//#endif
// So, I have to define PTW32_STATIC_LIB in the project settings.
//#define PTW32_STATIC_LIB
#pragma comment(lib, "lib/x64/pthread_dll.lib")

// And about sympol constants GPU, CUDNN, OPENCV, define them in project properties.
//#define GPU       1
//#define CUDNN     1
//#define OPENCV    1

#ifdef OPENCV
#ifdef _DEBUG
#define OPENCV_LIB_EXT "d.lib"
#else
#define OPENCV_LIB_EXT ".lib"
#endif
#pragma comment(lib, "opencv_core"      CVAUX_STR(CV_VERSION_EPOCH) CVAUX_STR(CV_VERSION_MAJOR) CVAUX_STR(CV_VERSION_MINOR) OPENCV_LIB_EXT)
#pragma comment(lib, "opencv_highgui"   CVAUX_STR(CV_VERSION_EPOCH) CVAUX_STR(CV_VERSION_MAJOR) CVAUX_STR(CV_VERSION_MINOR) OPENCV_LIB_EXT)
#pragma comment(lib, "opencv_imgproc"   CVAUX_STR(CV_VERSION_EPOCH) CVAUX_STR(CV_VERSION_MAJOR) CVAUX_STR(CV_VERSION_MINOR) OPENCV_LIB_EXT)
#pragma comment(lib, "opencv_video"     CVAUX_STR(CV_VERSION_EPOCH) CVAUX_STR(CV_VERSION_MAJOR) CVAUX_STR(CV_VERSION_MINOR) OPENCV_LIB_EXT)
#if CV_MAJOR_VERSION == 3
#error "It does not seem to work on Windows with OpenCV 3.x for now."
#pragma comment(lib, "opencv_videoio"   CVAUX_STR(CV_VERSION_EPOCH) CVAUX_STR(CV_VERSION_MAJOR) CVAUX_STR(CV_VERSION_MINOR) OPENCV_LIB_EXT)
#endif
#endif

#ifdef GPU
#pragma comment(lib, "cudart.lib")
#pragma comment(lib, "cublas.lib")
#pragma comment(lib, "curand.lib")
#ifdef CUDNN
#pragma comment(lib, "cudnn.lib")
#endif
#endif

#if _DEBUG
#pragma comment(lib, "darknet_lib/bin/x64/Debug/darknet_lib.lib")
#else
#pragma comment(lib, "darknet_lib/bin/x64/Release/darknet_lib.lib")
#endif
