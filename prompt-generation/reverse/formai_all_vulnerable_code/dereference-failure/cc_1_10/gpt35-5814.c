//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    struct hostent *server;

    char buf[BUFSIZE];

    // Check for correct number of arguments
    if (argc != 3) {
        printf("usage: %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get server IP address from hostname
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Clear servaddr
    memset(&servaddr, 0, sizeof(servaddr));

    // Fill in servaddr
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    memcpy(&servaddr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    // Get user input
    while(fgets(buf, BUFSIZE, stdin)) {
        // Send command to server
        n = write(sockfd, buf, strlen(buf));
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(EXIT_FAILURE);
        }

        // Clear buf and read response from server
        memset(buf, 0, BUFSIZE);
        n = read(sockfd, buf, BUFSIZE);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(EXIT_FAILURE);
        }

        // Print response from server
        printf("%s\n", buf);
    }

    // Close socket
    close(sockfd);

    return 0;
}