//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define MAXLINE 1024

void die(const char *s) {
    perror(s);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in servaddr;
    char host[MAXLINE];
    char buff[MAXLINE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <file>\n", argv[0]);
        exit(1);
    }

    strcpy(host, argv[1]);
    FILE *fp = fopen(argv[2], "r");

    if (fp == NULL) {
        die("Open file error");
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        die("Socket error");
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(25);

    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
        die("Invalid address/hostname");
    }

    if (connect(sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        die("Connect error");
    }

    fprintf(stdout, "Connected to %s\n", host);

    while (fgets(buff, MAXLINE, fp)!= NULL) {
        send(sock, buff, strlen(buff), 0);
    }

    fclose(fp);

    char recv_buff[MAXLINE];
    while (recv(sock, recv_buff, MAXLINE, 0) > 0) {
        fprintf(stdout, "%s", recv_buff);
    }

    close(sock);

    return 0;
}