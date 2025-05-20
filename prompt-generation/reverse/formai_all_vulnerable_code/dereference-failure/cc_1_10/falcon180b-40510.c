//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    struct addrinfo hints, *server;
    int sockfd;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo("speedtest.net", "80", &hints, &server)!= 0) {
        printf("Error: could not resolve host.\n");
        exit(1);
    }

    sockfd = socket(server->ai_family, server->ai_socktype, server->ai_protocol);

    if (sockfd == -1) {
        printf("Error: could not create socket.\n");
        exit(1);
    }

    if (connect(sockfd, server->ai_addr, server->ai_addrlen)!= 0) {
        printf("Error: could not connect to server.\n");
        exit(1);
    }

    printf("Connected to server.\n");

    while (1) {
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Error: could not receive data.\n");
            exit(1);
        }

        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    freeaddrinfo(server);
    return 0;
}