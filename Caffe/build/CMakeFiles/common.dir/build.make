# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/taoran/桌面/caffe/Caffe

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/taoran/桌面/caffe/Caffe/build

# Include any dependencies generated for this target.
include CMakeFiles/common.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/common.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/common.dir/flags.make

CMakeFiles/common.dir/src/caffe/common.cpp.o: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/src/caffe/common.cpp.o: ../src/caffe/common.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/taoran/桌面/caffe/Caffe/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/common.dir/src/caffe/common.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/src/caffe/common.cpp.o -c /home/taoran/桌面/caffe/Caffe/src/caffe/common.cpp

CMakeFiles/common.dir/src/caffe/common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/src/caffe/common.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/taoran/桌面/caffe/Caffe/src/caffe/common.cpp > CMakeFiles/common.dir/src/caffe/common.cpp.i

CMakeFiles/common.dir/src/caffe/common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/src/caffe/common.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/taoran/桌面/caffe/Caffe/src/caffe/common.cpp -o CMakeFiles/common.dir/src/caffe/common.cpp.s

CMakeFiles/common.dir/src/caffe/common.cpp.o.requires:
.PHONY : CMakeFiles/common.dir/src/caffe/common.cpp.o.requires

CMakeFiles/common.dir/src/caffe/common.cpp.o.provides: CMakeFiles/common.dir/src/caffe/common.cpp.o.requires
	$(MAKE) -f CMakeFiles/common.dir/build.make CMakeFiles/common.dir/src/caffe/common.cpp.o.provides.build
.PHONY : CMakeFiles/common.dir/src/caffe/common.cpp.o.provides

CMakeFiles/common.dir/src/caffe/common.cpp.o.provides.build: CMakeFiles/common.dir/src/caffe/common.cpp.o

CMakeFiles/common.dir/src/caffe/common_thread.cpp.o: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/src/caffe/common_thread.cpp.o: ../src/caffe/common_thread.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/taoran/桌面/caffe/Caffe/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/common.dir/src/caffe/common_thread.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/src/caffe/common_thread.cpp.o -c /home/taoran/桌面/caffe/Caffe/src/caffe/common_thread.cpp

CMakeFiles/common.dir/src/caffe/common_thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/src/caffe/common_thread.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/taoran/桌面/caffe/Caffe/src/caffe/common_thread.cpp > CMakeFiles/common.dir/src/caffe/common_thread.cpp.i

CMakeFiles/common.dir/src/caffe/common_thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/src/caffe/common_thread.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/taoran/桌面/caffe/Caffe/src/caffe/common_thread.cpp -o CMakeFiles/common.dir/src/caffe/common_thread.cpp.s

CMakeFiles/common.dir/src/caffe/common_thread.cpp.o.requires:
.PHONY : CMakeFiles/common.dir/src/caffe/common_thread.cpp.o.requires

CMakeFiles/common.dir/src/caffe/common_thread.cpp.o.provides: CMakeFiles/common.dir/src/caffe/common_thread.cpp.o.requires
	$(MAKE) -f CMakeFiles/common.dir/build.make CMakeFiles/common.dir/src/caffe/common_thread.cpp.o.provides.build
.PHONY : CMakeFiles/common.dir/src/caffe/common_thread.cpp.o.provides

CMakeFiles/common.dir/src/caffe/common_thread.cpp.o.provides.build: CMakeFiles/common.dir/src/caffe/common_thread.cpp.o

CMakeFiles/common.dir/src/caffe/internal_thread.cpp.o: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/src/caffe/internal_thread.cpp.o: ../src/caffe/internal_thread.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/taoran/桌面/caffe/Caffe/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/common.dir/src/caffe/internal_thread.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/src/caffe/internal_thread.cpp.o -c /home/taoran/桌面/caffe/Caffe/src/caffe/internal_thread.cpp

CMakeFiles/common.dir/src/caffe/internal_thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/src/caffe/internal_thread.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/taoran/桌面/caffe/Caffe/src/caffe/internal_thread.cpp > CMakeFiles/common.dir/src/caffe/internal_thread.cpp.i

CMakeFiles/common.dir/src/caffe/internal_thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/src/caffe/internal_thread.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/taoran/桌面/caffe/Caffe/src/caffe/internal_thread.cpp -o CMakeFiles/common.dir/src/caffe/internal_thread.cpp.s

CMakeFiles/common.dir/src/caffe/internal_thread.cpp.o.requires:
.PHONY : CMakeFiles/common.dir/src/caffe/internal_thread.cpp.o.requires

CMakeFiles/common.dir/src/caffe/internal_thread.cpp.o.provides: CMakeFiles/common.dir/src/caffe/internal_thread.cpp.o.requires
	$(MAKE) -f CMakeFiles/common.dir/build.make CMakeFiles/common.dir/src/caffe/internal_thread.cpp.o.provides.build
