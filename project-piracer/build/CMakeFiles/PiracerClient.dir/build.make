# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/seame-workstation05/Desktop/DES_Middleware/project-piracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/seame-workstation05/Desktop/DES_Middleware/project-piracer/build

# Include any dependencies generated for this target.
include CMakeFiles/PiracerClient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PiracerClient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PiracerClient.dir/flags.make

CMakeFiles/PiracerClient.dir/src/PiracerClient.cpp.o: CMakeFiles/PiracerClient.dir/flags.make
CMakeFiles/PiracerClient.dir/src/PiracerClient.cpp.o: ../src/PiracerClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seame-workstation05/Desktop/DES_Middleware/project-piracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PiracerClient.dir/src/PiracerClient.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PiracerClient.dir/src/PiracerClient.cpp.o -c /home/seame-workstation05/Desktop/DES_Middleware/project-piracer/src/PiracerClient.cpp

CMakeFiles/PiracerClient.dir/src/PiracerClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PiracerClient.dir/src/PiracerClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/seame-workstation05/Desktop/DES_Middleware/project-piracer/src/PiracerClient.cpp > CMakeFiles/PiracerClient.dir/src/PiracerClient.cpp.i

CMakeFiles/PiracerClient.dir/src/PiracerClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PiracerClient.dir/src/PiracerClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/seame-workstation05/Desktop/DES_Middleware/project-piracer/src/PiracerClient.cpp -o CMakeFiles/PiracerClient.dir/src/PiracerClient.cpp.s

CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPProxy.cpp.o: CMakeFiles/PiracerClient.dir/flags.make
CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPProxy.cpp.o: ../src-gen/v1/commonapi/PiracerSomeIPProxy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seame-workstation05/Desktop/DES_Middleware/project-piracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPProxy.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPProxy.cpp.o -c /home/seame-workstation05/Desktop/DES_Middleware/project-piracer/src-gen/v1/commonapi/PiracerSomeIPProxy.cpp

CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPProxy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPProxy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/seame-workstation05/Desktop/DES_Middleware/project-piracer/src-gen/v1/commonapi/PiracerSomeIPProxy.cpp > CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPProxy.cpp.i

CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPProxy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPProxy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/seame-workstation05/Desktop/DES_Middleware/project-piracer/src-gen/v1/commonapi/PiracerSomeIPProxy.cpp -o CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPProxy.cpp.s

CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPDeployment.cpp.o: CMakeFiles/PiracerClient.dir/flags.make
CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPDeployment.cpp.o: ../src-gen/v1/commonapi/PiracerSomeIPDeployment.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seame-workstation05/Desktop/DES_Middleware/project-piracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPDeployment.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPDeployment.cpp.o -c /home/seame-workstation05/Desktop/DES_Middleware/project-piracer/src-gen/v1/commonapi/PiracerSomeIPDeployment.cpp

CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPDeployment.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPDeployment.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/seame-workstation05/Desktop/DES_Middleware/project-piracer/src-gen/v1/commonapi/PiracerSomeIPDeployment.cpp > CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPDeployment.cpp.i

CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPDeployment.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPDeployment.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/seame-workstation05/Desktop/DES_Middleware/project-piracer/src-gen/v1/commonapi/PiracerSomeIPDeployment.cpp -o CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPDeployment.cpp.s

CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPStubAdapter.cpp.o: CMakeFiles/PiracerClient.dir/flags.make
CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPStubAdapter.cpp.o: ../src-gen/v1/commonapi/PiracerSomeIPStubAdapter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seame-workstation05/Desktop/DES_Middleware/project-piracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPStubAdapter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPStubAdapter.cpp.o -c /home/seame-workstation05/Desktop/DES_Middleware/project-piracer/src-gen/v1/commonapi/PiracerSomeIPStubAdapter.cpp

CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPStubAdapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPStubAdapter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/seame-workstation05/Desktop/DES_Middleware/project-piracer/src-gen/v1/commonapi/PiracerSomeIPStubAdapter.cpp > CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPStubAdapter.cpp.i

CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPStubAdapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPStubAdapter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/seame-workstation05/Desktop/DES_Middleware/project-piracer/src-gen/v1/commonapi/PiracerSomeIPStubAdapter.cpp -o CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPStubAdapter.cpp.s

# Object files for target PiracerClient
PiracerClient_OBJECTS = \
"CMakeFiles/PiracerClient.dir/src/PiracerClient.cpp.o" \
"CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPProxy.cpp.o" \
"CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPDeployment.cpp.o" \
"CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPStubAdapter.cpp.o"

# External object files for target PiracerClient
PiracerClient_EXTERNAL_OBJECTS =

PiracerClient: CMakeFiles/PiracerClient.dir/src/PiracerClient.cpp.o
PiracerClient: CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPProxy.cpp.o
PiracerClient: CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPDeployment.cpp.o
PiracerClient: CMakeFiles/PiracerClient.dir/src-gen/v1/commonapi/PiracerSomeIPStubAdapter.cpp.o
PiracerClient: CMakeFiles/PiracerClient.dir/build.make
PiracerClient: CMakeFiles/PiracerClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/seame-workstation05/Desktop/DES_Middleware/project-piracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable PiracerClient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PiracerClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PiracerClient.dir/build: PiracerClient

.PHONY : CMakeFiles/PiracerClient.dir/build

CMakeFiles/PiracerClient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PiracerClient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PiracerClient.dir/clean

CMakeFiles/PiracerClient.dir/depend:
	cd /home/seame-workstation05/Desktop/DES_Middleware/project-piracer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/seame-workstation05/Desktop/DES_Middleware/project-piracer /home/seame-workstation05/Desktop/DES_Middleware/project-piracer /home/seame-workstation05/Desktop/DES_Middleware/project-piracer/build /home/seame-workstation05/Desktop/DES_Middleware/project-piracer/build /home/seame-workstation05/Desktop/DES_Middleware/project-piracer/build/CMakeFiles/PiracerClient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PiracerClient.dir/depend

