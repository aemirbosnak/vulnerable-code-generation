//FormAI DATASET v1.0 Category: Chat server ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

#define MAX_CLIENTS 5

int server_fd;
int clients_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int client_socket[MAX_CLIENTS];
struct sockaddr_in server_addr, client_addr;
char *welcome_message = "Welcome to the chat room!\n";
char buffer[1024];

void cleanup() {
    close(server_fd);
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (client_socket[i]) {
            close(client_socket[i]);
        }
    }
}

void handle_sigint(int sig) {
    printf("Caught signal: %d\n", sig);
    cleanup();
    exit(0);
}

void *client_handler(void *arg) {
    int index = *(int *) arg;
    printf("Starting client handler thread for socket: %d\n", client_socket[index]);
    write(client_socket[index], welcome_message, strlen(welcome_message));
    while (1) {
        // receive message from client
        int read_bytes = read(client_socket[index], buffer, sizeof(buffer));
        if (read_bytes == 0) {
            // client disconnected
            printf("Client disconnected: %d\n", client_socket[index]);
            pthread_mutex_lock(&mutex);
            client_socket[index] = 0;
            clients_count--;
            pthread_mutex_unlock(&mutex);
            break;
        }
        // broadcast message to all other clients
        pthread_mutex_lock(&mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_socket[i] && i != index) {
                write(client_socket[i], buffer, read_bytes);
            }
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [port]\n", argv[0]);
        return 1;
    }

    // setup signal handler
    signal(SIGINT, handle_sigint);

    // create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Failed to create socket\n");
        return 1;
    }

    // configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    // bind socket to address
    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to bind socket to address\n");
        return 1;
    }

    // listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        printf("Failed to listen for incoming connections\n");
        return 1;
    }

    printf("Server started on port %d\n", atoi(argv[1]));

    // accept incoming connections
    while (1) {
        int client_fd;
        int client_addr_len = sizeof(client_addr);
        if ((client_fd = accept(server_fd, (struct sockaddr *) &client_addr, (socklen_t *) &client_addr_len)) < 0) {
            printf("Failed to accept incoming connection\n");
            return 1;
        }
        // add client to list
        pthread_mutex_lock(&mutex);
        if (clients_count >= MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
            close(client_fd);
        } else {
            int i = 0;
            for (i = 0; i < MAX_CLIENTS; i++) {
                if (client_socket[i] == 0) {
                    client_socket[i] = client_fd;
                    clients_count++;
                    pthread_t tid;
                    pthread_create(&tid, NULL, client_handler, &i);
                    break;
                }
            }
        }
        pthread_mutex_unlock(&mutex);
    }

    cleanup();
    return 0;
}