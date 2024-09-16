FROM ubuntu:jammy

RUN apt update -y && apt install -y build-essential

COPY . /app

WORKDIR /app

ENTRYPOINT ["make"]

