cmake_minimum_required(VERSION 3.14)
project(vfxcore LANGUAGES CXX)

option(PLATFORM_APPLE "Build for Apple" OFF)
option(PLATFORM_ANDROID "Build for Android" OFF)

set(VFX_SOURCES
  analysis/TierA.cpp
  analysis/TierB.cpp
  analysis/SceneDetect.cpp
  fx/Graph.cpp
  novelty/DNA.cpp
  novelty/Sampler.cpp
  novelty/Constraints.cpp
  runtime/Governor.cpp
  runtime/Pipeline.cpp
)

if(PLATFORM_APPLE)
  list(APPEND VFX_SOURCES
    platform/apple/MetalInterop.mm
    platform/apple/VideoIO.mm)
endif()
if(PLATFORM_ANDROID)
  list(APPEND VFX_SOURCES
    platform/android/GLInterop.cpp
    platform/android/VideoIO.cpp)
endif()

add_library(vfxcore STATIC ${VFX_SOURCES})

target_include_directories(vfxcore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(vfxcore PUBLIC cxx_std_17)

if(PLATFORM_APPLE)
  target_compile_definitions(vfxcore PUBLIC PLATFORM_APPLE=1)
elseif(PLATFORM_ANDROID)
  target_compile_definitions(vfxcore PUBLIC PLATFORM_ANDROID=1)
endif()
