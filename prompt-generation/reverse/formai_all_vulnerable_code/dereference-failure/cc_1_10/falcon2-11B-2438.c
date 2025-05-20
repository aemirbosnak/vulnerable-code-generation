//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        exit(1);
    }

    char url[BUFSIZE];
    strcpy(url, argv[1]);

    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    if (inet_pton(AF_INET, "www.example.com", &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    char buffer[BUFSIZE];
    int n;

    while (1) {
        if ((n = read(sockfd, buffer, sizeof(buffer))) < 0) {
            perror("read");
            exit(1);
        }

        if (strstr(buffer, "200 OK")) {
            printf("Website is up!\n");
            exit(0);
        }

        sleep(10);
    }

    return 0;
}