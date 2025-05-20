//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the host and port number from the command line arguments.
    char *host = argv[1];
    int port = atoi(argv[2]);

    // Create a socket for communicating with the server.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the IP address of the host.
    struct hostent *hostent = gethostbyname(host);
    if (hostent == NULL)
    {
        fprintf(stderr, "gethostbyname: %s\n", host);
        return EXIT_FAILURE;
    }

    // Create a sockaddr_in structure for the server's address.
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    memcpy(&servaddr.sin_addr, hostent->h_addr, hostent->h_length);

    // Connect to the server.
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1)
    {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Prepare the HTTP request.
    char request[MAX_BUFFER_SIZE];
    snprintf(request, MAX_BUFFER_SIZE, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", host);

    // Send the HTTP request to the server.
    if (send(sockfd, request, strlen(request), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the HTTP response from the server.
    char response[MAX_BUFFER_SIZE];
    int n;
    while ((n = recv(sockfd, response, MAX_BUFFER_SIZE, 0)) > 0)
    {
        // Write the HTTP response to stdout.
        fwrite(response, 1, n, stdout);
    }
    if (n == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}