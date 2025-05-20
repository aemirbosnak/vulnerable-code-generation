//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10

struct client {
    int sock;
    struct sockaddr_in addr;
};

void *thread(void *arg) {
    struct client *client = (struct client *) arg;
    char buffer[1024];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes = recv(client->sock, buffer, sizeof(buffer), 0);
        if (bytes <= 0) {
            close(client->sock);
            free(client);
            return NULL;
        }
        printf("Client %s:%d sent: %s\n", inet_ntoa(client->addr.sin_addr), ntohs(client->addr.sin_port), buffer);
        send(client->sock, buffer, strlen(buffer), 0);
    }
}

int main() {
    int listen_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    int opt = TRUE;
    int addrlen = sizeof(client_addr);

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, (char *) &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_sock, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        client_sock = accept(listen_sock, (struct sockaddr *) &client_addr, &addrlen);
        if (client_sock < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        struct client *client = (struct client *) malloc(sizeof(struct client));
        client->sock = client_sock;
        memcpy(&client->addr, &client_addr, sizeof(client_addr));

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, thread, (void *) client);
    }

    return 0;
}