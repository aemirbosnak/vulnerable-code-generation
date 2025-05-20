//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE 1024
#define SERVER_PORT 25

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serveraddr;
    char buffer[MAX_LINE];
    char *message;
    FILE *fp;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <server> <message_file>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "socket failed: %s\n", strerror(errno));
        exit(1);
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, argv[1], &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        fprintf(stderr, "connect failed: %s\n", strerror(errno));
        exit(1);
    }

    fp = fopen(argv[2], "r");
    if (fp == NULL) {
        fprintf(stderr, "fopen failed: %s\n", strerror(errno));
        exit(1);
    }

    while ((n = fread(buffer, 1, MAX_LINE, fp)) > 0) {
        buffer[n] = '\0';
        send(sockfd, buffer, n, 0);
    }

    fclose(fp);
    close(sockfd);

    return 0;
}