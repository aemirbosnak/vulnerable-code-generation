//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main() {
    // Define the target host and port
    const char *host = "example.com";
    int port = 80;

    // Create a socket for the client
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket() failed");
        return EXIT_FAILURE;
    }

    // Resolve the host name to an IP address
    struct hostent *host_entry = gethostbyname(host);
    if (host_entry == NULL) {
        perror("gethostbyname() failed");
        return EXIT_FAILURE;
    }

    // Create the server address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *(struct in_addr *)host_entry->h_addr_list[0];

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect() failed");
        return EXIT_FAILURE;
    }

    // Send an HTTP GET request to the server
    const char *request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send() failed");
        return EXIT_FAILURE;
    }

    // Receive the HTTP response from the server
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("recv() failed");
        return EXIT_FAILURE;
    }

    // Print the HTTP response to the console
    printf("%s", buffer);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}