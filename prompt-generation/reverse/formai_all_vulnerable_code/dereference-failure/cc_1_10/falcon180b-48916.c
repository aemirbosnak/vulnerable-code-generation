//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: scalable
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

void *handle_client(void *socket_desc) {
    char buffer[1024];
    int bytes_received;
    while (1) {
        bytes_received = recv(*((int *) socket_desc), buffer, 1024, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("Client %d sent: %s\n", *((int *) socket_desc), buffer);
        send(*((int *) socket_desc), buffer, strlen(buffer), 0);
    }
    close(*((int *) socket_desc));
    num_clients--;
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_socket, 3);

    printf("Server is listening on port %d\n", PORT);

    while (num_clients < MAX_CLIENTS) {
        int client_socket = accept(server_socket, NULL, NULL);
        printf("New client connected\n");
        client_sockets[num_clients] = client_socket;
        num_clients++;
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
    }

    while (1) {
        sleep(1);
    }

    return 0;
}