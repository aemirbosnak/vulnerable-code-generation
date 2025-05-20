//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket, n;
    int yes = 1;
    struct sockaddr_in address;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE];
    int connection_count = 0;
    pid_t child_pid;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(atoi(argv[1]));

    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) == -1) {
        fprintf(stderr, "Error binding socket\n");
        exit(1);
    }

    listen(server_socket, MAX_CONNECTIONS);
    while (1) {
        client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            fprintf(stderr, "Error accepting connection\n");
            exit(1);
        }

        printf("New client connected, %d\n", connection_count);
        connection_count++;

        while (1) {
            n = read(client_socket, buffer, BUFFER_SIZE);
            if (n == 0) {
                printf("Client disconnected, %d\n", connection_count);
                close(client_socket);
                connection_count--;
                break;
            }

            printf("Received: %s\n", buffer);
            strcpy(message, buffer);
            write(client_socket, message, strlen(message));
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}