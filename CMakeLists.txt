cmake_minimum_required(VERSION 3.2)

PROJECT(dmcurl)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()

SET(DMCURL_VERSION_MAJOR "1")
SET(DMCURL_VERSION_MINOR "0")
SET(DMCURL_VERSION_PATCH "1")
SET(DMCURL_VERSION "${DMCURL_VERSION_MAJOR}.${DMCURL_VERSION_MINOR}.${DMCURL_VERSION_PATCH}")

MESSAGE(STATUS "VERSION: ${DMCURL_VERSION}")

ADD_DEFINITIONS(-DUSE_DMCURL)
ADD_DEFINITIONS(-DNOMINMAX)

ModuleImport("mbedtls" "thirdparty/mbedtls")
ModuleImport("curl" "thirdparty/curl")
ModuleImport("dmtest" "thirdparty/dmtest")

LibImportDepends("libcpr" "src/libcpr" "libcurl;mbedcrypto;mbedx509;mbedtls")
LibImportDepends("libcpr_util" "src/libcpr_util" "libcpr;libcurl;mbedcrypto;mbedx509;mbedtls")

ExeImport("test" "dmtest;libcpr;libcurl;mbedcrypto;mbedx509;mbedtls")
