#!/bin/bash
set -e                                   # 任何一步出错就立即停止
cd "$(dirname "$0")"                     # 进入脚本所在目录，即 third_party/

VER=4.10.0
mkdir -p src
if [ ! -d src/opencv-$VER ]; then
    curl -L -o src/opencv-$VER.tar.gz https://github.com/opencv/opencv/archive/refs/tags/$VER.tar.gz
    tar xzf src/opencv-$VER.tar.gz -C src
fi

cmake -S src/opencv-$VER -B build-opencv \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=$(pwd)/opencv \
    -DBUILD_LIST=core,imgproc,imgcodecs \
    -DBUILD_TESTS=OFF -DBUILD_PERF_TESTS=OFF \
    -DBUILD_EXAMPLES=OFF -DBUILD_opencv_apps=OFF \
    -DWITH_FFMPEG=OFF -DWITH_GTK=OFF

cmake --build build-opencv -j$(nproc)
cmake --install build-opencv