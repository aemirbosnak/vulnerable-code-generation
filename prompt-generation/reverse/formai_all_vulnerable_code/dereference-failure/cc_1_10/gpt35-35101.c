//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define USER_AGENT "HTTPClient/1.0"

int main() {
    // Define the URL to make the GET request to
    char* url = "http://example.com";

    // Parse the URL into its components
    struct hostent* host = gethostbyname("example.com");
    char* ip = inet_ntoa(*(struct in_addr*)host->h_addr_list[0]);
    int port = 80;
    char* path = "/";

    // Create a socket for the HTTP connection
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    struct sockaddr_in server = {0};
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(port);
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) != 0) {
        perror("Failed to connect to server");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Build the HTTP request
    char request[1024];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\n"
        "Host: %s:%d\r\n"
        "User-Agent: %s\r\n"
        "Connection: close\r\n"
        "\r\n", path, url, port, USER_AGENT);

    // Send the HTTP request to the server
    if (send(sock, request, strlen(request), 0) == -1) {
        perror("Failed to send request");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Receive the HTTP response from the server
    char response[1024];
    int response_size = 0;
    int bytes_received;
    while ((bytes_received = recv(sock, response + response_size, sizeof(response) - response_size - 1, 0)) > 0) {
        response_size += bytes_received;
    }
    response[response_size] = '\0';

    // Find the start of the response body
    char* body_start = strstr(response, "\r\n\r\n") + 4;

    // Print the response body to the console
    printf("%s", body_start);

    // Close the socket
    close(sock);

    return 0;
}