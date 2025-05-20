//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server address> <server port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server_address = argv[1];
    int server_port = atoi(argv[2]);

    // Create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("socket()");
        exit(EXIT_FAILURE);
    }

    // Get server info
    struct hostent *server = gethostbyname(server_address);
    if (server == NULL) {
        fprintf(stderr, "Unable to find server \"%s\"\n", server_address);
        exit(EXIT_FAILURE);
    }

    // Setup server address struct
    struct sockaddr_in server_address_struct;
    memset(&server_address_struct, 0, sizeof(server_address_struct));
    server_address_struct.sin_family = AF_INET;
    server_address_struct.sin_port = htons(server_port);
    memcpy(&server_address_struct.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address_struct, sizeof(server_address_struct)) == -1) {
        perror("connect()");
        exit(EXIT_FAILURE);
    }

    // HTTP request
    const char *request_message = "GET / HTTP/1.1\r\nHost: %s:%d\r\nUser-Agent: Mozilla/5.0\r\nAccept: */*\r\nConnection: close\r\n\r\n";
    char request[BUFFER_SIZE];
    int request_length = snprintf(request, BUFFER_SIZE, request_message, server_address, server_port);

    // Send HTTP request
    if (send(client_socket, request, request_length, 0) == -1) {
        perror("send()");
        exit(EXIT_FAILURE);
    }

    // Receive HTTP response
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received == -1) {
        perror("recv()");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';

    // Print HTTP response
    printf("%s\n", buffer);

    // Close socket
    close(client_socket);

    return 0;
}