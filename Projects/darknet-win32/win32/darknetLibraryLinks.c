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
#if 1
#if _DEBUG
#pragma comment(lib, "bin/x64_MSVC2015.Debug/pthread_dll.lib")
#else
#pragma comment(lib, "bin/x64_MSVC2015.Release/pthread_dll.lib")
#endif
#else
#if _DEBUG
#pragma comment(lib, "bin/x64_MSVC2015.Debug/pthread_lib.lib")
#else
#pragma comment(lib, "bin/x64_MSVC2015.Release/pthread_lib.lib")
#endif
#endif


// And about sympol constants GPU, CUDNN, OPENCV, define them in project properties.
//#define GPU       1
//#define CUDNN     1
//#define OPENCV    1

#ifdef OPENCV
#ifdef _DEBUG
//#define OPENCV_LIB_EXT CVAUX_STR(CV_VERSION_EPOCH) CVAUX_STR(CV_VERSION_MAJOR) CVAUX_STR(CV_VERSION_MINOR) "d.lib"
#define OPENCV_LIB_EXT CVAUX_STR(CV_VERSION_EPOCH) CVAUX_STR(CV_VERSION_MAJOR) CVAUX_STR(CV_VERSION_MINOR) ".lib"
#else
#define OPENCV_LIB_EXT CVAUX_STR(CV_VERSION_EPOCH) CVAUX_STR(CV_VERSION_MAJOR) CVAUX_STR(CV_VERSION_MINOR) ".lib"
#endif

#define OPENCV_LIB_X64_FOLDER_PATH "../OpenCVBuiltFilesForWindows/opencv_x64/install/x64/vc14/lib/"
#pragma comment(lib, OPENCV_LIB_X64_FOLDER_PATH "opencv_core"      OPENCV_LIB_EXT)
#pragma comment(lib, OPENCV_LIB_X64_FOLDER_PATH "opencv_highgui"   OPENCV_LIB_EXT)
#pragma comment(lib, OPENCV_LIB_X64_FOLDER_PATH "opencv_imgproc"   OPENCV_LIB_EXT)
#pragma comment(lib, OPENCV_LIB_X64_FOLDER_PATH "opencv_video"     OPENCV_LIB_EXT)
#if CV_MAJOR_VERSION == 3
#error "It does not seem to work on Windows with OpenCV 3.x for now."
#pragma comment(lib, OPENCV_LIB_X64_FOLDER_PATH "opencv_videoio"   OPENCV_LIB_EXT)
#endif

#undef OPENCV_LIB_X64_FOLDER_PATH
#undef OPENCV_LIB_EXT
#endif

#ifdef GPU
#define CUDA_v8_LIB_X64_FOLDER_PATH "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v8.0/lib/x64/"
#pragma comment(lib, CUDA_v8_LIB_X64_FOLDER_PATH "cudart.lib")
#pragma comment(lib, CUDA_v8_LIB_X64_FOLDER_PATH "cublas.lib")
#pragma comment(lib, CUDA_v8_LIB_X64_FOLDER_PATH "curand.lib")
#ifdef CUDNN
#pragma comment(lib, CUDA_v8_LIB_X64_FOLDER_PATH "cudnn.lib")
#endif

#undef CUDA_v8_LIB_X64_FOLDER_PATH
#endif

#ifdef GPU
#if _DEBUG
#pragma comment(lib, "bin/x64_MSVC2015.Debug/darknet_lib.lib")
#else
#pragma comment(lib, "bin/x64_MSVC2015.Release/darknet_lib.lib")
#endif

#else

#ifdef INTEL_MKL
// NOTE: SGEMM needs only this lib file, but setting "Use Intel MKL" to "Parallel" in Project settings is useful.
//#pragma comment(lib, "C:/Program Files (x86)/IntelSWTools/compilers_and_libraries_2017.2.187/windows/mkl/lib/intel64_win/mkl_rt.lib")
#endif

#if _DEBUG
#pragma comment(lib, "bin/x64_MSVC2015.Debug/darknet_lib_nogpu.lib")
#else
#pragma comment(lib, "bin/x64_MSVC2015.Release/darknet_lib_nogpu.lib")
#endif

#endif
