//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

void send_message(int sockfd, char *msg) {
    int n;
    n = write(sockfd, msg, strlen(msg));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }
}

void receive_message(int sockfd, char *buf, int buflen) {
    int n;
    n = read(sockfd, buf, buflen);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    if (argc < 3) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    send_message(sockfd, "Hello, world!");
    receive_message(sockfd, buffer, sizeof(buffer));

    printf("%s\n", buffer);

    exit(0);
}