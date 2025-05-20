//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_LINE 1024
#define MAX_HOST_NAME 256
#define MAX_EMAIL 256
#define MAX_SUBJECT 256
#define MAX_BODY 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serveraddr;
    char *host;
    char *email;
    char *subject;
    char *body;
    char *line = NULL;
    char *ptr;
    char buffer[MAX_LINE];
    FILE *fp;
    int len;

    if (argc!= 7) {
        printf("Usage: %s <host> <email> <subject> <body> <filename>\n", argv[0]);
        return 1;
    }

    host = argv[1];
    email = argv[2];
    subject = argv[3];
    body = argv[4];
    fp = fopen(argv[6], "r");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        return 1;
    }

    line = fgets(line, MAX_LINE, fp);
    while (line!= NULL) {
        len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[--len] = '\0';
        }
        send(sockfd, line, len, 0);
        line = fgets(line, MAX_LINE, fp);
    }

    fclose(fp);
    close(sockfd);

    return 0;
}