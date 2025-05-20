//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define POP3_PORT 110

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024], command[100];
    FILE *fp;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s username\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(POP3_PORT);
    if ((inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)) <= 0) {
        fprintf(stderr, "ERROR, can't resolve address\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    snprintf(command, 100, "USER %s\r\n", argv[1]);
    if (send(sockfd, command, strlen(command), 0) < 0)
        error("ERROR sending command");

    snprintf(command, 100, "PASS %s\r\n", argv[1]);
    if (send(sockfd, command, strlen(command), 0) < 0)
        error("ERROR sending command");

    snprintf(command, 100, "STAT\r\n");
    if (send(sockfd, command, strlen(command), 0) < 0)
        error("ERROR sending command");

    n = read(sockfd, buffer, 1024);
    if (n < 0)
        error("ERROR reading from socket");
    else if (n == 0)
        error("ERROR reading from socket - connection closed");
    else {
        printf("Received: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}