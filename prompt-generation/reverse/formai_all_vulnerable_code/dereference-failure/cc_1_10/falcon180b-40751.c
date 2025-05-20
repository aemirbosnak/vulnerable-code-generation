//Falcon-180B DATASET v1.0 Category: Chat server ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 12345
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS];
    int opt = 1;
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char *message;
    int message_len;
    int client_count = 0;

    message = malloc(BUFFER_SIZE);
    if (message == NULL) {
        printf("Error: failed to allocate memory\n");
        exit(1);
    }

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error: failed to create socket\n");
        exit(1);
    }

    // Set options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        printf("Error: failed to set socket options\n");
        exit(1);
    }

    // Bind socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: failed to bind socket\n");
        exit(1);
    }

    // Listen for connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        printf("Error: failed to listen on socket\n");
        exit(1);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        // Accept new connections
        int new_socket = accept(server_socket, (struct sockaddr *)&client_addr[client_count], sizeof(client_addr[client_count]));

        if (new_socket == -1) {
            printf("Error: failed to accept connection\n");
            exit(1);
        }

        printf("New client connected on socket %d\n", new_socket);
        client_socket[client_count] = new_socket;
        client_count++;
    }

    return 0;
}