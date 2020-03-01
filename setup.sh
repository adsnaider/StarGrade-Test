#!/usr/bin/bash

# Bazel
apt install curl -y
curl https://bazel.build/bazel-release.pub.gpg | apt-key add -
echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | tee /etc/apt/sources.list.d/bazel.list
apt update && apt install bazel -y

bazel build -c opt @stargrade//:runner
bazel build -c opt //tests
