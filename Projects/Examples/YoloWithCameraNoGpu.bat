REM Refer to https://pjreddie.com/darknet/yolo/
REM Please download yolo.weights to this folder from https://pjreddie.com/media/files/yolo.weights

copy "..\bin\x64_MSVC2015.Release\darknet_nogpu.exe" .

REM GPU version darknet.exe with "-nogpu" option did not work correctly.
cd "..\darknet"
"..\Examples\darknet_nogpu.exe" detector demo -nogpu "cfg/coco.data" "cfg/yolo.cfg" "..\Examples\yolo.weights"
