//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo *serverinfo;
    char *host = "localhost";
    char *port = "21";
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int bytes_sent;

    if (argc < 2) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = argv[2];

    if ((serverinfo = getaddrinfo(host, port, NULL, NULL)) == NULL) {
        printf("Error: could not resolve host\n");
        exit(1);
    }

    if ((sockfd = socket(serverinfo->ai_family, serverinfo->ai_socktype, serverinfo->ai_protocol)) == -1) {
        printf("Error: could not create socket\n");
        exit(1);
    }

    if (connect(sockfd, serverinfo->ai_addr, serverinfo->ai_addrlen) == -1) {
        printf("Error: could not connect to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter command: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
        if (bytes_sent == -1) {
            printf("Error: could not send command\n");
            exit(1);
        }
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            printf("Error: could not receive response\n");
            exit(1);
        }
        printf("Server response: %s", buffer);
    }

    close(sockfd);
    return 0;
}