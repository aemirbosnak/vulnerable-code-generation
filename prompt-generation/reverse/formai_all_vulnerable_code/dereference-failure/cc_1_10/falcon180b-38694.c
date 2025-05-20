//Falcon-180B DATASET v1.0 Category: Networking ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int addrlen;
    char buffer[BUFFER_SIZE];
    int client_count = 0;

    if (argc!= 2) {
        printf("Usage:./server_program <port_number>\n");
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Could not bind socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error: Could not listen on socket\n");
        exit(1);
    }

    printf("Server is listening on port %d\n", atoi(argv[1]));

    addrlen = sizeof(client_addr);

    while (1) {
        if (client_count == MAX_CLIENTS) {
            printf("Maximum clients reached\n");
        } else {
            client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);
            if (client_socket == -1) {
                printf("Error: Could not accept connection\n");
                exit(1);
            }

            printf("Client connected: IP - %s, Port - %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

            client_count++;
        }

        memset(buffer, 0, BUFFER_SIZE);
        read(client_socket, buffer, BUFFER_SIZE);

        printf("Client message: %s\n", buffer);

        send(client_socket, buffer, strlen(buffer), 0);
    }

    close(server_socket);
    return 0;
}