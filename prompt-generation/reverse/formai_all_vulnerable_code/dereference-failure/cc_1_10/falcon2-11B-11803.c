//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int server_socket, port_number;
    struct sockaddr_in server_address;
    char buffer[1024];

    if (argc!= 2) {
        printf("Usage: %s <port_number>\n", argv[0]);
        return 1;
    }

    port_number = atoi(argv[1]);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation error");
        return 1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port_number);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Binding error");
        return 1;
    }

    listen(server_socket, 5);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("Accept error");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(server_address.sin_addr), ntohs(server_address.sin_port));

        char *request = NULL;
        int request_length = 0;

        request_length = recv(client_socket, buffer, 1024, 0);
        if (request_length <= 0) {
            perror("Receive error");
            close(client_socket);
            continue;
        }

        request = malloc(request_length + 1);
        if (request == NULL) {
            perror("Memory allocation error");
            close(client_socket);
            continue;
        }

        memcpy(request, buffer, request_length);
        request[request_length] = '\0';

        printf("Request: %s\n", request);

        // Handle the request and send the response back to the client

        free(request);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}