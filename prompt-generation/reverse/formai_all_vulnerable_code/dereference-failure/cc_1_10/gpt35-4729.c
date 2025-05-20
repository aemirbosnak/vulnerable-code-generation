//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#define PORT 80
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int socket_fd, bytes_received;
    struct hostent *server_ip;
    struct sockaddr_in server_address;
    char message[MAX_BUFFER_SIZE], request[MAX_BUFFER_SIZE], response[MAX_BUFFER_SIZE];
    bool message_sent = false;

    // Check if URL is provided as input argument
    if (argc != 2) {
        printf("Please provide a URL to connect to.\n");
        return 1;
    }

    // Get IP address of the server
    server_ip = gethostbyname(argv[1]);
    if (server_ip == NULL) {
        printf("Could not resolve server IP address.\n");
        return 1;
    }

    // Create socket and specify protocol family, type and protocol
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        printf("Failed to create socket.\n");
        return 1;
    }

    // Assign the server address and port number to the socket
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = ((struct in_addr *)(server_ip->h_addr_list[0]))->s_addr;
    server_address.sin_port = htons(PORT);

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Failed to connect to server.\n");
        return 1;
    }

    // Prepare HTTP GET request
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    printf("Sending HTTP GET request:\n%s", request);

    // Send request to server
    if (send(socket_fd, request, strlen(request), 0) < 0) {
        printf("Failed to send message to server.\n");
        return 1;
    }
    message_sent = true;

    // Receive response from server
    bytes_received = recv(socket_fd, response, MAX_BUFFER_SIZE - 1, 0);
    response[bytes_received] = '\0';

    // Check if response was received
    if (bytes_received < 0) {
        printf("Failed to receive message from server.\n");
        return 1;
    }

    // Print response from server
    printf("Received response from server:\n%s", response);

    // Close socket
    close(socket_fd);
    
    return 0;
}