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
CMAKE_SOURCE_DIR = /Users/dmitrii/CrossIntersection

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dmitrii/CrossIntersection/build

# Include any dependencies generated for this target.
include CMakeFiles/IntersectionSimulation.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/IntersectionSimulation.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/IntersectionSimulation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IntersectionSimulation.dir/flags.make

CMakeFiles/IntersectionSimulation.dir/codegen:
.PHONY : CMakeFiles/IntersectionSimulation.dir/codegen

CMakeFiles/IntersectionSimulation.dir/main.cpp.o: CMakeFiles/IntersectionSimulation.dir/flags.make
CMakeFiles/IntersectionSimulation.dir/main.cpp.o: /Users/dmitrii/CrossIntersection/main.cpp
CMakeFiles/IntersectionSimulation.dir/main.cpp.o: CMakeFiles/IntersectionSimulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/dmitrii/CrossIntersection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/IntersectionSimulation.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/IntersectionSimulation.dir/main.cpp.o -MF CMakeFiles/IntersectionSimulation.dir/main.cpp.o.d -o CMakeFiles/IntersectionSimulation.dir/main.cpp.o -c /Users/dmitrii/CrossIntersection/main.cpp

CMakeFiles/IntersectionSimulation.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/IntersectionSimulation.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dmitrii/CrossIntersection/main.cpp > CMakeFiles/IntersectionSimulation.dir/main.cpp.i

CMakeFiles/IntersectionSimulation.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/IntersectionSimulation.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dmitrii/CrossIntersection/main.cpp -o CMakeFiles/IntersectionSimulation.dir/main.cpp.s

CMakeFiles/IntersectionSimulation.dir/IntersectionManager.cpp.o: CMakeFiles/IntersectionSimulation.dir/flags.make
CMakeFiles/IntersectionSimulation.dir/IntersectionManager.cpp.o: /Users/dmitrii/CrossIntersection/IntersectionManager.cpp
CMakeFiles/IntersectionSimulation.dir/IntersectionManager.cpp.o: CMakeFiles/IntersectionSimulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/dmitrii/CrossIntersection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/IntersectionSimulation.dir/IntersectionManager.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/IntersectionSimulation.dir/IntersectionManager.cpp.o -MF CMakeFiles/IntersectionSimulation.dir/IntersectionManager.cpp.o.d -o CMakeFiles/IntersectionSimulation.dir/IntersectionManager.cpp.o -c /Users/dmitrii/CrossIntersection/IntersectionManager.cpp

CMakeFiles/IntersectionSimulation.dir/IntersectionManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/IntersectionSimulation.dir/IntersectionManager.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dmitrii/CrossIntersection/IntersectionManager.cpp > CMakeFiles/IntersectionSimulation.dir/IntersectionManager.cpp.i

CMakeFiles/IntersectionSimulation.dir/IntersectionManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/IntersectionSimulation.dir/IntersectionManager.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dmitrii/CrossIntersection/IntersectionManager.cpp -o CMakeFiles/IntersectionSimulation.dir/IntersectionManager.cpp.s

CMakeFiles/IntersectionSimulation.dir/Car.cpp.o: CMakeFiles/IntersectionSimulation.dir/flags.make
CMakeFiles/IntersectionSimulation.dir/Car.cpp.o: /Users/dmitrii/CrossIntersection/Car.cpp
CMakeFiles/IntersectionSimulation.dir/Car.cpp.o: CMakeFiles/IntersectionSimulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/dmitrii/CrossIntersection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/IntersectionSimulation.dir/Car.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/IntersectionSimulation.dir/Car.cpp.o -MF CMakeFiles/IntersectionSimulation.dir/Car.cpp.o.d -o CMakeFiles/IntersectionSimulation.dir/Car.cpp.o -c /Users/dmitrii/CrossIntersection/Car.cpp

CMakeFiles/IntersectionSimulation.dir/Car.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/IntersectionSimulation.dir/Car.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dmitrii/CrossIntersection/Car.cpp > CMakeFiles/IntersectionSimulation.dir/Car.cpp.i

CMakeFiles/IntersectionSimulation.dir/Car.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/IntersectionSimulation.dir/Car.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dmitrii/CrossIntersection/Car.cpp -o CMakeFiles/IntersectionSimulation.dir/Car.cpp.s

# Object files for target IntersectionSimulation
IntersectionSimulation_OBJECTS = \
"CMakeFiles/IntersectionSimulation.dir/main.cpp.o" \
"CMakeFiles/IntersectionSimulation.dir/IntersectionManager.cpp.o" \
"CMakeFiles/IntersectionSimulation.dir/Car.cpp.o"

# External object files for target IntersectionSimulation
IntersectionSimulation_EXTERNAL_OBJECTS =

IntersectionSimulation: CMakeFiles/IntersectionSimulation.dir/main.cpp.o
IntersectionSimulation: CMakeFiles/IntersectionSimulation.dir/IntersectionManager.cpp.o
IntersectionSimulation: CMakeFiles/IntersectionSimulation.dir/Car.cpp.o
IntersectionSimulation: CMakeFiles/IntersectionSimulation.dir/build.make
IntersectionSimulation: /opt/homebrew/Cellar/sdl2/2.32.0/lib/libSDL2.dylib
IntersectionSimulation: CMakeFiles/IntersectionSimulation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/dmitrii/CrossIntersection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable IntersectionSimulation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IntersectionSimulation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IntersectionSimulation.dir/build: IntersectionSimulation
.PHONY : CMakeFiles/IntersectionSimulation.dir/build

CMakeFiles/IntersectionSimulation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/IntersectionSimulation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/IntersectionSimulation.dir/clean

CMakeFiles/IntersectionSimulation.dir/depend:
	cd /Users/dmitrii/CrossIntersection/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dmitrii/CrossIntersection /Users/dmitrii/CrossIntersection /Users/dmitrii/CrossIntersection/build /Users/dmitrii/CrossIntersection/build /Users/dmitrii/CrossIntersection/build/CMakeFiles/IntersectionSimulation.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/IntersectionSimulation.dir/depend

