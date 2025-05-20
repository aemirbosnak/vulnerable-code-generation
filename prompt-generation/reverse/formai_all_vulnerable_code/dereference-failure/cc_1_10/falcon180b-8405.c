//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct addrinfo *serverinfo;
    struct addrinfo hints;
    char buffer[BUFFER_SIZE];
    int bytesread;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo("www.google.com", "80", &hints, &serverinfo)!= 0) {
        printf("Failed to get server information\n");
        exit(1);
    }

    sockfd = socket(serverinfo->ai_family, serverinfo->ai_socktype, serverinfo->ai_protocol);

    if (connect(sockfd, serverinfo->ai_addr, serverinfo->ai_addrlen)!= 0) {
        printf("Failed to connect to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        bytesread = read(sockfd, buffer, BUFFER_SIZE);

        if (bytesread <= 0) {
            printf("Disconnected from server\n");
            break;
        }

        printf("Received from server: %s", buffer);
    }

    close(sockfd);
    return 0;
}