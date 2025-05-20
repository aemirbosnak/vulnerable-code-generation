//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, valread;
    struct sockaddr_in serveraddr;
    char buffer[1024];

    if (argc!= 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        return 1;
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("bind failed");
        return 1;
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        return 1;
    }

    printf("Waiting for a connection...\n");

    if ((valread = accept(sockfd, NULL, NULL)) < 0) {
        perror("accept");
        return 1;
    }

    printf("Connection accepted!\n");

    memset(buffer, 0, sizeof(buffer));

    while ((valread = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        printf("Received: %s\n", buffer);

        memset(buffer, 0, sizeof(buffer));

        if (send(sockfd, argv[1], strlen(argv[1]), 0) < 0) {
            perror("send failed");
            return 1;
        }

        printf("Sent: %s\n", argv[1]);
    }

    close(sockfd);

    return 0;
}