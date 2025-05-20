//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buf[BUF_SIZE];

    // Check for correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    // Get host information
    struct hostent *host = gethostbyname(argv[1]);
    if (!host) {
        fprintf(stderr, "Error: could not resolve host %s\n", argv[1]);
        exit(1);
    }

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error: could not create socket");
        exit(1);
    }

    // Connect to server
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = ((struct in_addr *)(host->h_addr))->s_addr;
    servaddr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error: could not connect to server");
        exit(1);
    }

    // Read SMTP response
    while ((n = read(sockfd, buf, BUF_SIZE)) > 0) {
        buf[n] = '\0';
        printf("%s", buf);

        // Check for end of response
        if (buf[n - 1] == '\n')
            break;
    }

    // Send IMAP command
    char cmd[] = "LOGIN username password\n";
    write(sockfd, cmd, strlen(cmd));

    // Read IMAP response
    while ((n = read(sockfd, buf, BUF_SIZE)) > 0) {
        buf[n] = '\0';
        printf("%s", buf);

        // Check for end of response
        if (buf[n - 1] == '\n')
            break;
    }

    // Close socket
    close(sockfd);

    return 0;
}