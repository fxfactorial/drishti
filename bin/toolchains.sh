#!/bin/bash

INSTALL_DIR=\
(
#   "_os/centos-6.2"               
    "."
    "."
    "."
    "."
    "."
    "."
)

NAMES=\
(
#    "centos-6.2"
    "osx"
    "ios"
    "android/armeabi-v7a"
    "android/arm64-v8a"
    "android/x86"
    "android/x86-64"
)

TOOLCHAINS=\
(
#    gcc-hid-fpic
    libcxx-hid 
    ios-9-2-dep-8-0-hid
    android-ndk-r10e-api-16-armeabi-v7a-neon-clang-35-hid
    android-ndk-r10e-api-21-arm64-v8a-gcc-49-hid
    android-ndk-r10e-api-16-x86-hid
    android-ndk-r10e-api-21-x86-64-hid
)

RELEASES=\
(
#    1
    1
    0
    1
    1
    1
    1
)

BUILDER=\
(
#    build-centos-6.2.sh
	build-libcxx.sh
	build-ios-9-1-hid.sh
	build-android.sh
	build-android-64.sh
	build-android-x86.sh
	build-android-x86-64.sh
)