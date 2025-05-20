//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 110
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buf[MAX_LINE];
    int n;

    if (argc != 3) {
        printf("usage: %s <hostname> <username>\n", argv[0]);
        return 1;
    }

    // create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // resolve the hostname
    struct hostent *hostent = gethostbyname(argv[1]);
    if (hostent == NULL) {
        perror("gethostbyname");
        return 1;
    }

    // set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    bcopy(hostent->h_addr, &servaddr.sin_addr, hostent->h_length);

    // connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return 1;
    }

    // send the username
    sprintf(buf, "USER %s\r\n", argv[2]);
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        perror("write");
        return 1;
    }

    // receive the server response
    n = read(sockfd, buf, MAX_LINE);
    if (n < 0) {
        perror("read");
        return 1;
    }

    // print the server response
    printf("%s", buf);

    // close the socket
    close(sockfd);

    return 0;
}