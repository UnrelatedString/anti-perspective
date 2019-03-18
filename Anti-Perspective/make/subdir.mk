################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main.cpp \
../src/repeated_detection_old.cpp \
../src/select.cpp \
../src/viewer.cpp 

OBJS += \
./src/main.o \
./src/repeated_detection_old.o \
./src/select.o \
./src/viewer.o 

CPP_DEPS += \
./src/main.d \
./src/repeated_detection_old.d \
./src/select.d \
./src/viewer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -I/usr/local/include/opencv/modules/calib3d/include -I/usr/local/include/opencv/modules/cudaarithm/include -I/usr/local/include/opencv/modules/cudabgsegm/include -I/usr/local/include/opencv/modules/cudacodec/include -I/usr/local/include/opencv/modules/cudafeatures2d/include -I/usr/local/include/opencv/modules/cudafilters/include -I/usr/local/include/opencv/modules/cudaimgproc/include -I/usr/local/include/opencv/modules/cudalegacy/include -I/usr/local/include/opencv/modules/cudaobjdetect/include -I/usr/local/include/opencv/modules/cudaoptflow/include -I/usr/local/include/opencv/modules/cudastereo/include -I/usr/local/include/opencv/modules/cudawarping/include -I/usr/local/include/opencv/modules/cudev/include -I/usr/local/include/opencv/modules/dnn/include -I/usr/local/include/opencv/modules/features2d/include -I/usr/local/include/opencv/modules/flann/include -I/usr/local/include/opencv/modules/highgui/include -I/usr/local/include/opencv/modules/imgcodecs/include -I/usr/local/include/opencv/modules/imgproc/include -I/usr/local/include/opencv/modules/ml/include -I/usr/local/include/opencv/modules/objdetect/include -I/usr/local/include/opencv/modules/photo/include -I/usr/local/include/opencv/modules/shape/include -I/usr/local/include/opencv/modules/stitching/include -I/usr/local/include/opencv/modules/superres/include -I/usr/local/include/opencv/modules/ts/include -I/usr/local/include/opencv/modules/video/include -I/usr/local/include/opencv/modules/videoio/include -I/usr/local/include/opencv/modules/videostab/include -I/usr/local/include/opencv/modules/viz/include -I/usr/local/include/opencv/modules/world/include -I/usr/local/include/opencv_contrib/modules/aruco/include -I/usr/local/include/opencv_contrib/modules/bgsegm/include -I/usr/local/include/opencv_contrib/modules/bioinspired/include -I/usr/local/include/opencv_contrib/modules/ccalib/include -I/usr/local/include/opencv_contrib/modules/cnn_3dobj/include -I/usr/local/include/opencv_contrib/modules/cvv/include -I/usr/local/include/opencv_contrib/modules/datasets/include -I/usr/local/include/opencv_contrib/modules/dnn_objdetect/include -I/usr/local/include/opencv_contrib/modules/dnns_easily_fooled/include -I/usr/local/include/opencv_contrib/modules/dpm/include -I/usr/local/include/opencv_contrib/modules/face/include -I/usr/local/include/opencv_contrib/modules/freetype/include -I/usr/local/include/opencv_contrib/modules/fuzzy/include -I/usr/local/include/opencv_contrib/modules/hdf/include -I/usr/local/include/opencv_contrib/modules/hfs/include -I/usr/local/include/opencv_contrib/modules/img_hash/include -I/usr/local/include/opencv_contrib/modules/line_descriptor/include -I/usr/local/include/opencv_contrib/modules/matlab/include -I/usr/local/include/opencv_contrib/modules/optflow/include -I/usr/local/include/opencv_contrib/modules/ovis/include -I/usr/local/include/opencv_contrib/modules/phase_unwrapping/include -I/usr/local/include/opencv_contrib/modules/plot/include -I/usr/local/include/opencv_contrib/modules/reg/include -I/usr/local/include/opencv_contrib/modules/rgbd/include -I/usr/local/include/opencv_contrib/modules/saliency/include -I/usr/local/include/opencv_contrib/modules/sfm/include -I/usr/local/include/opencv_contrib/modules/stereo/include -I/usr/local/include/opencv_contrib/modules/structured_light/include -I/usr/local/include/opencv_contrib/modules/surface_matching/include -I/usr/local/include/opencv_contrib/modules/text/include -I/usr/local/include/opencv_contrib/modules/tracking/include -I/usr/local/include/opencv_contrib/modules/xfeatures2d/include -I/usr/local/include/opencv_contrib/modules/ximgproc/include -I/usr/local/include/opencv_contrib/modules/xobjdetect/include -I/usr/local/include/opencv_contrib/modules/xphoto/include -I/usr/local/include/opencv/modules/core/include -I/usr/local/include/opencv/build -I/usr/local/include/opencv/include -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


