//GEMINI-pro DATASET v1.0 Category: Networking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip address> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];
    int port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    while (1) {
        printf("Enter message: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strlen(buffer) - 1] = '\0';

        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            perror("send");
            return EXIT_FAILURE;
        }

        memset(buffer, 0, sizeof(buffer));

        if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
            perror("recv");
            return EXIT_FAILURE;
        }

        printf("Received message: %s\n", buffer);
    }

    close(sockfd);

    return EXIT_SUCCESS;
}