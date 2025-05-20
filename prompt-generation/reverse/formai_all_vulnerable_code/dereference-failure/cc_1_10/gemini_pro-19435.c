//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server-ip> <server-port> <email-address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send the email address to the server
    char *email_address = argv[3];
    int len = strlen(email_address);
    if (send(sockfd, email_address, len, 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the email from the server
    char buffer[MAX_LINE];
    int n;
    while ((n = recv(sockfd, buffer, MAX_LINE, 0)) > 0) {
        printf("%s", buffer);
    }
    if (n < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}