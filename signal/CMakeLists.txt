# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo)

# set build type
set(CMAKE_BUILD_TYPE Release) #(Debug, Release)

#depende
find_package(Boost 1.54 REQUIRED COMPONENTS system thread filesystem)



# 添加 math 子目录
#add_subdirectory(math)

#source file
set(Demo_INCLUDE_DIRS "")
set(Demo_CXX_DIRS "")
file(GLOB Demo_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/*.h*)
file(GLOB Demo_CXX_DIRS ${PROJECT_SOURCE_DIR}/*.cpp)
add_executable(Demo ${Demo_CXX_DIRS} ${Demo_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
target_link_libraries(Demo ${Boost_LIBRARIES})

#message(${Caffe_INCLUDE_DIRS})
#message(${Caffe_LINKER_LIBS})
