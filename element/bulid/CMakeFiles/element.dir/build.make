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
CMAKE_SOURCE_DIR = /home/zyt/LearnOpenCV/element

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zyt/LearnOpenCV/element/bulid

# Include any dependencies generated for this target.
include CMakeFiles/element.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/element.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/element.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/element.dir/flags.make

CMakeFiles/element.dir/main.cpp.o: CMakeFiles/element.dir/flags.make
CMakeFiles/element.dir/main.cpp.o: ../main.cpp
CMakeFiles/element.dir/main.cpp.o: CMakeFiles/element.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zyt/LearnOpenCV/element/bulid/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/element.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/element.dir/main.cpp.o -MF CMakeFiles/element.dir/main.cpp.o.d -o CMakeFiles/element.dir/main.cpp.o -c /home/zyt/LearnOpenCV/element/main.cpp

CMakeFiles/element.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/element.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zyt/LearnOpenCV/element/main.cpp > CMakeFiles/element.dir/main.cpp.i

CMakeFiles/element.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/element.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zyt/LearnOpenCV/element/main.cpp -o CMakeFiles/element.dir/main.cpp.s

# Object files for target element
element_OBJECTS = \
"CMakeFiles/element.dir/main.cpp.o"

# External object files for target element
element_EXTERNAL_OBJECTS =

element: CMakeFiles/element.dir/main.cpp.o
element: CMakeFiles/element.dir/build.make
element: /usr/local/lib/libopencv_gapi.so.4.6.0
element: /usr/local/lib/libopencv_highgui.so.4.6.0
element: /usr/local/lib/libopencv_ml.so.4.6.0
element: /usr/local/lib/libopencv_objdetect.so.4.6.0
element: /usr/local/lib/libopencv_photo.so.4.6.0
element: /usr/local/lib/libopencv_stitching.so.4.6.0
element: /usr/local/lib/libopencv_video.so.4.6.0
element: /usr/local/lib/libopencv_videoio.so.4.6.0
element: /usr/local/lib/libopencv_imgcodecs.so.4.6.0
element: /usr/local/lib/libopencv_dnn.so.4.6.0
element: /usr/local/lib/libopencv_calib3d.so.4.6.0
element: /usr/local/lib/libopencv_features2d.so.4.6.0
element: /usr/local/lib/libopencv_flann.so.4.6.0
element: /usr/local/lib/libopencv_imgproc.so.4.6.0
element: /usr/local/lib/libopencv_core.so.4.6.0
element: CMakeFiles/element.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zyt/LearnOpenCV/element/bulid/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable element"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/element.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/element.dir/build: element
.PHONY : CMakeFiles/element.dir/build

CMakeFiles/element.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/element.dir/cmake_clean.cmake
.PHONY : CMakeFiles/element.dir/clean

CMakeFiles/element.dir/depend:
	cd /home/zyt/LearnOpenCV/element/bulid && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zyt/LearnOpenCV/element /home/zyt/LearnOpenCV/element /home/zyt/LearnOpenCV/element/bulid /home/zyt/LearnOpenCV/element/bulid /home/zyt/LearnOpenCV/element/bulid/CMakeFiles/element.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/element.dir/depend
