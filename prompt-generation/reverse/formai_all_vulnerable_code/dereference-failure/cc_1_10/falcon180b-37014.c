//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 25
#define MAX_CLIENTS 10

struct client_data {
    int sock;
    struct sockaddr_in addr;
};

void *handle_client(void *arg) {
    struct client_data *client_data = (struct client_data *) arg;
    char buffer[1024];
    int n;

    while ((n = recv(client_data->sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0';
        printf("Client %s:%d said: %s\n", inet_ntoa(client_data->addr.sin_addr), ntohs(client_data->addr.sin_port), buffer);
    }

    close(client_data->sock);
    free(client_data);

    return NULL;
}

int main() {
    int server_sock, new_sock, addrlen;
    struct sockaddr_in server_addr, client_addr;
    pthread_t threads[MAX_CLIENTS];

    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        addrlen = sizeof(client_addr);
        if ((new_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addrlen)) == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        if (pthread_create(&threads[0], NULL, handle_client, (void *)&client_addr)!= 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}