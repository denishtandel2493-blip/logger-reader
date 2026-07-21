FROM gcc:14 AS builder

WORKDIR /app

COPY . .

RUN g++ main.cpp Logger.cpp -o logger-reader

FROM ubuntu:24.04

WORKDIR /app

COPY --from=builder /app/logger-reader .

RUN mkdir -p logs

ENTRYPOINT ["./logger-reader"]