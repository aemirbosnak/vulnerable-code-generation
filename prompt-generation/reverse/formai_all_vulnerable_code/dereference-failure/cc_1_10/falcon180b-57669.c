//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    struct addrinfo hints, *result;
    int sockfd;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    char command[BUFFER_SIZE];
    char *ptr;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo("example.com", "21", &hints, &result)!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
        exit(1);
    }

    sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

    if (sockfd == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        exit(1);
    }

    printf("Connected to FTP server.\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        memset(command, 0, BUFFER_SIZE);

        printf("Enter command: ");
        fgets(command, BUFFER_SIZE, stdin);

        send(sockfd, command, strlen(command), 0);

        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        buffer[bytes_received] = '\0';
        printf("Server response: %s\n", buffer);
    }

    close(sockfd);

    return 0;
}