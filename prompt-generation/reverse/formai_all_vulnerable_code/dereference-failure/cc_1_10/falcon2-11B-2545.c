//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: grateful
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <dirent.h>

void sigint_handler(int sig) {
    printf("Caught SIGINT, exiting...\n");
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, n, status, bytes_read, ch;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    char hostname[1024];
    int port = 80;
    time_t start_time, end_time, uptime;

    if (argc > 1) {
        port = atoi(argv[1]);
    }

    signal(SIGINT, sigint_handler);

    start_time = time(NULL);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    uptime = time(NULL) - start_time;

    printf("Uptime: %ld seconds\n", uptime);

    while (1) {
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n < 0) {
            printf("Error receiving data\n");
            exit(1);
        }

        printf("Received data: %s\n", buffer);

        memset(buffer, 0, sizeof(buffer));

        bytes_read = send(sockfd, "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n", 49, 0);
        if (bytes_read < 0) {
            printf("Error sending data\n");
            exit(1);
        }

        ch = recv(sockfd, buffer, sizeof(buffer), 0);
        if (ch < 0) {
            printf("Error receiving data\n");
            exit(1);
        }

        printf("Received server response: %s\n", buffer);

        uptime = time(NULL) - start_time;

        if (uptime > 60) {
            printf("Website has been down for more than 60 seconds, restarting...\n");
            exit(0);
        }
    }

    return 0;
}