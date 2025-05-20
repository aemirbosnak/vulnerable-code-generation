//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in servaddr;
    struct hostent *server;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    portno = htons(atoi(argv[1]));
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = portno;

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    if (mkdir("test_dir", 0777) < 0) {
        perror("ERROR creating directory");
        exit(1);
    }

    if (creat("test_file", 0777) < 0) {
        perror("ERROR creating file");
        exit(1);
    }

    write(sockfd, "Hello World", 12);
    close(sockfd);

    printf("Success!\n");
    exit(0);
}