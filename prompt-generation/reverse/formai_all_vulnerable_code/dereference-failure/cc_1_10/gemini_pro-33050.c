//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Donald Knuth
// A FTP client in the inimitable style of Donald Knuth.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// The main function.
int main(int argc, char *argv[])
{
    // Parse the command line arguments.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the hostname and port number.
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the FTP server.
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &serveraddr.sin_addr) != 1) {
        fprintf(stderr, "inet_pton: invalid address '%s'\n", hostname);
        return EXIT_FAILURE;
    }
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the FTP commands.
    char buf[1024];
    while (1) {
        // Get the command from the user.
        printf("ftp> ");
        fgets(buf, sizeof(buf), stdin);

        // Send the command to the FTP server.
        if (send(sockfd, buf, strlen(buf), 0) == -1) {
            perror("send");
            return EXIT_FAILURE;
        }

        // Receive the response from the FTP server.
        memset(buf, 0, sizeof(buf));
        if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
            perror("recv");
            return EXIT_FAILURE;
        }

        // Print the response to the user.
        printf("%s", buf);
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}