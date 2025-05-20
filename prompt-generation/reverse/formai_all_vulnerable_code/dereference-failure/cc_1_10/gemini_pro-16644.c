//GEMINI-pro DATASET v1.0 Category: Networking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_BUFFER_SIZE 1024

typedef struct {
    int fd;
    struct sockaddr_in addr;
} client_info;

client_info clients[MAX_CLIENTS];
int num_clients;

pthread_mutex_t mutex;

void *handle_client(void *arg) {
    client_info *client = (client_info *)arg;
    char buffer[MAX_BUFFER_SIZE];
    int n;
    while (1) {
        n = recv(client->fd, buffer, sizeof(buffer), 0);
        if (n <= 0) {
            if (n == 0) {
                printf("Client %s disconnected\n", inet_ntoa(client->addr.sin_addr));
            } else {
                perror("recv");
            }
            pthread_mutex_lock(&mutex);
            for (int i = 0; i < num_clients; i++) {
                if (clients[i].fd == client->fd) {
                    clients[i] = clients[num_clients - 1];
                    num_clients--;
                    break;
                }
            }
            pthread_mutex_unlock(&mutex);
            free(client);
            return NULL;
        }
        buffer[n] = '\0';
        printf("Client %s: %s\n", inet_ntoa(client->addr.sin_addr), buffer);
        pthread_mutex_lock(&mutex);
        for (int i = 0; i < num_clients; i++) {
            if (clients[i].fd != client->fd) {
                send(clients[i].fd, buffer, n, 0);
            }
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    int server_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    pthread_t threads[MAX_CLIENTS];
    socklen_t client_addr_len;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    if (listen(server_fd, MAX_CLIENTS) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    pthread_mutex_init(&mutex, NULL);

    while (1) {
        client_addr_len = sizeof(client_addr);
        conn_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (conn_fd == -1) {
            if (errno == EINTR) {
                continue;
            }
            perror("accept");
            return EXIT_FAILURE;
        }
        printf("Client %s connected\n", inet_ntoa(client_addr.sin_addr));
        pthread_mutex_lock(&mutex);
        if (num_clients < MAX_CLIENTS) {
            clients[num_clients].fd = conn_fd;
            clients[num_clients].addr = client_addr;
            num_clients++;
            pthread_create(&threads[num_clients - 1], NULL, handle_client, &clients[num_clients - 1]);
        } else {
            send(conn_fd, "Server is full\n", 15, 0);
            close(conn_fd);
        }
        pthread_mutex_unlock(&mutex);
    }

    pthread_mutex_destroy(&mutex);
    close(server_fd);

    return EXIT_SUCCESS;
}