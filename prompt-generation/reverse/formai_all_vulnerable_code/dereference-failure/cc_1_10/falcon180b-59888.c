//Falcon-180B DATASET v1.0 Category: Chat server ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define PORT 8080

int client_sockets[MAX_CLIENTS];
int num_clients = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* handle_client(void* arg) {
    int client_socket = *(int*)arg;

    char buffer[1024];
    while(1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if(bytes_received <= 0) {
            break;
        }

        pthread_mutex_lock(&mutex);
        for(int i = 0; i < num_clients; i++) {
            if(client_sockets[i]!= client_socket) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
        pthread_mutex_unlock(&mutex);
    }

    close(client_socket);
    free(arg);
    return NULL;
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_socket, MAX_CLIENTS);

    printf("Server started on port %d\n", PORT);

    while(1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if(client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        pthread_t thread_id;
        int* client_socket_ptr = malloc(sizeof(int));
        *client_socket_ptr = client_socket;

        pthread_create(&thread_id, NULL, handle_client, client_socket_ptr);

        pthread_mutex_lock(&mutex);
        client_sockets[num_clients] = client_socket;
        num_clients++;
        pthread_mutex_unlock(&mutex);
    }

    return 0;
}