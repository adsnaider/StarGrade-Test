#!/usr/bin/bash

# Bazel
apt install curl -y
curl https://bazel.build/bazel-release.pub.gpg | apt-key add -
echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | tee /etc/apt/sources.list.d/bazel.list
apt update && apt install bazel -y

# GTest
apt install libgtest-dev
apt install cmake
cd /usr/src/gtest
cmake CMakeLists.txt
make
cp *.a /usr/lib/

bazel build -c opt //tests
bazel build -c opt @stargrade//:runner
