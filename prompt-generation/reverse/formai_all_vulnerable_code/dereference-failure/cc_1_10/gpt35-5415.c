//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <server_address> <port>\n", argv[0]);
        return 1;
    }

    char* server_address = argv[1];
    int port = atoi(argv[2]);

    // Create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Connect to server
    struct sockaddr_in server_address_info;
    memset(&server_address_info, 0, sizeof(server_address_info));
    server_address_info.sin_family = AF_INET;
    server_address_info.sin_addr.s_addr = inet_addr(server_address);
    server_address_info.sin_port = htons(port);

    if (connect(client_socket, (struct sockaddr*) &server_address_info, sizeof(server_address_info)) == -1) {
        printf("Error connecting to server\n");
        close(client_socket);
        return 1;
    }

    // Send IMAP message
    char buffer[BUFFER_SIZE];
    char* message = "tag001 LOGIN username password\n";
    memset(buffer, 0, BUFFER_SIZE);
    strcpy(buffer, message);
    send(client_socket, buffer, strlen(buffer), 0);

    // Receive response
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    printf("%s", buffer);

    // Send another IMAP message
    message = "tag002 SELECT inbox\n";
    memset(buffer, 0, BUFFER_SIZE);
    strcpy(buffer, message);
    send(client_socket, buffer, strlen(buffer), 0);

    // Receive response
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    printf("%s", buffer);

    // Close socket
    close(client_socket);

    return 0;
}