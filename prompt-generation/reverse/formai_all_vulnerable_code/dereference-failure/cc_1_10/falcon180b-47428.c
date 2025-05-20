//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: shape shifting
/* Smart Home Light Control Example Program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *client_socket) {
    char buffer[BUFFER_SIZE];
    int client_socket_copy = *((int *) client_socket);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket_copy, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("Client %d: %s\n", client_socket_copy, buffer);

        // Parse command and control light
        char *command = strtok(buffer, " ");
        if (strcmp(command, "on") == 0) {
            // Turn on light
        } else if (strcmp(command, "off") == 0) {
            // Turn off light
        } else if (strcmp(command, "dim") == 0) {
            // Dim light
        } else {
            // Invalid command
        }
    }

    close(client_socket_copy);
    printf("Client %d disconnected\n", client_socket_copy);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server listening on port 8080\n");

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket!= -1) {
            clients[num_clients] = client_socket;
            num_clients++;
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, (void *) &clients[num_clients - 1]);
        }
    }

    return 0;
}