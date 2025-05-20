//GEMINI-pro DATASET v1.0 Category: Networking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} client_t;

void* handle_client(void* arg) {
    client_t* client = (client_t*)arg;

    char buffer[1024];
    int n;

    while ((n = recv(client->sockfd, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0';
        printf("Received: %s\n", buffer);
        send(client->sockfd, buffer, n, 0);
    }

    if (n == 0) {
        printf("Client disconnected\n");
    } else {
        perror("recv");
    }

    close(client->sockfd);
    free(client);

    return NULL;
}

int main() {
    int sockfd, newsockfd, opt = 1;
    struct sockaddr_in addr, cliaddr;
    int addrlen = sizeof(addr);
    int n;
    pthread_t tid;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*)&addr, addrlen) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if ((newsockfd = accept(sockfd, (struct sockaddr*)&cliaddr, &addrlen)) == -1) {
            perror("accept");
            continue;
        }

        printf("New connection from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        client_t* client = malloc(sizeof(client_t));
        client->sockfd = newsockfd;
        client->addr = cliaddr;

        if (pthread_create(&tid, NULL, handle_client, client) != 0) {
            perror("pthread_create");
            close(newsockfd);
            free(client);
            continue;
        }
    }

    close(sockfd);

    return 0;
}