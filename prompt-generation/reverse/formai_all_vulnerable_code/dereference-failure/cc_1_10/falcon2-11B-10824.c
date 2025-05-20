//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in servaddr;
    struct hostent *server;

    // check the command line arguments
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    // create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // fill in the structure with the correct server address information
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }
    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(21); // ftp port number

    // connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // send the username and password
    char buf[100];
    bzero(buf, sizeof(buf));
    sprintf(buf, "USER %s\r\n", argv[1]);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("ERROR sending username");
        exit(1);
    }
    bzero(buf, sizeof(buf));
    sprintf(buf, "PASS %s\r\n", argv[1]);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("ERROR sending password");
        exit(1);
    }

    // send the command to list files
    bzero(buf, sizeof(buf));
    sprintf(buf, "NLST\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("ERROR sending command");
        exit(1);
    }

    // receive and print the response
    bzero(buf, sizeof(buf));
    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n <= 0) {
        perror("ERROR receiving response");
        exit(1);
    }
    printf("%s\n", buf);

    // close the socket
    close(sockfd);

    return 0;
}