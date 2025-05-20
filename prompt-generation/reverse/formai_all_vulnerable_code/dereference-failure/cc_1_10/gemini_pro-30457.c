//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buf[BUF_SIZE];
    struct hostent *server;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    // create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // get the server's IP address
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "error: no such host\n");
        exit(1);
    }

    // set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    memcpy(&servaddr.sin_addr.s_addr, server->h_addr, server->h_length);

    // connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // send a message to the server
    strcpy(buf, "Hello world!\n");
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    // receive a message from the server
    n = read(sockfd, buf, BUF_SIZE - 1);
    if (n < 0) {
        perror("read");
        exit(1);
    }

    // print the message from the server
    buf[n] = '\0';
    printf("Received: %s", buf);

    // close the socket
    close(sockfd);

    return 0;
}