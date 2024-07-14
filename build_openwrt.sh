#!/bin/bash

# - install depends tools
# yum -y install git
# yum -y install gcc gcc-c++ autoconf libtool automake make
#

# - clone code
# git clone https://github.com/brinkqiang/dmcurl.git
# pushd dmcurl
# git submodule update --init --recursive
#

# pushd depends_path
# libtoolize && aclocal && autoheader && autoconf && automake --add-missing
# sh configure
# popd

rm -rf build
mkdir build

pushd thirdparty/curl
./buildconf
./configure --disable-dependency-tracking
# autoreconf -i
popd

#find . -name "*.cmake.in" -exec sed -i  "s/-lrt//g" '{}' \;
#find . -name "*.cmake.in" -exec sed -i  "s/-ldl//g" '{}' \;
#find . -name "link.txt" -exec sed -i  "s/-ldl//g" '{}' \;
#find . -name "link.txt" -exec sed -i  "s/-lrt//g" '{}' \;
#find . -name Makefile2 -exec sed -i  "s/-ldl//g" '{}' \;
#find . -name Makefile2 -exec sed -i  "s/-lrt//g" '{}' \;

pushd build

cmake -DCMAKE_BUILD_TYPE=relwithdebinfo ..
make -j1
popd
# popd