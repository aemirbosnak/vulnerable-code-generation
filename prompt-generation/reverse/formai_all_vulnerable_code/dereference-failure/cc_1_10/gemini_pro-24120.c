//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {

    // Set the hostname of the server you wish to commune with
    char* hostname = "example.com";

    // Perform a DNS lookup to obtain the server's IP address
    struct hostent* host = gethostbyname(hostname);
    if (!host) {
        perror("gethostbyname");
        exit(1);
    }

    // Create a socket to connect to the server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Specify the server's address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr = *(struct in_addr*)host->h_addr;

    // Initiate the connection to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Craft a HTTP request
    char* request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";

    // Send the request to the server
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Prepare to receive the server's response
    char buffer[1024];
    int bytes_received;

    // Read the server's response
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        // Display the server's response
        printf("%s", buffer);
    }

    // Close the connection to the server
    close(sockfd);

    return 0;
}