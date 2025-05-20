//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define MAX_ATTEMPTS 5
#define TIMEOUT_SEC 2
#define TIMEOUT_USEC 0

void print_usage(char *program) {
    printf("Usage: %s <IP Address>\n", program);
}

int ping(char *ip) {
    int sockfd, ret;
    struct sockaddr_in servaddr;
    char buffer[BUFFER_SIZE];
    int attempts = 0;
    int success = 0;
    struct timeval timeout;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &servaddr.sin_addr);
    servaddr.sin_port = htons(7);

    while (attempts < MAX_ATTEMPTS) {
        ret = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
        if (ret == 0) {
            success = 1;
            break;
        } else if (errno == EINPROGRESS) {
            timeout.tv_sec = TIMEOUT_SEC;
            timeout.tv_usec = TIMEOUT_USEC;
            ret = select(sockfd + 1, NULL, NULL, NULL, &timeout);
            if (ret == 0) {
                attempts++;
            } else if (ret == -1) {
                perror("select failed");
                exit(EXIT_FAILURE);
            }
        } else {
            attempts++;
        }
    }

    if (success) {
        printf("Ping successful to %s\n", ip);
    } else {
        printf("Ping failed to %s\n", ip);
    }

    close(sockfd);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    ping(argv[1]);

    return 0;
}