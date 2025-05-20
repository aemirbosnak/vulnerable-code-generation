//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

// Define the HTTP request header
#define HTTP_REQUEST "GET /index.html HTTP/1.1\r\nHost: www.example.com\r\n\r\n"

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Get the IP address of the server
    struct hostent *host = gethostbyname("www.example.com");
    if (host == NULL) {
        perror("gethostbyname");
        return 1;
    }

    // Create the server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    memcpy(&serv_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send the HTTP request
    if (send(sockfd, HTTP_REQUEST, strlen(HTTP_REQUEST), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the HTTP response
    char buffer[4096];
    int bytes_received;
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        // Print the HTTP response
        fwrite(buffer, 1, bytes_received, stdout);
    }
    if (bytes_received == -1) {
        perror("recv");
        return 1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}