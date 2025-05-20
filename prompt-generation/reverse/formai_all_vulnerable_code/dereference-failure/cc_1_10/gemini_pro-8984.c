//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_LINE 1024

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    // Get the hostname and port from the command line arguments.
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create a socket for connecting to the server.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Get the IP address of the server.
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // Create the address structure for the server.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to the server.
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send an HTTP request to the server.
    char *request = "GET / HTTP/1.1\nHost: www.example.com\n\n";
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive the HTTP response from the server.
    char response[MAX_LINE];
    int nbytes;
    while ((nbytes = recv(sockfd, response, MAX_LINE, 0)) > 0) {
        printf("%s", response);
    }

    if (nbytes == -1) {
        perror("recv");
        exit(1);
    }

    // Close the socket.
    close(sockfd);

    return 0;
}