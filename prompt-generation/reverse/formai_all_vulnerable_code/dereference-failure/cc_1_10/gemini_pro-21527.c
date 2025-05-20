//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Resolve the hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send the HTTP request
    char request[] = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the HTTP response
    char buffer[4096];
    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        printf("%s", buffer);
    }
    if (bytes_received == -1) {
        perror("recv");
        return 1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}