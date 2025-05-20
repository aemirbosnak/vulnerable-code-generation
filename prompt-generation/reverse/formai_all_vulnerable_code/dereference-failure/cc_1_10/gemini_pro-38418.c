//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: random
#if 1 // compile and run this
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024

int main(int argc, char **argv) {
    int sockfd, n;
    struct sockaddr_in servaddr;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server IP> <server port>\n", argv[0]);
        exit(1);
    }

    // create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // connect to the server
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // send a message to the server
    char buffer[MAX_LINE];
    sprintf(buffer, "HELO %s\r\n", argv[1]);
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("write");
        exit(1);
    }

    // read a response from the server
    bzero(buffer, MAX_LINE);
    if ((n = read(sockfd, buffer, MAX_LINE)) < 0) {
        perror("read");
        exit(1);
    }
    printf("%s", buffer);

    // close the socket
    close(sockfd);

    return 0;
}
#else //another possible implementation
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024

int main(int argc, char **argv) {
    int sockfd, n;
    struct sockaddr_in servaddr;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server IP> <server port>\n", argv[0]);
        exit(1);
    }

    // create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // connect to the server
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // send a message to the server
    char buffer[MAX_LINE];
    sprintf(buffer, "HELO %s\r\n", argv[1]);
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("write");
        exit(1);
    }

    // read a response from the server
    bzero(buffer, MAX_LINE);
    if ((n = read(sockfd, buffer, MAX_LINE)) < 0) {
        perror("read");
        exit(1);
    }
    printf("%s", buffer);

    // close the socket
    close(sockfd);

    return 0;
}
#endif