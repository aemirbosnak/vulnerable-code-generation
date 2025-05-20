//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define SERVER_PORT 12345
#define MAX_CLIENTS 10
#define MAX_THREADS 10

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;
pthread_t threads[MAX_THREADS];

void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[1024];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            close(client_socket);
            pthread_exit(NULL);
        }
        printf("Client %d: %s\n", client_socket, buffer);
    }
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    while (num_clients < MAX_CLIENTS) {
        struct sockaddr_in client_addr;
        socklen_t addr_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &addr_size);
        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }
        client_sockets[num_clients] = client_socket;
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
        num_clients++;
    }

    while (1) {
        sleep(1);
    }

    return 0;
}