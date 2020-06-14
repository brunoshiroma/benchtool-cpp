FROM alpine as buildbase

RUN apk update
RUN apk add gcc
RUN apk add g++
RUN apk add gmp-dev
RUN apk add make
RUN apk add cmake

WORKDIR /bench

COPY . .

RUN cmake .

RUN cmake --build . --target benchtool_cpp

FROM alpine as runtime

RUN apk update
RUN apk add gmp
RUN apk add libstdc++

WORKDIR /bench

COPY --from=buildbase /bench/linux_benchtool_cpp .

ENTRYPOINT ["./linux_benchtool_cpp"]
