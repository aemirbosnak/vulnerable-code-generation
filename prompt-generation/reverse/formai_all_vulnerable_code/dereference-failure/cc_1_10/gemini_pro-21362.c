//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

#define MAX_URL_LEN 2048
#define MAX_TIME 600

int sockfd;

void sig_int(int signo)
{
    close(sockfd);
    exit(0);
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <url> <time>\n", argv[0]);
        exit(1);
    }

    if (strlen(argv[1]) > MAX_URL_LEN) {
        fprintf(stderr, "URL too long\n");
        exit(1);
    }

    if (atoi(argv[2]) > MAX_TIME) {
        fprintf(stderr, "Time too long\n");
        exit(1);
    }

    int time = atoi(argv[2]);

    struct sockaddr_in addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);

    if (inet_pton(AF_INET, argv[1], &addr.sin_addr.s_addr) != 1) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        exit(1);
    }

    signal(SIGINT, sig_int);

    while (1) {
        char buffer[1024];
        int n = read(sockfd, buffer, sizeof(buffer));
        if (n > 0) {
            printf("Received %d bytes\n", n);
        } else if (n == 0) {
            printf("Connection closed\n");
            close(sockfd);
            exit(0);
        } else {
            perror("read");
            break;
        }
        sleep(time);
    }

    return 0;
}