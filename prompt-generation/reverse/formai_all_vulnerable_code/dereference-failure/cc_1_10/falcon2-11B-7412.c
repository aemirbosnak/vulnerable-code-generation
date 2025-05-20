//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 110
#define MAX_LINE 512

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <username> <password>\n", argv[0]);
        exit(1);
    }

    struct sockaddr_in server;
    int sockfd, ret;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(argv[2]);

    ret = connect(sockfd, (struct sockaddr *) &server, sizeof(server));
    if (ret < 0) {
        perror("connect");
        exit(1);
    }

    char buffer[MAX_LINE];
    strcpy(buffer, "USER ");
    strcat(buffer, argv[1]);
    strcat(buffer, "\r\n");

    write(sockfd, buffer, strlen(buffer));

    ret = read(sockfd, buffer, MAX_LINE);
    if (ret < 0) {
        perror("read");
        exit(1);
    }
    printf("Response from server: %s\n", buffer);

    strcpy(buffer, "PASS ");
    strcat(buffer, argv[2]);
    strcat(buffer, "\r\n");

    write(sockfd, buffer, strlen(buffer));

    ret = read(sockfd, buffer, MAX_LINE);
    if (ret < 0) {
        perror("read");
        exit(1);
    }
    printf("Response from server: %s\n", buffer);

    return 0;
}