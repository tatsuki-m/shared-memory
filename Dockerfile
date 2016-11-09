FROM centos:latest

RUN yum install -y gcc gcc-c++ boost-devel

RUN mkdir /work
ADD main /work

