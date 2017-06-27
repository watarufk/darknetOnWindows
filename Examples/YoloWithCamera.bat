REM https://pjreddie.com/darknet/yolo/

cd ..\darknet-win32
"..\Examples\darknet.exe" detector demo "cfg\coco.data" "cfg\yolo.cfg" "D:\Data\darknet\yolo.weights"
