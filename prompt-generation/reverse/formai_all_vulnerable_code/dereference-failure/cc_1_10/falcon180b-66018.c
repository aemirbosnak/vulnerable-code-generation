//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int client_socket;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: Invalid IP address\n");
        exit(2);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr = *(struct in_addr *)server->h_addr;

    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error: Socket creation failed\n");
        exit(3);
    }

    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Connection failed\n");
        exit(4);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        printf("Enter message: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        bytes_received = send(client_socket, buffer, strlen(buffer), 0);
        if (bytes_received <= 0) {
            printf("Error: Message sending failed\n");
            exit(5);
        }

        memset(buffer, 0, BUFFER_SIZE);
        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error: Message receiving failed\n");
            exit(6);
        }
        printf("Received message: %s", buffer);
    }

    close(client_socket);
    return 0;
}