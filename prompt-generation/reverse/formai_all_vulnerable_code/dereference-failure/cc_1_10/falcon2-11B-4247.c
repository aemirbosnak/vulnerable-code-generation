//Falcon2-11B DATASET v1.0 Category: Networking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

// function to print the error message
void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc!= 3) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    if (portno < 0 || portno > 65535) {
        fprintf(stderr, "Invalid port number\n");
        exit(1);
    }

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        error("ERROR opening socket");

    // get server address
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    printf("Connected to server\n");
    n = read(sockfd, "hello world\n", sizeof("hello world\n"));
    if (n < 0)
        error("ERROR reading from socket");
    else
        printf("Received: %s\n", "hello world\n");

    send(sockfd, "goodbye\n", sizeof("goodbye\n"), 0);
    if (n < 0)
        error("ERROR writing to socket");
    else
        printf("Sent: %s\n", "goodbye\n");

    close(sockfd);
    return 0;
}