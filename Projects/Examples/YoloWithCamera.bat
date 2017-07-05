REM Refer to https://pjreddie.com/darknet/yolo/
REM Please download yolo.weights to this folder from https://pjreddie.com/media/files/yolo.weights

REM copy "..\bin\x64_MSVC2015.Release\darknet.exe" .

cd "..\darknet"
"..\Examples\darknet.exe" detector demo "cfg/coco.data" "cfg/yolo.cfg" "..\Examples\yolo.weights"
