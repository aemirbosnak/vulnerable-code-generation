//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char **argv) {
    int sockfd, portno;
    struct hostent *server;
    char buffer[1025];
    int n;
    char *ptr;
    int speed = 0;
    float filesize = 1024 * 1024; // 1MB
    
    if (argc < 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        return 0;
    }

    portno = atoi(argv[2]);
    server = gethostbyname(argv[1]);

    if (server == NULL) {
        printf("No such host\n");
        return 0;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("socket failed\n");
        return 0;
    }

    if (connect(sockfd, (struct sockaddr *)server, sizeof(struct sockaddr)) < 0) {
        printf("connect failed\n");
        return 0;
    }

    printf("Connected to %s:%d\n", argv[1], portno);

    while (speed < 1024) {
        memset(buffer, 'a', 1024);
        send(sockfd, buffer, 1024, 0);
        n = recv(sockfd, buffer, 1024, 0);
        speed += n;
        usleep(10000);
    }

    close(sockfd);

    printf("Speed test complete\n");
    printf("Download speed: %d KB/s\n", speed);

    return 0;
}