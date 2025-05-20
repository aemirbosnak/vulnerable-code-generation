//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int client_socket = 0;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];
    int buffer_size = 0;
    int bytes_received = 0;

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    while (1) {
        memset(buffer, 0, MAX_BUFFER_SIZE);
        buffer_size = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);

        if (buffer_size <= 0) {
            printf("Disconnected from server\n");
            exit(1);
        }

        printf("Received message: %s\n", buffer);
        send(client_socket, buffer, strlen(buffer), 0);
    }

    close(client_socket);
    return 0;
}