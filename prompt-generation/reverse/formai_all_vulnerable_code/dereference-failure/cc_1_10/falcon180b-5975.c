//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define SERVER_PORT 8080

int server_socket;
int client_sockets[MAX_CLIENTS];
int max_clients = 0;
sem_t mutex;

void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            close(client_socket);
            sem_post(&mutex);
            break;
        }
        send(client_socket, buffer, bytes_received, 0);
    }
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sem_init(&mutex, 0, MAX_CLIENTS - 1);

    while (1) {
        struct sockaddr_in server_addr, client_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(SERVER_PORT);
        server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

        bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
        listen(server_socket, 3);

        printf("Server is listening on port %d\n", SERVER_PORT);

        while (max_clients < MAX_CLIENTS) {
            socklen_t addr_size = sizeof(client_addr);
            int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size);

            if (client_socket < 0) {
                printf("Error accepting connection: %s\n", strerror(errno));
            } else {
                client_sockets[max_clients] = client_socket;
                max_clients++;
                printf("Client connected. Total clients: %d\n", max_clients);

                pthread_t thread_id;
                pthread_create(&thread_id, NULL, handle_client, (void *)&client_socket);
            }
        }

        sleep(1);
    }

    return 0;
}