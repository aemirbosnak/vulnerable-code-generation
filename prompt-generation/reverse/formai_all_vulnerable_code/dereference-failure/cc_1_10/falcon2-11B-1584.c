//Falcon2-11B DATASET v1.0 Category: Networking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

#define PORT 8080

int main() {
    int sockfd, connfd;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    char buffer[1024];

    server = gethostbyname("localhost");
    if (server == NULL) {
        printf("Error: Could not resolve hostname\n");
        return 1;
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    memcpy((char *)&serveraddr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        printf("Error: Could not connect to server\n");
        return 1;
    }

    printf("Connected to server\n");

    while (1) {
        bzero(buffer, sizeof(buffer));
        if (read(sockfd, buffer, sizeof(buffer)) <= 0) {
            printf("Error: Could not read from socket\n");
            return 1;
        }
        printf("Received: %s\n", buffer);
        printf("Enter a message: ");
        bzero(buffer, sizeof(buffer));
        fgets(buffer, sizeof(buffer), stdin);
        if (write(sockfd, buffer, strlen(buffer)) < 0) {
            printf("Error: Could not write to socket\n");
            return 1;
        }
        printf("Sent: %s\n", buffer);
    }

    return 0;
}