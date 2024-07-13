cmake_minimum_required(VERSION 3.8)

PROJECT(dmcpr)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()

SET(cpr_VERSION_MAJOR "1")
SET(cpr_VERSION_MINOR "0")
SET(cpr_VERSION_PATCH "1")
SET(cpr_VERSION "${cpr_VERSION_MAJOR}.${cpr_VERSION_MINOR}.${cpr_VERSION_PATCH}")

MESSAGE(STATUS "VERSION: ${cpr_VERSION}")

ADD_DEFINITIONS(-DUSE_DMCURL)
ADD_DEFINITIONS(-DNOMINMAX)

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/cmake/cprver.h.in" "${CMAKE_CURRENT_SOURCE_DIR}/include/cpr/cprver.h")

ModuleImport("mbedtls" "thirdparty/mbedtls")
ModuleImport("curl" "thirdparty/curl")
ModuleImport("dmtest" "thirdparty/dmtest")

LibImportDepends("libcpr" "src/libcpr" "libcurl;mbedcrypto;mbedx509;mbedtls")
LibImportDepends("libcpr_util" "src/libcpr_util" "libcpr;libcurl;mbedcrypto;mbedx509;mbedtls")

ExeImport("test" "dmtest;libcpr;libcpr_util;libcurl;mbedcrypto;mbedx509;mbedtls")
