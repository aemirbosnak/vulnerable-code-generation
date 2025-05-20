//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int client_socket, bytes_received;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;

    if (argc!= 3) {
        printf("Usage:./client <server_ip> <server_port>\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        if ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) == -1) {
            printf("Error receiving data\n");
            exit(1);
        }

        if (bytes_received == 0) {
            printf("Connection closed by server\n");
            break;
        }

        buffer[bytes_received] = '\0';
        printf("Received: %s", buffer);
    }

    close(client_socket);
    return 0;
}