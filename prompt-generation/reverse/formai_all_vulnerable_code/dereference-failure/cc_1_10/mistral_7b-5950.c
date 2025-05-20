//MISTRAL-7B DATASET v1.0 Category: Chat server ; Style: Donald Knuth
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

typedef struct {
    struct sockaddr_in addr;
    int sockfd;
} client_t;

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define RANDOM(x) (rand() % x)

int main() {
    srand(time(NULL));

    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    client_t *clients[MAX_CLIENTS] = {0};

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", PORT);

    while (true) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                 (socklen_t *)&addrlen))) {
            clients[RANDOM(MAX_CLIENTS)] = malloc(sizeof(client_t));
            clients[RANDOM(MAX_CLIENTS)]->sockfd = new_socket;
            clients[RANDOM(MAX_CLIENTS)]->addr = address;

            printf("New client connected: %s:%d\n",
                   inet_ntoa(clients[RANDOM(MAX_CLIENTS)]->addr.sin_addr),
                   ntohs(clients[RANDOM(MAX_CLIENTS)]->addr.sin_port));

            char buffer[BUFFER_SIZE];
            memset(buffer, '.', BUFFER_SIZE);
            buffer[BUFFER_SIZE - 1] = '\0';

            for (int i = 0; i < MAX_CLIENTS; ++i) {
                if (clients[i] && clients[i]->sockfd > 0) {
                    send(clients[i]->sockfd, buffer, strlen(buffer), 0);
                }
            }

            char msg[256];
            recv(new_socket, msg, sizeof(msg), 0);
            printf("Message from client %s:%d: %s\n",
                   inet_ntoa(clients[RANDOM(MAX_CLIENTS)]->addr.sin_addr),
                   ntohs(clients[RANDOM(MAX_CLIENTS)]->addr.sin_port), msg);

            free(clients[RANDOM(MAX_CLIENTS)]);
            close(new_socket);
        }
    }

    close(server_fd);
    return EXIT_SUCCESS;
}