# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Projects\FinalCLang

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Projects\FinalCLang\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FinalCLang.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FinalCLang.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FinalCLang.dir/flags.make

CMakeFiles/FinalCLang.dir/main.c.obj: CMakeFiles/FinalCLang.dir/flags.make
CMakeFiles/FinalCLang.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\FinalCLang\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/FinalCLang.dir/main.c.obj"
	C:\wbs\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\FinalCLang.dir\main.c.obj   -c D:\Projects\FinalCLang\main.c

CMakeFiles/FinalCLang.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FinalCLang.dir/main.c.i"
	C:\wbs\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Projects\FinalCLang\main.c > CMakeFiles\FinalCLang.dir\main.c.i

CMakeFiles/FinalCLang.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FinalCLang.dir/main.c.s"
	C:\wbs\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Projects\FinalCLang\main.c -o CMakeFiles\FinalCLang.dir\main.c.s

# Object files for target FinalCLang
FinalCLang_OBJECTS = \
"CMakeFiles/FinalCLang.dir/main.c.obj"

# External object files for target FinalCLang
FinalCLang_EXTERNAL_OBJECTS =

FinalCLang.exe: CMakeFiles/FinalCLang.dir/main.c.obj
FinalCLang.exe: CMakeFiles/FinalCLang.dir/build.make
FinalCLang.exe: CMakeFiles/FinalCLang.dir/linklibs.rsp
FinalCLang.exe: CMakeFiles/FinalCLang.dir/objects1.rsp
FinalCLang.exe: CMakeFiles/FinalCLang.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Projects\FinalCLang\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable FinalCLang.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\FinalCLang.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FinalCLang.dir/build: FinalCLang.exe

.PHONY : CMakeFiles/FinalCLang.dir/build

CMakeFiles/FinalCLang.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\FinalCLang.dir\cmake_clean.cmake
.PHONY : CMakeFiles/FinalCLang.dir/clean

CMakeFiles/FinalCLang.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Projects\FinalCLang D:\Projects\FinalCLang D:\Projects\FinalCLang\cmake-build-debug D:\Projects\FinalCLang\cmake-build-debug D:\Projects\FinalCLang\cmake-build-debug\CMakeFiles\FinalCLang.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FinalCLang.dir/depend
