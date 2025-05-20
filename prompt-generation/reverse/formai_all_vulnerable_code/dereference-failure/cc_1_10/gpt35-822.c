//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BACKLOG 5
#define MAXBUF 1024
#define PORT 8080

#define ERROR "\033[0;31m"
#define SUCCESS "\033[0;32m"
#define CYBER "\033[0;36m"
#define DEFAULT "\033[0m"

void error(char *message) {
    fprintf(stderr, ERROR "[ERROR] %s\n" DEFAULT, message);
    exit(1);
}

void success(char *message) {
    printf(SUCCESS "[SUCCESS] %s\n" DEFAULT, message);
}

typedef struct {
    int clientFd;
    struct sockaddr_in clientAddr;
} httpConnection;

void parseRequest(char *buffer, char **uri, char **host) {
    char *saveptr;
    char *method = strtok_r(buffer, " ", &saveptr);
    *uri = strtok_r(NULL, " ", &saveptr);
    strtok_r(NULL, "\r\n", &saveptr);
    char *header = strtok_r(NULL, "\r\n", &saveptr);
    while (header) {
        if (strstr(header, "Host: ")) {
            *host = header + 6;
            break;
        }
        header = strtok_r(NULL, "\r\n", &saveptr);
    }

    if (!*host) {
        error("Could not find host in request.");
    }
}

void *httpProxy(void *connectionPtr) {
    httpConnection *httpConn = (httpConnection *) connectionPtr;
    int clientFd = httpConn->clientFd;
    struct sockaddr_in clientAddr = httpConn->clientAddr;
    char buffer[MAXBUF];

    success("Accepted new HTTP connection!");
    int readBytes = read(clientFd, buffer, MAXBUF);
    if (readBytes < 0) {
        error("Error reading from HTTP client.");
    }

    buffer[readBytes] = 0;
    char *uri, *host;
    parseRequest(buffer, &uri, &host);
    success(uri);
    success(host);

    int serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFd < 0) {
        error("Error creating server socket.");
    }

    struct sockaddr_in serverAddr = {
        .sin_family = AF_INET,
        .sin_port = htons(80)
    };
    if (inet_pton(AF_INET, host, &serverAddr.sin_addr) <= 0) {
        error("Error converting IP address.");
    }

    if (connect(serverFd, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
        error("Error connecting to server.");
    }

    if (write(serverFd, buffer, strlen(buffer)) < 0) {
        error("Error writing to server.");
    }

    while ((readBytes = read(serverFd, buffer, MAXBUF)) > 0) {
        if (write(clientFd, buffer, readBytes) < 0) {
            error("Error writing to client.");
        }
    }

    success("HTTP connection closed.");
    close(serverFd);
    close(clientFd);
    free(httpConn);
    return NULL;
}

int main() {
    success("HTTP Proxy starting up...");
    int serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFd < 0) {
        error("Error creating server socket.");
    }

    int opt = 1;
    if (setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        error("Error setting socket options.");
    }

    struct sockaddr_in serverAddr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT)
    };
    if (bind(serverFd, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
        error("Error binding server socket.");
    }

    if (listen(serverFd, BACKLOG) < 0) {
        error("Error listening on server socket.");
    }

    success("HTTP Proxy running...");

    while (true) {
        httpConnection *httpConn = (httpConnection *) malloc(sizeof(httpConnection));
        socklen_t clientAddrLen = sizeof(httpConn->clientAddr);
        httpConn->clientFd = accept(serverFd, (struct sockaddr *) &httpConn->clientAddr, &clientAddrLen);
        if (httpConn->clientFd < 0) {
            error("Error accepting HTTP connection.");
        }
        pthread_t thread;
        pthread_create(&thread, NULL, httpProxy, httpConn);
    }

    close(serverFd);
    return 0;
}