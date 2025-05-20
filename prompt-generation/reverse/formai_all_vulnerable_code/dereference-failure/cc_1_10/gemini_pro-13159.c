//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Get the server's IP address
    struct hostent *server = gethostbyname("www.example.com");
    if (server == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // Connect to the server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send the HTTP request
    const char *request = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive the HTTP response
    char response[4096];
    int n = recv(sockfd, response, sizeof(response), 0);
    if (n == -1) {
        perror("recv");
        exit(1);
    }

    // Print the HTTP response
    printf("%s", response);

    // Close the socket
    close(sockfd);

    return 0;
}