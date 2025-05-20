//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_LINE 1024

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s <server> <port> <email>\n", argv[0]);
        exit(1);
    }

    char *server = argv[1];
    char *port = argv[2];
    char *email = argv[3];

    // Get the server's IP address
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(server, port, &hints, &res) != 0)
    {
        fprintf(stderr, "Error: could not get server's IP address\n");
        exit(1);
    }

    // Create a socket
    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1)
    {
        fprintf(stderr, "Error: could not create socket\n");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1)
    {
        fprintf(stderr, "Error: could not connect to server\n");
        exit(1);
    }

    freeaddrinfo(res);

    // Send the email
    char buffer[MAX_LINE];
    sprintf(buffer, "MAIL FROM: <%s>\n", email);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1)
    {
        fprintf(stderr, "Error: could not send email\n");
        exit(1);
    }

    // Wait for the server to respond
    if (recv(sockfd, buffer, MAX_LINE, 0) == -1)
    {
        fprintf(stderr, "Error: could not receive response from server\n");
        exit(1);
    }

    // Check the server's response
    if (strncmp(buffer, "250 OK", 6) != 0)
    {
        fprintf(stderr, "Error: server did not accept email\n");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}