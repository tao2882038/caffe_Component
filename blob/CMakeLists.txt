# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Blob)

# 编译方式
set(CMAKE_BUILD_TYPE Debug) #(Debug, Release)

# ---[ Using cmake scripts and modules
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)

include(ExternalProject)
include(GNUInstallDirs)

# 编译选项---[ Options
option(CPU_ONLY  "Build Caffe without CUDA support" OFF) 


include(cmake/Utils.cmake)

# 依赖---[ Dependencies
include(cmake/Dependencies.cmake)

# protobuf文件编译
find_package( Protobuf REQUIRED )
list(APPEND Caffe_INCLUDE_DIRS PUBLIC ${PROTOBUF_INCLUDE_DIR})
list(APPEND Caffe_LINKER_LIBS PUBLIC ${PROTOBUF_LIBRARIES})
option(BUILD_python_layer "Build the Caffe Python layer" ON)


if(EXISTS ${PROTOBUF_PROTOC_EXECUTABLE})
  message(STATUS "Found PROTOBUF Compiler: ${PROTOBUF_PROTOC_EXECUTABLE}")
else()
  message(FATAL_ERROR "Could not find PROTOBUF Compiler")
endif()

set(FILENAME ${PROTOBUF_INCLUDE_DIR}/google/protobuf/stubs/common.h)
set(vars_regex GOOGLE_PROTOBUF_VERSION)
if(EXISTS "${FILENAME}")
  file(STRINGS "${FILENAME}" PROTOBUF_VERSION REGEX "#define[ \t]+(${vars_regex})[ \t]+[0-9]+" )
  string(REGEX MATCH "([0-9])00([0-9])00([0-9])" PROTOBUF_VERSION ${PROTOBUF_VERSION})
  set(PROTOBUF_VERSION "${CMAKE_MATCH_1}.${CMAKE_MATCH_2}.${CMAKE_MATCH_3}")
  message("PROTOBUF_VERSION: " ${PROTOBUF_VERSION})
else()
  message(******** no file ********)
endif()

file(INSTALL ${PROJECT_SOURCE_DIR}/src/caffe/proto/caffe.proto DESTINATION ${PROJECT_BINARY_DIR}/include/caffe/proto)
include_directories("${PROJECT_BINARY_DIR}/include/")
set(proto_files "${PROJECT_BINARY_DIR}/include/caffe/proto/caffe.proto")
set(output_dir "${PROJECT_BINARY_DIR}/include/caffe/proto")
set(proto_path ${PROJECT_BINARY_DIR}/include/caffe/proto)

get_filename_component(abs_fil ${proto_files} ABSOLUTE)
get_filename_component(fil_we ${proto_files} NAME_WE)
add_custom_command(
      OUTPUT "${output_dir}/${fil_we}.pb.cc"
             "${output_dir}/${fil_we}.pb.h"
             "${output_dir}/${fil_we}_pb2.py"
      COMMAND ${CMAKE_COMMAND} -E make_directory "${output_dir}"
      COMMAND ${PROTOBUF_PROTOC_EXECUTABLE} --cpp_out ${output_dir} --proto_path ${proto_path} ${abs_fil}
      COMMAND ${PROTOBUF_PROTOC_EXECUTABLE} --python_out ${output_dir} --proto_path ${proto_path} ${abs_fil}
      DEPENDS ${abs_fil}
      COMMENT "Running C++/Python protocol buffer compiler on ${fil}" VERBATIM )

list(APPEND srcs_var "${output_dir}/${fil_we}.pb.cc")
list(APPEND hdrs_var "${output_dir}/${fil_we}.pb.h")
list(APPEND python_var "${output_dir}/${fil_we}_pb2.py")

set_source_files_properties(${srcs_var} ${hdrs_var} ${python_var} PROPERTIES GENERATED TRUE)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib) 
add_library(caffeproto STATIC ${srcs_var} ${hdrs_var} ${python_var} )
list(APPEND Caffe_LINKER_LIBS caffeproto ${Boost_LIBRARIES})



# 添加 math 子目录
#add_subdirectory(math)

find_package(PythonInterp 2.7)
find_package(PythonLibs 2.7)
find_package(NumPy 1.7.1)
find_package(Boost 1.54 COMPONENTS python-py27)
list(APPEND Caffe_INCLUDE_DIRS PRIVATE ${PYTHON_INCLUDE_DIRS} ${NUMPY_INCLUDE_DIR} PUBLIC ${Boost_INCLUDE_DIRS})
list(APPEND Caffe_LINKER_LIBS PRIVATE ${PYTHON_LIBRARIES} PUBLIC ${Boost_LIBRARIES})

include_directories(${PROJECT_SOURCE_DIR}/include)
caffe_cuda_compile(cuda_objcs ${PROJECT_SOURCE_DIR}/src/caffe/util/math_functions.cu)

# 源文件
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(/usr/include/python2.7)
set(INCLUDE_VARS "")
set(CXX_VARS "")
file(GLOB_RECURSE INCLUDE_VARS ${PROJECT_SOURCE_DIR}/*.hpp)
file(GLOB_RECURSE CXX_VARS ${PROJECT_SOURCE_DIR}/src/*.cpp)
list(APPEND CXX_VARS ${PROJECT_SOURCE_DIR}/_blob.cpp)
#file(GLOB_RECURSE python_includes /usr/include/python2.7/*pyconfig.h)
add_library(blob SHARED ${CXX_VARS} ${INCLUDE_VARS} ${cuda_objcs} ${hdrs_var})
target_link_libraries(blob PUBLIC ${Caffe_LINKER_LIBS}  )
set_target_properties(blob PROPERTIES PREFIX "" OUTPUT_NAME "_blob")
target_include_directories(blob PUBLIC ${Caffe_INCLUDE_DIRS} ${hdrs_var})

message("--------------------------------")
message(${Boost_LIBRARIES})
#message(${python_includes})


set(CMAKE_INSTALL_LIBDIR ${PROJECT_SOURCE_DIR}/lib)
install(TARGETS  blob  DESTINATION ${CMAKE_INSTALL_LIBDIR})



#install
#set(CMAKE_INSTALL_INCLUDEDIR ${PROJECT_BINARY_DIR}/install/include)
#set(CMAKE_INSTALL_LIBDIR ${PROJECT_BINARY_DIR}/install/lib)
#set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/install/bin)

#install(FILES  ${Demo_INCLUDE_DIRS} DESTINATION  ${CMAKE_INSTALL_INCLUDEDIR})
#install(TARGETS  caffeproto  DESTINATION ${CMAKE_INSTALL_LIBDIR})
#install(TARGETS  Demo  DESTINATION ${CMAKE_INSTALL_PREFIX})

#message(${Caffe_INCLUDE_DIRS})
#message(${Caffe_LINKER_LIBS})
