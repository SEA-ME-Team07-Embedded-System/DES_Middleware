cmake_minimum_required(VERSION 2.8)
project(Piracer_Interface)

# Find the Python3 libraries
find_package(Python3 COMPONENTS Development)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")
include_directories(
    src-gen
    ${CMAKE_INCLUDE_PATH}/CommonAPI-3.2
    ${CMAKE_INCLUDE_PATH}
)
link_directories(
    ${CMAKE_LIBRARY_PATH}
)
add_executable(PiracerClient
    src/PiracerClient.cpp
    src-gen/v1/commonapi/PiracerSomeIPProxy.cpp
    src-gen/v1/commonapi/PiracerSomeIPDeployment.cpp
)
target_link_libraries(PiracerClient CommonAPI CommonAPI-SomeIP vsomeip3)
add_executable(PiracerService
    src/PiracerInterface.cpp
    src/PiracerClass.cpp
    src/GamePad.cpp
    src/PiracerStubImpl.cpp
    src-gen/v1/commonapi/PiracerSomeIPProxy.cpp
    src-gen/v1/commonapi/PiracerSomeIPDeployment.cpp
    src-gen/v1/commonapi/PiracerSomeIPStubAdapter.cpp
)
target_link_libraries(PiracerService Python3::Python pthread CommonAPI CommonAPI-SomeIP vsomeip3)

install(TARGETS CANClient DESTINATION /usr/bin/example/vsomeip-example)
install(TARGETS CANService DESTINATION /usr/bin/example/vsomeip-example)
