//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 12345
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int addr_size, num_clients = 0;
    int *client_sockets;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        addr_size = sizeof(struct sockaddr_in);
        if ((new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size)) == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("New client connected with IP %s and port %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        if (num_clients == MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
            close(new_socket);
            continue;
        }

        client_sockets = (int *)realloc(client_sockets, sizeof(int) * (num_clients + 1));
        client_sockets[num_clients] = new_socket;
        num_clients++;
    }

    return 0;
}