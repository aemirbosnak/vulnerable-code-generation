//FormAI DATASET v1.0 Category: Chat server ; Style: immersive
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 5
#define MAX_NAME_LENGTH 20
#define MAX_MESSAGE_LENGTH 256

struct client {
    char name[MAX_NAME_LENGTH];
    int socket_fd;
};

static int client_count = 0;
static struct client clients[MAX_CLIENTS];

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *client_handler(void *arg) {
    int socket_fd = *((int *)arg);
    char name[MAX_NAME_LENGTH];
    char buffer[MAX_MESSAGE_LENGTH];

    recv(socket_fd, name, sizeof(name), 0);
    
    pthread_mutex_lock(&mutex);
    strcpy(clients[client_count].name, name);
    clients[client_count].socket_fd = socket_fd;
    client_count++;
    pthread_mutex_unlock(&mutex);

    while (1) {
        int bytes_received = recv(socket_fd, buffer, sizeof(buffer), 0);
        if (bytes_received < 1) {
            close(socket_fd);
            pthread_exit(NULL);
        }

        buffer[bytes_received] = '\0';
        printf("%s: %s", name, buffer);

        for (int i = 0; i < client_count; i++) {
            if (clients[i].socket_fd != socket_fd) {
                char message[MAX_MESSAGE_LENGTH + MAX_NAME_LENGTH + 2];
                snprintf(message, sizeof(message), "[%s]: %s", name, buffer);
                send(clients[i].socket_fd, message, strlen(message), 0);
            }
        }
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <port_number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);

    int server_fd;
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in address = {0};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int client_fd;
        if ((client_fd = accept(server_fd, NULL, NULL)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, client_handler, &client_fd) != 0) {
            perror("pthread_create failed");
            exit(EXIT_FAILURE);
        }

        pthread_detach(thread_id);
    }

    return 0;
}