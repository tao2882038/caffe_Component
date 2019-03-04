# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (common)

# 编译方式
set(CMAKE_BUILD_TYPE Release) #(Debug, Release)

# ---[ Using cmake scripts and modules
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)

include(ExternalProject)
include(GNUInstallDirs)

# 编译选项---[ Options
option(CPU_ONLY  "Build Caffe without CUDA support" OFF) 

# 编译参数---[ Flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Wall")

# 添加其他cmake文件---[ include
include(cmake/Utils.cmake)

# 添加其他包含CMakeLists.txt的路径---[ Subdirectories
#add_subdirectory(src/gtest)

## 依赖 库文件和头文件---[ Dependencies
set(Caffe_LINKER_LIBS "")
set(Caffe_INCLUDE_DIRS "")
include(cmake/Dependencies.cmake)

    # # 依赖---[ Boost
    # find_package(Boost 1.54 REQUIRED COMPONENTS system thread filesystem)
    # list(APPEND Caffe_INCLUDE_DIRS PUBLIC ${Boost_INCLUDE_DIRS})
    # list(APPEND Caffe_LINKER_LIBS PUBLIC ${Boost_LIBRARIES})

    # # 依赖---[ Threads
    # find_package(Threads REQUIRED)
    # list(APPEND Caffe_LINKER_LIBS PRIVATE ${CMAKE_THREAD_LIBS_INIT})

    # # 依赖---[ Boost_python
    # find_package(PythonInterp 2.7)
    # find_package(PythonLibs 2.7)
    # find_package(NumPy 1.7.1)
    # find_package(Boost 1.54 COMPONENTS python-py27)
    # list(APPEND Caffe_INCLUDE_DIRS PRIVATE ${PYTHON_INCLUDE_DIRS} ${NUMPY_INCLUDE_DIR} PUBLIC ${Boost_INCLUDE_DIRS})
    # list(APPEND Caffe_LINKER_LIBS PRIVATE ${PYTHON_LIBRARIES} PUBLIC ${Boost_LIBRARIES})


## 源文件
    # 添加工程头文件路径
    include_directories(${PROJECT_SOURCE_DIR}/include)
    # 头文件
    set(INCLUDE_VARS "")
    file(GLOB_RECURSE INCLUDE_VARS ${PROJECT_SOURCE_DIR}/*.hpp)
    # 源文件
    set(CXX_VARS "")
    file(GLOB_RECURSE CXX_VARS ${PROJECT_SOURCE_DIR}/src/*.cpp)
    list(APPEND CXX_VARS ${PROJECT_SOURCE_DIR}/_common.cpp)


## target
    # 可执行文件---[添加target 
    add_executable(Demo ${CXX_VARS}  ${Boost_INCLUDE_DIRS})
    # 为target添加库文件路径
    target_link_libraries(Demo ${Caffe_LINKER_LIBS})
    # 设置目标命名及头文件路径
    #set_target_properties(common PROPERTIES PREFIX "" OUTPUT_NAME "_common")
    #target_include_directories(common PUBLIC ${Caffe_INCLUDE_DIRS})

    # 库文件---[添加target
    list(APPEND CXX_VARS ${PROJECT_SOURCE_DIR}/_common.cpp)
    #file(GLOB_RECURSE python_includes /usr/include/python2.7/*pyconfig.h)
    add_library(common SHARED ${CXX_VARS} ${INCLUDE_VARS} ${cuda_objcs} )
    target_link_libraries(common PUBLIC ${Caffe_LINKER_LIBS}  )
    set_target_properties(common PROPERTIES PREFIX "" OUTPUT_NAME "_common")
    target_include_directories(common PUBLIC ${Caffe_INCLUDE_DIRS})

    #install
    set(CMAKE_INSTALL_LIBDIR ${PROJECT_SOURCE_DIR}/lib)
    install(TARGETS  common  DESTINATION ${CMAKE_INSTALL_LIBDIR})

    # 库文件---[添加target
    #list(APPEND CXX_VARS ${PROJECT_SOURCE_DIR}/_common.cpp)
    #file(GLOB_RECURSE python_includes /usr/include/python2.7/*pyconfig.h)
    #add_library(common SHARED ${CXX_VARS} ${INCLUDE_VARS} ${cuda_objcs} )
    #target_link_libraries(common PUBLIC ${Caffe_LINKER_LIBS}  )
    #set_target_properties(common PROPERTIES PREFIX "" OUTPUT_NAME "_common")
    #target_include_directories(common PUBLIC ${Caffe_INCLUDE_DIRS})

# message("--------------------------------")
# message(${CXX_VARS})
#message(${python_includes})


## install
    # 设置install路径
    #set(CMAKE_INSTALL_INCLUDEDIR ${PROJECT_BINARY_DIR}/install/include)
    #set(CMAKE_INSTALL_LIBDIR ${PROJECT_BINARY_DIR}/install/lib)
    #set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/install/bin)

    # 安装
    #install(FILES  ${Demo_INCLUDE_DIRS} DESTINATION  ${CMAKE_INSTALL_INCLUDEDIR})
    #install(TARGETS  caffeproto  DESTINATION ${CMAKE_INSTALL_LIBDIR})
    #install(TARGETS  Demo  DESTINATION ${CMAKE_INSTALL_PREFIX})