.PHONY : CMakeFiles/common.dir/src/caffe/internal_thread.cpp.o.provides

CMakeFiles/common.dir/src/caffe/internal_thread.cpp.o.provides.build: CMakeFiles/common.dir/src/caffe/internal_thread.cpp.o

CMakeFiles/common.dir/_common.cpp.o: CMakeFiles/common.dir/flags.make
CMakeFiles/common.dir/_common.cpp.o: ../_common.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/taoran/桌面/caffe/Caffe/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/common.dir/_common.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/_common.cpp.o -c /home/taoran/桌面/caffe/Caffe/_common.cpp

CMakeFiles/common.dir/_common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/_common.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/taoran/桌面/caffe/Caffe/_common.cpp > CMakeFiles/common.dir/_common.cpp.i

CMakeFiles/common.dir/_common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/_common.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/taoran/桌面/caffe/Caffe/_common.cpp -o CMakeFiles/common.dir/_common.cpp.s

CMakeFiles/common.dir/_common.cpp.o.requires:
.PHONY : CMakeFiles/common.dir/_common.cpp.o.requires

CMakeFiles/common.dir/_common.cpp.o.provides: CMakeFiles/common.dir/_common.cpp.o.requires
	$(MAKE) -f CMakeFiles/common.dir/build.make CMakeFiles/common.dir/_common.cpp.o.provides.build
.PHONY : CMakeFiles/common.dir/_common.cpp.o.provides

CMakeFiles/common.dir/_common.cpp.o.provides.build: CMakeFiles/common.dir/_common.cpp.o

# Object files for target common
common_OBJECTS = \
"CMakeFiles/common.dir/src/caffe/common.cpp.o" \
"CMakeFiles/common.dir/src/caffe/common_thread.cpp.o" \
"CMakeFiles/common.dir/src/caffe/internal_thread.cpp.o" \
"CMakeFiles/common.dir/_common.cpp.o"

# External object files for target common
common_EXTERNAL_OBJECTS =

_common.so: CMakeFiles/common.dir/src/caffe/common.cpp.o
_common.so: CMakeFiles/common.dir/src/caffe/common_thread.cpp.o
_common.so: CMakeFiles/common.dir/src/caffe/internal_thread.cpp.o
_common.so: CMakeFiles/common.dir/_common.cpp.o
_common.so: CMakeFiles/common.dir/build.make
_common.so: /usr/lib/x86_64-linux-gnu/libboost_system.so
_common.so: /usr/lib/x86_64-linux-gnu/libboost_thread.so
_common.so: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
_common.so: /usr/lib/x86_64-linux-gnu/libpthread.so
_common.so: /usr/lib/x86_64-linux-gnu/libglog.so
_common.so: /usr/lib/x86_64-linux-gnu/libgflags.so
_common.so: /usr/lib/x86_64-linux-gnu/libhdf5_hl.so
_common.so: /usr/lib/x86_64-linux-gnu/libhdf5.so
_common.so: /usr/lib/x86_64-linux-gnu/libhdf5_hl.so
_common.so: /usr/lib/x86_64-linux-gnu/libhdf5.so
_common.so: /usr/local/cuda/lib64/libcudart.so
_common.so: /usr/local/cuda/lib64/libcurand.so
_common.so: /usr/local/cuda/lib64/libcublas.so
_common.so: /usr/lib/liblapack.so
_common.so: /usr/lib/libcblas.so
_common.so: /usr/lib/libatlas.so
_common.so: CMakeFiles/common.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library _common.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/common.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/common.dir/build: _common.so
.PHONY : CMakeFiles/common.dir/build

CMakeFiles/common.dir/requires: CMakeFiles/common.dir/src/caffe/common.cpp.o.requires
CMakeFiles/common.dir/requires: CMakeFiles/common.dir/src/caffe/common_thread.cpp.o.requires
CMakeFiles/common.dir/requires: CMakeFiles/common.dir/src/caffe/internal_thread.cpp.o.requires
CMakeFiles/common.dir/requires: CMakeFiles/common.dir/_common.cpp.o.requires
.PHONY : CMakeFiles/common.dir/requires

CMakeFiles/common.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/common.dir/cmake_clean.cmake
.PHONY : CMakeFiles/common.dir/clean

CMakeFiles/common.dir/depend:
	cd /home/taoran/桌面/caffe/Caffe/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/taoran/桌面/caffe/Caffe /home/taoran/桌面/caffe/Caffe /home/taoran/桌面/caffe/Caffe/build /home/taoran/桌面/caffe/Caffe/build /home/taoran/桌面/caffe/Caffe/build/CMakeFiles/common.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/common.dir/depend

