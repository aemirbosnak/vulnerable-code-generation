//FormAI DATASET v1.0 Category: Simple Web Server ; Style: thoughtful
// This is a simple web server program written in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXPENDING 10
#define MAXSIZE 1024

void handleClient(int clntSocket);

int main(int argc, char *argv[]) {
    int servSocket;
    int clntSocket;
    struct sockaddr_in servAddr;
    struct sockaddr_in clntAddr;
    unsigned short servPort;
    unsigned int clntLen;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server port>\n", argv[0]);
        exit(1);
    }

    servPort = atoi(argv[1]);

    if ((servSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("socket() failed");
        exit(1);
    }

    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(servPort);

    if (bind(servSocket, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0) {
        perror("bind() failed");
        exit(1);
    }

    if (listen(servSocket, MAXPENDING) < 0) {
        perror("listen() failed");
        exit(1);
    }

    while (1) {
        clntLen = sizeof(clntAddr);
        if ((clntSocket = accept(servSocket, (struct sockaddr *) &clntAddr, &clntLen)) < 0) {
            perror("accept() failed");
            exit(1);
        }

        handleClient(clntSocket);
    }
}

void handleClient(int clntSocket) {
    char buffer[MAXSIZE];
    ssize_t numBytesRcvd;
    ssize_t numBytesSent;

    // Receive message from client
    if ((numBytesRcvd = recv(clntSocket, buffer, MAXSIZE, 0)) < 0) {
        perror("recv() failed");
        exit(1);
    }

    // Send HTTP response to client
    char httpResponse[] = "HTTP/1.1 200 OK\r\n\Content-Type: text/html; charset=UTF-8\r\n\r\n<html><body><h1>Hello, world!</h1></body></html>";
    if ((numBytesSent = send(clntSocket, httpResponse, strlen(httpResponse), 0)) < 0) {
        perror("send() failed");
        exit(1);
    }

    if (close(clntSocket) < 0) {
        perror("close() failed");
        exit(1);
    }
}