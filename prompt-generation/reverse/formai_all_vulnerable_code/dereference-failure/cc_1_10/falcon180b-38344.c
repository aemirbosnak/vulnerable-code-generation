//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BACKLOG 10
#define MAX_REQUEST_SIZE 1024
#define MAX_CLIENTS 10
#define LIGHT_ON "light_on"
#define LIGHT_OFF "light_off"
#define LIGHT_STATUS "light_status"
#define LIGHT_STATUS_ON "light_status_on"
#define LIGHT_STATUS_OFF "light_status_off"

int clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    char request[MAX_REQUEST_SIZE];

    while (1) {
        memset(request, '\0', MAX_REQUEST_SIZE);
        int bytes_received = recv(client_socket, request, MAX_REQUEST_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("Received request: %s\n", request);

        if (strcmp(request, LIGHT_ON) == 0) {
            printf("Turning light on\n");
            // Code to turn on the light
        } else if (strcmp(request, LIGHT_OFF) == 0) {
            printf("Turning light off\n");
            // Code to turn off the light
        } else if (strcmp(request, LIGHT_STATUS) == 0) {
            printf("Sending light status\n");
            // Code to send the current status of the light
        }
    }

    close(client_socket);
    free(arg);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_socket, BACKLOG);

    printf("Server listening on port %d\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (num_clients >= MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
            close(client_socket);
            continue;
        }

        clients[num_clients] = client_socket;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
    }

    return 0;
}