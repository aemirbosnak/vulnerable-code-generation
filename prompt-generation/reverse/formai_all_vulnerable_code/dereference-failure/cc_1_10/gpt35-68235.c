//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER 1024

int main(int argc, char **argv) {
    char *host = "example.com";
    char *path = "/";
    char *http_version = "HTTP/1.1";

    // Resolve the hostname
    struct hostent *hostent = gethostbyname(host);

    if (!hostent) {
        printf("Error: Could not resolve host %s\n", host);
        return 1;
    }

    // Create the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    // Set up the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr, hostent->h_addr, hostent->h_length);
    server_addr.sin_port = htons(80);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Could not connect to server\n");
        return 1;
    }

    // Form the request message
    char *request_message_template = "GET %s %s\r\n"
                                      "Host: %s\r\n"
                                      "Connection: close\r\n"
                                      "\r\n";

    int request_message_length = strlen(request_message_template) + strlen(path) + strlen(http_version) + strlen(host);

    char *request_message = malloc(request_message_length + 1);
    sprintf(request_message, request_message_template, path, http_version, host);

    // Send the request message
    if (send(sockfd, request_message, strlen(request_message), 0) < 0) {
        printf("Error: Could not send request message\n");
        return 1;
    }

    // Receive the response message
    char buffer[MAX_BUFFER];
    int bytes_received;
    while ((bytes_received = recv(sockfd, buffer, MAX_BUFFER - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    if (bytes_received < 0) {
        printf("Error: Could not receive response message\n");
        return 1;
    }

    // Close the socket
    close(sockfd);

    // Free the memory
    free(request_message);

    return 0;
}