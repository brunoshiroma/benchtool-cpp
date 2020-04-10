FROM gcc:9.3.0 as buildbase

RUN apt update && yes | apt install cmake

FROM buildbase

WORKDIR /bench

COPY . .

RUN cmake .

RUN cmake --build . --target benchtool_cpp

ENTRYPOINT ["./linux_benchtool_cpp"]