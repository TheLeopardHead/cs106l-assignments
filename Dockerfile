# Use Ubuntu 20.04 as the base image, where GCC 10 is available
#FROM ubuntu:20.04
FROM swr.cn-north-4.myhuaweicloud.com/ddn-k8s/docker.io/ubuntu:20.04

# Avoid prompts during package installation
ARG DEBIAN_FRONTEND=noninteractive

# Update and install software
RUN apt-get update && apt-get install -y \
    gcc-10 g++-10 python3.8 python3-pip git wget make \
    libssl-dev libasan5 libubsan1

# Set GCC 10 as the default gcc and g++ compilers
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 10 && \
    update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-10 10

# Final command
CMD ["echo", "Welcome to CS106L!"]