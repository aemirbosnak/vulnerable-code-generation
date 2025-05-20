//GEMINI-pro DATASET v1.0 Category: Networking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} client_t;

void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[1024];
    int len;

    while ((len = recv(client->sockfd, buffer, sizeof(buffer), 0)) > 0) {
        buffer[len] = '\0';
        printf("Received: %s\n", buffer);
        send(client->sockfd, buffer, len, 0);
    }

    close(client->sockfd);
    free(client);

    return NULL;
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    pthread_t tid;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return EXIT_FAILURE;
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        return EXIT_FAILURE;
    }

    while (1) {
        client_addr_len = sizeof(client_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (newsockfd < 0) {
            perror("accept");
            continue;
        }

        client_t *client = malloc(sizeof(client_t));
        client->sockfd = newsockfd;
        client->addr = client_addr;

        pthread_create(&tid, NULL, handle_client, (void *)client);
    }

    close(sockfd);

    return EXIT_SUCCESS;
}