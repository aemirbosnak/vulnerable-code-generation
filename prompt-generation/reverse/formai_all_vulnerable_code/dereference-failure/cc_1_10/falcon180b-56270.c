//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_REQUEST_SIZE 1024

void handle_request(int client_socket) {
    char request[MAX_REQUEST_SIZE];
    memset(request, 0, MAX_REQUEST_SIZE);
    int bytes_received = recv(client_socket, request, MAX_REQUEST_SIZE, 0);

    if (bytes_received <= 0) {
        close(client_socket);
        return;
    }

    char *method = strtok(request, " ");
    char *path = strtok(NULL, " ");

    if (strcmp(method, "GET") == 0) {
        FILE *file = fopen(path, "r");

        if (file == NULL) {
            send(client_socket, "404 Not Found", strlen("404 Not Found"), 0);
        } else {
            char buffer[1024];
            while (fgets(buffer, sizeof(buffer), file)!= NULL) {
                send(client_socket, buffer, strlen(buffer), 0);
            }
            fclose(file);
        }
    } else {
        send(client_socket, "405 Method Not Allowed", strlen("405 Method Not Allowed"), 0);
    }

    close(client_socket);
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
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Client connected\n");
        handle_request(client_socket);
    }

    close(server_socket);
    return 0;
}