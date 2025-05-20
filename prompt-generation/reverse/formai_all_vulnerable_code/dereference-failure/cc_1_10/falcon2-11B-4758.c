//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int sockfd, valread, portno;
    struct sockaddr_in serv_addr;
    char buffer[256];
    struct timeval start_time, end_time;

    if (argc!= 2) {
        printf("Usage: %s <website_url>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    gettimeofday(&start_time, NULL);
    while (1) {
        valread = read(sockfd, buffer, 255);
        if (valread < 0) {
            perror("read failed");
            exit(1);
        }
        gettimeofday(&end_time, NULL);
        if (end_time.tv_sec - start_time.tv_sec > 10) {
            printf("Website is down!\n");
            exit(1);
        }
    }

    return 0;
}