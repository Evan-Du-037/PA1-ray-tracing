# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/evan/Study/大二下/计算机图形学/PA1/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/evan/Study/大二下/计算机图形学/PA1/build

# Include any dependencies generated for this target.
include CMakeFiles/PA1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PA1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PA1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PA1.dir/flags.make

CMakeFiles/PA1.dir/codegen:
.PHONY : CMakeFiles/PA1.dir/codegen

CMakeFiles/PA1.dir/src/image.cpp.o: CMakeFiles/PA1.dir/flags.make
CMakeFiles/PA1.dir/src/image.cpp.o: /Users/evan/Study/大二下/计算机图形学/PA1/code/src/image.cpp
CMakeFiles/PA1.dir/src/image.cpp.o: CMakeFiles/PA1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/evan/Study/大二下/计算机图形学/PA1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PA1.dir/src/image.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PA1.dir/src/image.cpp.o -MF CMakeFiles/PA1.dir/src/image.cpp.o.d -o CMakeFiles/PA1.dir/src/image.cpp.o -c /Users/evan/Study/大二下/计算机图形学/PA1/code/src/image.cpp

CMakeFiles/PA1.dir/src/image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/PA1.dir/src/image.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evan/Study/大二下/计算机图形学/PA1/code/src/image.cpp > CMakeFiles/PA1.dir/src/image.cpp.i

CMakeFiles/PA1.dir/src/image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/PA1.dir/src/image.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evan/Study/大二下/计算机图形学/PA1/code/src/image.cpp -o CMakeFiles/PA1.dir/src/image.cpp.s

CMakeFiles/PA1.dir/src/main.cpp.o: CMakeFiles/PA1.dir/flags.make
CMakeFiles/PA1.dir/src/main.cpp.o: /Users/evan/Study/大二下/计算机图形学/PA1/code/src/main.cpp
CMakeFiles/PA1.dir/src/main.cpp.o: CMakeFiles/PA1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/evan/Study/大二下/计算机图形学/PA1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PA1.dir/src/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PA1.dir/src/main.cpp.o -MF CMakeFiles/PA1.dir/src/main.cpp.o.d -o CMakeFiles/PA1.dir/src/main.cpp.o -c /Users/evan/Study/大二下/计算机图形学/PA1/code/src/main.cpp

CMakeFiles/PA1.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/PA1.dir/src/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evan/Study/大二下/计算机图形学/PA1/code/src/main.cpp > CMakeFiles/PA1.dir/src/main.cpp.i

CMakeFiles/PA1.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/PA1.dir/src/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evan/Study/大二下/计算机图形学/PA1/code/src/main.cpp -o CMakeFiles/PA1.dir/src/main.cpp.s

CMakeFiles/PA1.dir/src/mesh.cpp.o: CMakeFiles/PA1.dir/flags.make
CMakeFiles/PA1.dir/src/mesh.cpp.o: /Users/evan/Study/大二下/计算机图形学/PA1/code/src/mesh.cpp
CMakeFiles/PA1.dir/src/mesh.cpp.o: CMakeFiles/PA1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/evan/Study/大二下/计算机图形学/PA1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/PA1.dir/src/mesh.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PA1.dir/src/mesh.cpp.o -MF CMakeFiles/PA1.dir/src/mesh.cpp.o.d -o CMakeFiles/PA1.dir/src/mesh.cpp.o -c /Users/evan/Study/大二下/计算机图形学/PA1/code/src/mesh.cpp

CMakeFiles/PA1.dir/src/mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/PA1.dir/src/mesh.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evan/Study/大二下/计算机图形学/PA1/code/src/mesh.cpp > CMakeFiles/PA1.dir/src/mesh.cpp.i

CMakeFiles/PA1.dir/src/mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/PA1.dir/src/mesh.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evan/Study/大二下/计算机图形学/PA1/code/src/mesh.cpp -o CMakeFiles/PA1.dir/src/mesh.cpp.s

CMakeFiles/PA1.dir/src/scene_parser.cpp.o: CMakeFiles/PA1.dir/flags.make
CMakeFiles/PA1.dir/src/scene_parser.cpp.o: /Users/evan/Study/大二下/计算机图形学/PA1/code/src/scene_parser.cpp
CMakeFiles/PA1.dir/src/scene_parser.cpp.o: CMakeFiles/PA1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/evan/Study/大二下/计算机图形学/PA1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/PA1.dir/src/scene_parser.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PA1.dir/src/scene_parser.cpp.o -MF CMakeFiles/PA1.dir/src/scene_parser.cpp.o.d -o CMakeFiles/PA1.dir/src/scene_parser.cpp.o -c /Users/evan/Study/大二下/计算机图形学/PA1/code/src/scene_parser.cpp

CMakeFiles/PA1.dir/src/scene_parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/PA1.dir/src/scene_parser.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evan/Study/大二下/计算机图形学/PA1/code/src/scene_parser.cpp > CMakeFiles/PA1.dir/src/scene_parser.cpp.i

CMakeFiles/PA1.dir/src/scene_parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/PA1.dir/src/scene_parser.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evan/Study/大二下/计算机图形学/PA1/code/src/scene_parser.cpp -o CMakeFiles/PA1.dir/src/scene_parser.cpp.s

# Object files for target PA1
PA1_OBJECTS = \
"CMakeFiles/PA1.dir/src/image.cpp.o" \
"CMakeFiles/PA1.dir/src/main.cpp.o" \
"CMakeFiles/PA1.dir/src/mesh.cpp.o" \
"CMakeFiles/PA1.dir/src/scene_parser.cpp.o"

# External object files for target PA1
PA1_EXTERNAL_OBJECTS =

PA1: CMakeFiles/PA1.dir/src/image.cpp.o
PA1: CMakeFiles/PA1.dir/src/main.cpp.o
PA1: CMakeFiles/PA1.dir/src/mesh.cpp.o
PA1: CMakeFiles/PA1.dir/src/scene_parser.cpp.o
PA1: CMakeFiles/PA1.dir/build.make
PA1: deps/vecmath/libvecmath.a
PA1: CMakeFiles/PA1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/evan/Study/大二下/计算机图形学/PA1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable PA1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PA1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PA1.dir/build: PA1
.PHONY : CMakeFiles/PA1.dir/build

CMakeFiles/PA1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PA1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PA1.dir/clean

CMakeFiles/PA1.dir/depend:
	cd /Users/evan/Study/大二下/计算机图形学/PA1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/evan/Study/大二下/计算机图形学/PA1/code /Users/evan/Study/大二下/计算机图形学/PA1/code /Users/evan/Study/大二下/计算机图形学/PA1/build /Users/evan/Study/大二下/计算机图形学/PA1/build /Users/evan/Study/大二下/计算机图形学/PA1/build/CMakeFiles/PA1.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/PA1.dir/depend

