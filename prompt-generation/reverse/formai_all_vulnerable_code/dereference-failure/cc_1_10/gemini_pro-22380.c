//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_LINE 1024

char *html_escape(char *str) {
    char *escaped_str = malloc(strlen(str) * 3 + 1);
    char *p = escaped_str;
    while (*str) {
        switch (*str) {
            case '&':  *p++ = '&';  *p++ = 'a';  *p++ = 'm';  *p++ = 'p';  *p++ = ';';  break;
            case '<':  *p++ = '&';  *p++ = 'l';  *p++ = 't';  *p++ = ';';  break;
            case '>':  *p++ = '&';  *p++ = 'g';  *p++ = 't';  *p++ = ';';  break;
            default:   *p++ = *str;
        }
        str++;
    }
    *p = '\0';
    return escaped_str;
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[MAX_LINE], recvline[MAX_LINE];
    char *escaped_sendline;

    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation failed\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        printf("Invalid hostname or IP address\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        printf("Connection failed\n");
        exit(1);
    }

    while (1) {
        printf("> ");
        fflush(stdout);

        if ((n = read(0, sendline, MAX_LINE)) <= 0) {
            break;
        }

        sendline[n - 1] = '\0';
        escaped_sendline = html_escape(sendline);

        sprintf(sendline, "GET /%s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", escaped_sendline, argv[1]);
        free(escaped_sendline);

        if (write(sockfd, sendline, strlen(sendline)) < 0) {
            printf("Write failed\n");
            break;
        }

        memset(recvline, 0, sizeof(recvline));
        if ((n = read(sockfd, recvline, MAX_LINE)) <= 0) {
            printf("Read failed\n");
            break;
        }

        printf("%s", recvline);
    }

    close(sockfd);
    return 0;
}