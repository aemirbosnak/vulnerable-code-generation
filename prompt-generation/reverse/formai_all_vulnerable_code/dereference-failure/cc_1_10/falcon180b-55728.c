//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void die(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char** argv) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <host> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* host = argv[1];
    char* username = argv[2];
    char* password = argv[3];

    struct addrinfo hints, *server;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int status = getaddrinfo(host, "21", &hints, &server);
    if (status!= 0) {
        die("getaddrinfo");
    }

    int sock = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
    if (sock == -1) {
        die("socket");
    }

    status = connect(sock, server->ai_addr, server->ai_addrlen);
    if (status!= 0) {
        die("connect");
    }

    char login[BUFFER_SIZE];
    snprintf(login, BUFFER_SIZE, "USER %s\r\n", username);
    send(sock, login, strlen(login), 0);

    char pass[BUFFER_SIZE];
    snprintf(pass, BUFFER_SIZE, "PASS %s\r\n", password);
    send(sock, pass, strlen(pass), 0);

    char welcome[BUFFER_SIZE];
    recv(sock, welcome, BUFFER_SIZE, 0);
    printf("Welcome message: %s", welcome);

    return EXIT_SUCCESS;
}