//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int main() {

    int client_socket;
    struct sockaddr_in server_address;
    char buffer[MAX_BUFFER_SIZE];

    // Create TCP socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        printf("Error: Could not create socket\n");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    struct hostent* host_info = gethostbyname("www.google.com");
    memcpy(&server_address.sin_addr, host_info->h_addr_list[0], host_info->h_length);

    // Connect to server
    if (connect(client_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        printf("Error: Could not connect to server\n");
        exit(EXIT_FAILURE);
    }

    // Send HTTP GET request
    char* request = "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n";
    if (send(client_socket, request, strlen(request), 0) < 0) {
        printf("Error: Could not send HTTP GET request\n");
        exit(EXIT_FAILURE);
    }

    // Receive HTTP response
    int total_received = 0;
    int bytes_received;
    do {
        bytes_received = recv(client_socket, buffer, MAX_BUFFER_SIZE-1, 0);
        if (bytes_received < 0) {
            printf("Error: Could not receive data from server\n");
            exit(EXIT_FAILURE);
        }
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        total_received += bytes_received;
    } while (bytes_received > 0);

    // Close socket
    close(client_socket);

    return 0;
}