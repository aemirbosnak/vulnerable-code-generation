//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define ERR_EXIT(m) do { perror(m); exit(EXIT_FAILURE); } while(0)

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    char port[6];
    strcpy(port, "80");

    // Resolve the hostname to an IPv4 address
    struct hostent *host = gethostbyname(hostname);
    if (!host) {
        herror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        ERR_EXIT("socket");

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        ERR_EXIT("connect");

    // Send an HTTP GET request
    char request[1024];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", hostname);

    if (send(sockfd, request, strlen(request), 0) == -1)
        ERR_EXIT("send");

    // Receive the HTTP response
    char response[4096];
    int n = recv(sockfd, response, sizeof(response), 0);
    if (n == -1)
        ERR_EXIT("recv");

    // Print the HTTP response
    printf("%s", response);

    // Close the socket
    close(sockfd);

    return 0;
}