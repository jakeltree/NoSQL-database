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
CMAKE_SOURCE_DIR = /home/jakeltree/Documents/School/task3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jakeltree/Documents/School/task3_build

# Include any dependencies generated for this target.
include task3_server/CMakeFiles/main_server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include task3_server/CMakeFiles/main_server.dir/compiler_depend.make

# Include the progress variables for this target.
include task3_server/CMakeFiles/main_server.dir/progress.make

# Include the compile flags for this target's objects.
include task3_server/CMakeFiles/main_server.dir/flags.make

task3_server/CMakeFiles/main_server.dir/src/main_server.cpp.o: task3_server/CMakeFiles/main_server.dir/flags.make
task3_server/CMakeFiles/main_server.dir/src/main_server.cpp.o: /home/jakeltree/Documents/School/task3/task3_server/src/main_server.cpp
task3_server/CMakeFiles/main_server.dir/src/main_server.cpp.o: task3_server/CMakeFiles/main_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jakeltree/Documents/School/task3_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object task3_server/CMakeFiles/main_server.dir/src/main_server.cpp.o"
	cd /home/jakeltree/Documents/School/task3_build/task3_server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT task3_server/CMakeFiles/main_server.dir/src/main_server.cpp.o -MF CMakeFiles/main_server.dir/src/main_server.cpp.o.d -o CMakeFiles/main_server.dir/src/main_server.cpp.o -c /home/jakeltree/Documents/School/task3/task3_server/src/main_server.cpp

task3_server/CMakeFiles/main_server.dir/src/main_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_server.dir/src/main_server.cpp.i"
	cd /home/jakeltree/Documents/School/task3_build/task3_server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakeltree/Documents/School/task3/task3_server/src/main_server.cpp > CMakeFiles/main_server.dir/src/main_server.cpp.i

task3_server/CMakeFiles/main_server.dir/src/main_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_server.dir/src/main_server.cpp.s"
	cd /home/jakeltree/Documents/School/task3_build/task3_server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakeltree/Documents/School/task3/task3_server/src/main_server.cpp -o CMakeFiles/main_server.dir/src/main_server.cpp.s

# Object files for target main_server
main_server_OBJECTS = \
"CMakeFiles/main_server.dir/src/main_server.cpp.o"

# External object files for target main_server
main_server_EXTERNAL_OBJECTS =

task3_server/main_server: task3_server/CMakeFiles/main_server.dir/src/main_server.cpp.o
task3_server/main_server: task3_server/CMakeFiles/main_server.dir/build.make
task3_server/main_server: task3_server/libtask_server.a
task3_server/main_server: task3_server/CMakeFiles/main_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jakeltree/Documents/School/task3_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable main_server"
	cd /home/jakeltree/Documents/School/task3_build/task3_server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
task3_server/CMakeFiles/main_server.dir/build: task3_server/main_server
.PHONY : task3_server/CMakeFiles/main_server.dir/build

task3_server/CMakeFiles/main_server.dir/clean:
	cd /home/jakeltree/Documents/School/task3_build/task3_server && $(CMAKE_COMMAND) -P CMakeFiles/main_server.dir/cmake_clean.cmake
.PHONY : task3_server/CMakeFiles/main_server.dir/clean

task3_server/CMakeFiles/main_server.dir/depend:
	cd /home/jakeltree/Documents/School/task3_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jakeltree/Documents/School/task3 /home/jakeltree/Documents/School/task3/task3_server /home/jakeltree/Documents/School/task3_build /home/jakeltree/Documents/School/task3_build/task3_server /home/jakeltree/Documents/School/task3_build/task3_server/CMakeFiles/main_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : task3_server/CMakeFiles/main_server.dir/depend

