//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define PORT 8080
#define BACKLOG 10

int clients[MAX_CLIENTS][2];
int num_clients = 0;

void *handle_client(void *arg) {
    int client_socket = *(int *) arg;

    char buffer[1024];
    while(1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);

        if(bytes_received <= 0) {
            close(client_socket);
            break;
        }

        printf("Client %d sent message: %s\n", client_socket, buffer);

        for(int i = 0; i < num_clients; i++) {
            if(clients[i][0]!= client_socket) {
                send(clients[i][0], buffer, strlen(buffer), 0);
            }
        }
    }

    return NULL;
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));

    listen(server_socket, BACKLOG);

    printf("Server listening on port %d\n", PORT);

    while(1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if(client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        printf("Client %d connected\n", client_socket);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);

        if(num_clients >= MAX_CLIENTS) {
            close(client_socket);
            printf("Maximum number of clients reached\n");
        } else {
            clients[num_clients][0] = client_socket;
            clients[num_clients][1] = thread_id;
            num_clients++;
        }
    }

    return 0;
}