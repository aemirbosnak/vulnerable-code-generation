//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct addrinfo *server_info;
    char buffer[MAX_BUFFER_SIZE];
    int bytes_received;
    char *command = "LIST\r\n";
    char *response;

    // Initialize the server info struct
    memset(&server_info, 0, sizeof(struct addrinfo));
    server_info->ai_family = AF_INET;
    server_info->ai_socktype = SOCK_STREAM;

    // Resolve the server address
    getaddrinfo("pop.gmail.com", "110", &server_info, NULL);

    // Create a socket
    sock = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);

    // Connect to the server
    connect(sock, server_info->ai_addr, server_info->ai_addrlen);

    // Send the command to the server
    send(sock, command, strlen(command), 0);

    // Receive the response from the server
    bytes_received = recv(sock, buffer, MAX_BUFFER_SIZE, 0);
    buffer[bytes_received] = '\0';

    // Print the response
    response = strstr(buffer, "+OK");
    if (response!= NULL) {
        printf("Response: %s\n", response);
    } else {
        printf("Error: Invalid response received\n");
    }

    // Close the socket
    close(sock);

    return 0;
}