FROM debian:11-slim as buildbase

RUN apt-get update
RUN apt-get install gcc -y
RUN apt-get install g++ -y
RUN apt-get install libgmp-dev -y
RUN apt-get install make -y
RUN apt-get install cmake -y

WORKDIR /bench

COPY . .

RUN cmake .

RUN cmake --build . --target benchtool_cpp

FROM debian:11-slim as runtime

RUN apt-get update
RUN apt-get install libgmp10 -y

WORKDIR /bench

COPY --from=buildbase /bench/linux_benchtool_cpp .

ENTRYPOINT ["./linux_benchtool_cpp"]
