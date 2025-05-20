//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *server_address = "localhost";
    int server_port = 25;
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    if (argc == 3) {
        server_address = argv[1];
        server_port = atoi(argv[2]);
    }

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    if (inet_pton(AF_INET, server_address, &server_addr.sin_addr) <= 0) {
        printf("Invalid server address\n");
        exit(1);
    }

    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        printf("Enter message: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        if (send(client_socket, buffer, strlen(buffer), 0) == -1) {
            printf("Error sending message\n");
            exit(1);
        }

        bytes_read = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_read <= 0) {
            printf("Error receiving message\n");
            exit(1);
        }

        printf("Received message: %s", buffer);
    }

    close(client_socket);
    return 0;
}