# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /snap/clion/82/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/82/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/prathamesh/Desktop/College/Sem-2/DSU-MP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/prathamesh/Desktop/College/Sem-2/DSU-MP/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DSU_MP.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DSU_MP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DSU_MP.dir/flags.make

CMakeFiles/DSU_MP.dir/main.c.o: CMakeFiles/DSU_MP.dir/flags.make
CMakeFiles/DSU_MP.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/prathamesh/Desktop/College/Sem-2/DSU-MP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/DSU_MP.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/DSU_MP.dir/main.c.o   -c /home/prathamesh/Desktop/College/Sem-2/DSU-MP/main.c

CMakeFiles/DSU_MP.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DSU_MP.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/prathamesh/Desktop/College/Sem-2/DSU-MP/main.c > CMakeFiles/DSU_MP.dir/main.c.i

CMakeFiles/DSU_MP.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DSU_MP.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/prathamesh/Desktop/College/Sem-2/DSU-MP/main.c -o CMakeFiles/DSU_MP.dir/main.c.s

# Object files for target DSU_MP
DSU_MP_OBJECTS = \
"CMakeFiles/DSU_MP.dir/main.c.o"

# External object files for target DSU_MP
DSU_MP_EXTERNAL_OBJECTS =

DSU_MP: CMakeFiles/DSU_MP.dir/main.c.o
DSU_MP: CMakeFiles/DSU_MP.dir/build.make
DSU_MP: CMakeFiles/DSU_MP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/prathamesh/Desktop/College/Sem-2/DSU-MP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable DSU_MP"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DSU_MP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DSU_MP.dir/build: DSU_MP

.PHONY : CMakeFiles/DSU_MP.dir/build

CMakeFiles/DSU_MP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DSU_MP.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DSU_MP.dir/clean

CMakeFiles/DSU_MP.dir/depend:
	cd /home/prathamesh/Desktop/College/Sem-2/DSU-MP/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/prathamesh/Desktop/College/Sem-2/DSU-MP /home/prathamesh/Desktop/College/Sem-2/DSU-MP /home/prathamesh/Desktop/College/Sem-2/DSU-MP/cmake-build-debug /home/prathamesh/Desktop/College/Sem-2/DSU-MP/cmake-build-debug /home/prathamesh/Desktop/College/Sem-2/DSU-MP/cmake-build-debug/CMakeFiles/DSU_MP.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DSU_MP.dir/depend
