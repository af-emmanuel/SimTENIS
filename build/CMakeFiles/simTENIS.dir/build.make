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
CMAKE_SOURCE_DIR = /home/emmanuel/myworkdir/simTENIS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/emmanuel/myworkdir/simTENIS/build

# Utility rule file for simTENIS.

# Include any custom commands dependencies for this target.
include CMakeFiles/simTENIS.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/simTENIS.dir/progress.make

CMakeFiles/simTENIS: exeTENIS

simTENIS: CMakeFiles/simTENIS
simTENIS: CMakeFiles/simTENIS.dir/build.make
.PHONY : simTENIS

# Rule to build all files generated by this target.
CMakeFiles/simTENIS.dir/build: simTENIS
.PHONY : CMakeFiles/simTENIS.dir/build

CMakeFiles/simTENIS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simTENIS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simTENIS.dir/clean

CMakeFiles/simTENIS.dir/depend:
	cd /home/emmanuel/myworkdir/simTENIS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emmanuel/myworkdir/simTENIS /home/emmanuel/myworkdir/simTENIS /home/emmanuel/myworkdir/simTENIS/build /home/emmanuel/myworkdir/simTENIS/build /home/emmanuel/myworkdir/simTENIS/build/CMakeFiles/simTENIS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/simTENIS.dir/depend

