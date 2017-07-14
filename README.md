# darknetOnWindows

About darknet and YOLO, please refer to  
<https://pjreddie.com/darknet/>  
<https://github.com/pjreddie/darknet>  

This repository has some modification and additional files (pthread, unistd.h, time.h and so on) of darknet, to run it on Windows.  
To try YOLO with a web-cam, please download "yolo.weights" from <https://pjreddie.com/media/files/yolo.weights> to Projects/Examples folder, and run Projects/Examples/YoloWithCamera.bat file.

## Requirement to build
* Windows 7 or above
* Visual Studio 2015
* CUDA Toolkit v8.0

## License
MIT License (<https://github.com/kishimoto-exvision/darknetOnWindows/blob/master/LICENSE>)  
(Currently I use it, but I'd like to use the same licenses as darknet.  But please be careful this uses pthread-win32 and it is LGPL-2.1.)

## Third Party Libraries
* darknet (YOLO LICENSE and so on) (<https://github.com/pjreddie/darknet/blob/master/LICENSE>)
* pthread-win32 (LGPL-2.1) (<https://github.com/GerHobbelt/pthread-win32>)
* OpenCV (3-clause BSD) (<https://github.com/opencv/opencv/blob/master/LICENSE>)
