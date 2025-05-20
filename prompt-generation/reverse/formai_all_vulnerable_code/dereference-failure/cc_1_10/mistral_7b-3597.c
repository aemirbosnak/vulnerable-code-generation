//MISTRAL-7B DATASET v1.0 Category: Chat server ; Style: minimalist
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 4444
#define BUFFER_SIZE 1024

bool setup_socket(int *sockfd) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) {
        perror("socket creation failed");
        return false;
    }

    if (bind(*sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("binding failed");
        close(*sockfd);
        return false;
    }

    if (listen(*sockfd, 10) < 0) {
        perror("listen failed");
        close(*sockfd);
        return false;
    }

    return true;
}

int main() {
    int sockfd, newsockfd, client_addr_len;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in client_addr;

    if (!setup_socket(&sockfd)) {
        free(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    while (true) {
        client_addr_len = sizeof(struct sockaddr_in);
        newsockfd = accept(sockfd, NULL, &client_addr_len);
        if (newsockfd < 0) {
            perror("accept failed");
            continue;
        }

        printf("Client connected: %s:%d\n",
               inet_ntoa(client_addr.sin_addr),
               ntohs(client_addr.sin_port));

        while (true) {
            memset(buffer, 0, BUFFER_SIZE);
            ssize_t bytes_received = recv(newsockfd, buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0) {
                if (bytes_received < 0) {
                    perror("recv failed");
                }
                break;
            }

            printf("Message received: %s\n", buffer);

            fputs(buffer, stdout);

            ssize_t bytes_sent = send(newsockfd, buffer, strlen(buffer), 0);
            if (bytes_sent < 0) {
                perror("send failed");
                break;
            }

            if (strcmp(buffer, "quit") == 0) {
                printf("Client disconnected\n");
                close(newsockfd);
                break;
            }
        }
    }

    close(sockfd);
    return EXIT_SUCCESS;
}