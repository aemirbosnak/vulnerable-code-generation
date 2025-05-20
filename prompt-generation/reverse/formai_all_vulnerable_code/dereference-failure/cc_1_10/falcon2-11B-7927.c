//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_LINE 100
#define MAX_MESSAGE 1000

/* Sendmail API */
int sendmail(char *to, char *from, char *subject, char *body);

int main(int argc, char **argv) {
    if (argc < 5) {
        printf("Usage: %s to from subject message\n", argv[0]);
        return 1;
    }

    char *to = argv[1];
    char *from = argv[2];
    char *subject = argv[3];
    char *body = argv[4];

    sendmail(to, from, subject, body);
    return 0;
}

int sendmail(char *to, char *from, char *subject, char *body) {
    int sockfd;
    struct hostent *server;
    struct sockaddr_in servaddr;
    int i;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        perror("ERROR, no such host");
        exit(EXIT_FAILURE);
    }

    memset((char *)&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(25);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < strlen(subject); i++) {
        if (isupper(subject[i])) {
            subject[i] = tolower(subject[i]);
        }
    }

    printf("Subject: %s\r\n", subject);
    printf("From: %s\r\n", from);
    printf("To: %s\r\n", to);
    printf("Content-Type: text/plain; charset=utf-8\r\n");
    printf("Content-Length: %d\r\n\r\n", strlen(body));
    printf("%s", body);

    close(sockfd);
    return 0;
}