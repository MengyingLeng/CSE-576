# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lengmengying/Desktop/学习/CSE576_cv/cse576_sp20_hw5-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lengmengying/Desktop/学习/CSE576_cv/cse576_sp20_hw5-master/build

# Include any dependencies generated for this target.
include CMakeFiles/make-panorama.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/make-panorama.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/make-panorama.dir/flags.make

CMakeFiles/make-panorama.dir/src/test/make-panorama.cpp.o: CMakeFiles/make-panorama.dir/flags.make
CMakeFiles/make-panorama.dir/src/test/make-panorama.cpp.o: ../src/test/make-panorama.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lengmengying/Desktop/学习/CSE576_cv/cse576_sp20_hw5-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/make-panorama.dir/src/test/make-panorama.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/make-panorama.dir/src/test/make-panorama.cpp.o -c /Users/lengmengying/Desktop/学习/CSE576_cv/cse576_sp20_hw5-master/src/test/make-panorama.cpp

CMakeFiles/make-panorama.dir/src/test/make-panorama.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/make-panorama.dir/src/test/make-panorama.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lengmengying/Desktop/学习/CSE576_cv/cse576_sp20_hw5-master/src/test/make-panorama.cpp > CMakeFiles/make-panorama.dir/src/test/make-panorama.cpp.i

CMakeFiles/make-panorama.dir/src/test/make-panorama.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/make-panorama.dir/src/test/make-panorama.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lengmengying/Desktop/学习/CSE576_cv/cse576_sp20_hw5-master/src/test/make-panorama.cpp -o CMakeFiles/make-panorama.dir/src/test/make-panorama.cpp.s

# Object files for target make-panorama
make__panorama_OBJECTS = \
"CMakeFiles/make-panorama.dir/src/test/make-panorama.cpp.o"

# External object files for target make-panorama
make__panorama_EXTERNAL_OBJECTS =

../make-panorama: CMakeFiles/make-panorama.dir/src/test/make-panorama.cpp.o
../make-panorama: CMakeFiles/make-panorama.dir/build.make
../make-panorama: libuwimg++.dylib
../make-panorama: CMakeFiles/make-panorama.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lengmengying/Desktop/学习/CSE576_cv/cse576_sp20_hw5-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../make-panorama"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/make-panorama.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/make-panorama.dir/build: ../make-panorama

.PHONY : CMakeFiles/make-panorama.dir/build

CMakeFiles/make-panorama.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/make-panorama.dir/cmake_clean.cmake
.PHONY : CMakeFiles/make-panorama.dir/clean

CMakeFiles/make-panorama.dir/depend:
	cd /Users/lengmengying/Desktop/学习/CSE576_cv/cse576_sp20_hw5-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lengmengying/Desktop/学习/CSE576_cv/cse576_sp20_hw5-master /Users/lengmengying/Desktop/学习/CSE576_cv/cse576_sp20_hw5-master /Users/lengmengying/Desktop/学习/CSE576_cv/cse576_sp20_hw5-master/build /Users/lengmengying/Desktop/学习/CSE576_cv/cse576_sp20_hw5-master/build /Users/lengmengying/Desktop/学习/CSE576_cv/cse576_sp20_hw5-master/build/CMakeFiles/make-panorama.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/make-panorama.dir/depend

