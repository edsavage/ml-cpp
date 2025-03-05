#
# Copyright Elasticsearch B.V. and/or licensed to Elasticsearch B.V. under one
# or more contributor license agreements. Licensed under the Elastic License
# 2.0 and the following additional limitation. Functionality enabled by the
# files subject to the Elastic License 2.0 may only be used in production when
# invoked by an Elasticsearch process with a license key installed that permits
# use of machine learning features. You may not use this file except in
# compliance with the Elastic License 2.0 and the foregoing additional
# limitation.
#

project("ML Seccomp" LANGUAGES CXX)

if(${BUILD_MODULES})
  message(STATUS "Using C++20 Modules")
  if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.28)
      cmake_policy(SET CMP0155 NEW)
  endif()

  # Tell CMake that we explicitly want `import std`. This will initialize the
  # property on all targets declared after this to 1
  set (CMAKE_CXX_MODULE_STD 1)

  set (CMAKE_CXX_STANDARD 23)
  set (CMAKE_CXX_STANDARD_REQUIRED ON)
  set (CMAKE_CXX_EXTENSIONS ON)
endif()

set(SRCS
  CSystemCallFilter.cc
  )

ml_add_library(MlSeccomp STATIC ${SRCS})
