# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zyt/ImageShow

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zyt/ImageShow/bulid

# Include any dependencies generated for this target.
include CMakeFiles/ImageShow.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ImageShow.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ImageShow.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ImageShow.dir/flags.make

CMakeFiles/ImageShow.dir/main.cpp.o: CMakeFiles/ImageShow.dir/flags.make
CMakeFiles/ImageShow.dir/main.cpp.o: ../main.cpp
CMakeFiles/ImageShow.dir/main.cpp.o: CMakeFiles/ImageShow.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zyt/ImageShow/bulid/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ImageShow.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ImageShow.dir/main.cpp.o -MF CMakeFiles/ImageShow.dir/main.cpp.o.d -o CMakeFiles/ImageShow.dir/main.cpp.o -c /home/zyt/ImageShow/main.cpp

CMakeFiles/ImageShow.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImageShow.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zyt/ImageShow/main.cpp > CMakeFiles/ImageShow.dir/main.cpp.i

CMakeFiles/ImageShow.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImageShow.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zyt/ImageShow/main.cpp -o CMakeFiles/ImageShow.dir/main.cpp.s

# Object files for target ImageShow
ImageShow_OBJECTS = \
"CMakeFiles/ImageShow.dir/main.cpp.o"

# External object files for target ImageShow
ImageShow_EXTERNAL_OBJECTS =

ImageShow: CMakeFiles/ImageShow.dir/main.cpp.o
ImageShow: CMakeFiles/ImageShow.dir/build.make
ImageShow: /usr/local/lib/libopencv_gapi.so.4.6.0
ImageShow: /usr/local/lib/libopencv_highgui.so.4.6.0
ImageShow: /usr/local/lib/libopencv_ml.so.4.6.0
ImageShow: /usr/local/lib/libopencv_objdetect.so.4.6.0
ImageShow: /usr/local/lib/libopencv_photo.so.4.6.0
ImageShow: /usr/local/lib/libopencv_stitching.so.4.6.0
ImageShow: /usr/local/lib/libopencv_video.so.4.6.0
ImageShow: /usr/local/lib/libopencv_videoio.so.4.6.0
ImageShow: /usr/local/lib/libopencv_imgcodecs.so.4.6.0
ImageShow: /usr/local/lib/libopencv_dnn.so.4.6.0
ImageShow: /usr/local/lib/libopencv_calib3d.so.4.6.0
ImageShow: /usr/local/lib/libopencv_features2d.so.4.6.0
ImageShow: /usr/local/lib/libopencv_flann.so.4.6.0
ImageShow: /usr/local/lib/libopencv_imgproc.so.4.6.0
ImageShow: /usr/local/lib/libopencv_core.so.4.6.0
ImageShow: CMakeFiles/ImageShow.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zyt/ImageShow/bulid/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ImageShow"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ImageShow.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ImageShow.dir/build: ImageShow
.PHONY : CMakeFiles/ImageShow.dir/build

CMakeFiles/ImageShow.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ImageShow.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ImageShow.dir/clean

CMakeFiles/ImageShow.dir/depend:
	cd /home/zyt/ImageShow/bulid && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zyt/ImageShow /home/zyt/ImageShow /home/zyt/ImageShow/bulid /home/zyt/ImageShow/bulid /home/zyt/ImageShow/bulid/CMakeFiles/ImageShow.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ImageShow.dir/depend

