//FormAI DATASET v1.0 Category: Chat server ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 1024

typedef struct {
    char *name;
    int socket_fd;
    struct sockaddr_in client_addr;
    pthread_t thread_id;
} client_info;

client_info clients[MAX_CLIENTS];
int num_clients = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *client) {
    client_info *info = (client_info *) client;
    char msg[MAX_MSG_SIZE];
    int num_bytes;
    ssize_t ret;

    printf("Client %s connected\n", info->name);
    while ((num_bytes = recv(info->socket_fd, msg, MAX_MSG_SIZE - 1, 0)) > 0) {
        msg[num_bytes] = '\0';
        printf("[%s]: %s", info->name, msg);

        pthread_mutex_lock(&mutex);
        for (int i = 0; i < num_clients; i++) {
            if (clients[i].socket_fd != info->socket_fd) {
                ret = send(clients[i].socket_fd, msg, strlen(msg), 0);
                if (ret == -1) {
                    printf("Error sending message to client %s\n", clients[i].name);
                }
            }
        }
        pthread_mutex_unlock(&mutex);
    }

    close(info->socket_fd);

    pthread_mutex_lock(&mutex);
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].socket_fd == info->socket_fd) {
            printf("Removing client %s\n", clients[i].name);
            for (int j = i; j < num_clients - 1; j++) {
                clients[j] = clients[j + 1];
            }
            num_clients--;
            break;
        }
    }
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len;
    pthread_t thread_id;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) != 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_fd, 10) != 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server started on port %s\n", argv[1]);

    while (1) {
        if (num_clients == MAX_CLIENTS) {
            printf("Max number of clients reached\n");
            continue;
        }

        addr_len = sizeof(client_addr);
        client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &addr_len);
        if (client_fd == -1) {
            printf("Error accepting client connection\n");
            continue;
        }

        pthread_mutex_lock(&mutex);
        clients[num_clients].name = (char *) malloc(INET_ADDRSTRLEN * sizeof(char));
        inet_ntop(AF_INET, &(client_addr.sin_addr), clients[num_clients].name, INET_ADDRSTRLEN);
        clients[num_clients].socket_fd = client_fd;
        clients[num_clients].client_addr = client_addr;
        pthread_create(&clients[num_clients].thread_id, NULL, handle_client, &clients[num_clients]);
        num_clients++;
        pthread_mutex_unlock(&mutex);
    }

    return 0;
}