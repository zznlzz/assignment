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
CMAKE_SOURCE_DIR = /home/zyt/LearnOpenCV/beauty2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zyt/LearnOpenCV/beauty2/bulid

# Include any dependencies generated for this target.
include CMakeFiles/beauty.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/beauty.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/beauty.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/beauty.dir/flags.make

CMakeFiles/beauty.dir/main.cpp.o: CMakeFiles/beauty.dir/flags.make
CMakeFiles/beauty.dir/main.cpp.o: ../main.cpp
CMakeFiles/beauty.dir/main.cpp.o: CMakeFiles/beauty.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zyt/LearnOpenCV/beauty2/bulid/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/beauty.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/beauty.dir/main.cpp.o -MF CMakeFiles/beauty.dir/main.cpp.o.d -o CMakeFiles/beauty.dir/main.cpp.o -c /home/zyt/LearnOpenCV/beauty2/main.cpp

CMakeFiles/beauty.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/beauty.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zyt/LearnOpenCV/beauty2/main.cpp > CMakeFiles/beauty.dir/main.cpp.i

CMakeFiles/beauty.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/beauty.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zyt/LearnOpenCV/beauty2/main.cpp -o CMakeFiles/beauty.dir/main.cpp.s

# Object files for target beauty
beauty_OBJECTS = \
"CMakeFiles/beauty.dir/main.cpp.o"

# External object files for target beauty
beauty_EXTERNAL_OBJECTS =

beauty: CMakeFiles/beauty.dir/main.cpp.o
beauty: CMakeFiles/beauty.dir/build.make
beauty: /usr/local/lib/libopencv_gapi.so.4.6.0
beauty: /usr/local/lib/libopencv_highgui.so.4.6.0
beauty: /usr/local/lib/libopencv_ml.so.4.6.0
beauty: /usr/local/lib/libopencv_objdetect.so.4.6.0
beauty: /usr/local/lib/libopencv_photo.so.4.6.0
beauty: /usr/local/lib/libopencv_stitching.so.4.6.0
beauty: /usr/local/lib/libopencv_video.so.4.6.0
beauty: /usr/local/lib/libopencv_videoio.so.4.6.0
beauty: /usr/local/lib/libopencv_imgcodecs.so.4.6.0
beauty: /usr/local/lib/libopencv_dnn.so.4.6.0
beauty: /usr/local/lib/libopencv_calib3d.so.4.6.0
beauty: /usr/local/lib/libopencv_features2d.so.4.6.0
beauty: /usr/local/lib/libopencv_flann.so.4.6.0
beauty: /usr/local/lib/libopencv_imgproc.so.4.6.0
beauty: /usr/local/lib/libopencv_core.so.4.6.0
beauty: CMakeFiles/beauty.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zyt/LearnOpenCV/beauty2/bulid/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable beauty"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/beauty.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/beauty.dir/build: beauty
.PHONY : CMakeFiles/beauty.dir/build

CMakeFiles/beauty.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/beauty.dir/cmake_clean.cmake
.PHONY : CMakeFiles/beauty.dir/clean

CMakeFiles/beauty.dir/depend:
	cd /home/zyt/LearnOpenCV/beauty2/bulid && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zyt/LearnOpenCV/beauty2 /home/zyt/LearnOpenCV/beauty2 /home/zyt/LearnOpenCV/beauty2/bulid /home/zyt/LearnOpenCV/beauty2/bulid /home/zyt/LearnOpenCV/beauty2/bulid/CMakeFiles/beauty.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/beauty.dir/depend

