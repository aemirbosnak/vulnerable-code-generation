//Falcon-180B DATASET v1.0 Category: Chat server ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int addrlen = sizeof(client_addr);
    int opt = 1;

    if (argc!= 2) {
        printf("Usage:./chat_server <port_number>\n");
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, 10) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port %s...\n", argv[1]);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Client connected with IP address %s and port %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            if (recv(client_socket, buffer, BUFFER_SIZE, 0) <= 0) {
                printf("Client disconnected\n");
                break;
            }

            printf("Received message from client: %s\n", buffer);

            send(client_socket, buffer, strlen(buffer), 0);
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}