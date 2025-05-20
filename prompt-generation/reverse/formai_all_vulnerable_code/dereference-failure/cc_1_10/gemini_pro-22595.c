//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    // Check if the user provided the necessary arguments.
    if (argc < 4) {
        printf("Usage: %s <server> <port> <email>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the server name and port number from the command line.
    char *server = argv[1];
    int port = atoi(argv[2]);

    // Get the email address from the command line.
    char *email = argv[3];

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Resolve the server's address.
    struct hostent *host = gethostbyname(server);
    if (!host) {
        fprintf(stderr, "Error resolving hostname %s\n", server);
        exit(EXIT_FAILURE);
    }

    // Fill in the socket address.
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = ((struct in_addr *)host->h_addr)->s_addr;
    addr.sin_port = htons(port);

    // Connect to the server.
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send the email address to the server.
    if (send(sockfd, email, strlen(email), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}