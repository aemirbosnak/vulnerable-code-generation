//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 80

int main(int argc, char const *argv[]) {

    char *hostname = "www.example.com";
    char *message = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    struct hostent *he;
    struct sockaddr_in server_address;
    int socket_fd, bytes, response_length = 0;
    char buffer[2048];
    char *response = NULL;

    // Look up IP address of hostname
    if ((he = gethostbyname(hostname)) == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname.\n");
        return 1;
    }

    // Create socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Error: Could not create socket.\n");
        return 1;
    }

    // Set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr = *((struct in_addr *) he->h_addr);
    server_address.sin_port = htons(PORT);

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error: Could not connect to server.\n");
        return 1;
    }

    // Send HTTP request
    if (send(socket_fd, message, strlen(message), 0) < 0) {
        fprintf(stderr, "Error: Could not send message to server.\n");
        return 1;
    }

    // Receive HTTP response
    while ((bytes = recv(socket_fd, buffer, sizeof(buffer), 0)) > 0) {
        response_length += bytes;
        response = realloc(response, response_length);
        memcpy(response + response_length - bytes, buffer, bytes);
    }

    // Print HTTP response
    printf("HTTP Response:\n%s\n", response);

    // Clean up
    free(response);
    close(socket_fd);

    return 0;
}