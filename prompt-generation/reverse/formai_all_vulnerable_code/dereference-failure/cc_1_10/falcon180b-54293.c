//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server_address.sin_addr);
    server_address.sin_port = htons(port_number);

    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        close(client_socket);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received == 0) {
            fprintf(stderr, "Server closed the connection\n");
            close(client_socket);
            exit(1);
        } else if (bytes_received == -1) {
            fprintf(stderr, "Error receiving data: %s\n", strerror(errno));
            close(client_socket);
            exit(1);
        }

        printf("Received from server: %s\n", buffer);
    }

    close(client_socket);
    return 0;
}