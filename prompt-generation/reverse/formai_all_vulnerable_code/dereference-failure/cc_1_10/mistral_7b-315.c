//MISTRAL-7B DATASET v1.0 Category: Socket programming ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[])
{
    int sockfd, newsockfd, client_sockfd;
    struct sockaddr_in address, client_address;
    int opt = 1, addrlen = sizeof(struct sockaddr_in);
    char buffer[BUFFER_SIZE] = {0};

    if (argc != 2) {
        printf("Usage: ./server <port>\n");
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", ntohs(address.sin_port));

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&client_address, &addrlen);
        if (newsockfd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        client_sockfd = fork();
        if (client_sockfd < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (client_sockfd > 0) {
            close(newsockfd);
            continue;
        }

        read(newsockfd, buffer, BUFFER_SIZE);
        printf("Client message: %s\n", buffer);

        write(newsockfd, "Hello from server!\n", strlen("Hello from server!\n"));

        close(newsockfd);
        exit(EXIT_SUCCESS);
    }

    return 0;
}