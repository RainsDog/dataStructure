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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/work/ayu/vscode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/work/ayu/vscode/build

# Include any dependencies generated for this target.
include list/doubleLinkList/CMakeFiles/shared_linklist.dir/depend.make

# Include the progress variables for this target.
include list/doubleLinkList/CMakeFiles/shared_linklist.dir/progress.make

# Include the compile flags for this target's objects.
include list/doubleLinkList/CMakeFiles/shared_linklist.dir/flags.make

list/doubleLinkList/CMakeFiles/shared_linklist.dir/linklist.cpp.o: list/doubleLinkList/CMakeFiles/shared_linklist.dir/flags.make
list/doubleLinkList/CMakeFiles/shared_linklist.dir/linklist.cpp.o: ../list/doubleLinkList/linklist.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/work/ayu/vscode/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object list/doubleLinkList/CMakeFiles/shared_linklist.dir/linklist.cpp.o"
	cd /home/work/ayu/vscode/build/list/doubleLinkList && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/shared_linklist.dir/linklist.cpp.o -c /home/work/ayu/vscode/list/doubleLinkList/linklist.cpp

list/doubleLinkList/CMakeFiles/shared_linklist.dir/linklist.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shared_linklist.dir/linklist.cpp.i"
	cd /home/work/ayu/vscode/build/list/doubleLinkList && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/work/ayu/vscode/list/doubleLinkList/linklist.cpp > CMakeFiles/shared_linklist.dir/linklist.cpp.i

list/doubleLinkList/CMakeFiles/shared_linklist.dir/linklist.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shared_linklist.dir/linklist.cpp.s"
	cd /home/work/ayu/vscode/build/list/doubleLinkList && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/work/ayu/vscode/list/doubleLinkList/linklist.cpp -o CMakeFiles/shared_linklist.dir/linklist.cpp.s

list/doubleLinkList/CMakeFiles/shared_linklist.dir/linklist.cpp.o.requires:
.PHONY : list/doubleLinkList/CMakeFiles/shared_linklist.dir/linklist.cpp.o.requires

list/doubleLinkList/CMakeFiles/shared_linklist.dir/linklist.cpp.o.provides: list/doubleLinkList/CMakeFiles/shared_linklist.dir/linklist.cpp.o.requires
	$(MAKE) -f list/doubleLinkList/CMakeFiles/shared_linklist.dir/build.make list/doubleLinkList/CMakeFiles/shared_linklist.dir/linklist.cpp.o.provides.build
.PHONY : list/doubleLinkList/CMakeFiles/shared_linklist.dir/linklist.cpp.o.provides

list/doubleLinkList/CMakeFiles/shared_linklist.dir/linklist.cpp.o.provides.build: list/doubleLinkList/CMakeFiles/shared_linklist.dir/linklist.cpp.o

# Object files for target shared_linklist
shared_linklist_OBJECTS = \
"CMakeFiles/shared_linklist.dir/linklist.cpp.o"

# External object files for target shared_linklist
shared_linklist_EXTERNAL_OBJECTS =

lib/liblinklist.so.1.0: list/doubleLinkList/CMakeFiles/shared_linklist.dir/linklist.cpp.o
lib/liblinklist.so.1.0: list/doubleLinkList/CMakeFiles/shared_linklist.dir/build.make
lib/liblinklist.so.1.0: list/doubleLinkList/CMakeFiles/shared_linklist.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../../lib/liblinklist.so"
	cd /home/work/ayu/vscode/build/list/doubleLinkList && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shared_linklist.dir/link.txt --verbose=$(VERBOSE)
	cd /home/work/ayu/vscode/build/list/doubleLinkList && $(CMAKE_COMMAND) -E cmake_symlink_library ../../lib/liblinklist.so.1.0 ../../lib/liblinklist.so.1 ../../lib/liblinklist.so

lib/liblinklist.so.1: lib/liblinklist.so.1.0

lib/liblinklist.so: lib/liblinklist.so.1.0

# Rule to build all files generated by this target.
list/doubleLinkList/CMakeFiles/shared_linklist.dir/build: lib/liblinklist.so
.PHONY : list/doubleLinkList/CMakeFiles/shared_linklist.dir/build

list/doubleLinkList/CMakeFiles/shared_linklist.dir/requires: list/doubleLinkList/CMakeFiles/shared_linklist.dir/linklist.cpp.o.requires
.PHONY : list/doubleLinkList/CMakeFiles/shared_linklist.dir/requires

list/doubleLinkList/CMakeFiles/shared_linklist.dir/clean:
	cd /home/work/ayu/vscode/build/list/doubleLinkList && $(CMAKE_COMMAND) -P CMakeFiles/shared_linklist.dir/cmake_clean.cmake
.PHONY : list/doubleLinkList/CMakeFiles/shared_linklist.dir/clean

list/doubleLinkList/CMakeFiles/shared_linklist.dir/depend:
	cd /home/work/ayu/vscode/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/work/ayu/vscode /home/work/ayu/vscode/list/doubleLinkList /home/work/ayu/vscode/build /home/work/ayu/vscode/build/list/doubleLinkList /home/work/ayu/vscode/build/list/doubleLinkList/CMakeFiles/shared_linklist.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : list/doubleLinkList/CMakeFiles/shared_linklist.dir/depend

