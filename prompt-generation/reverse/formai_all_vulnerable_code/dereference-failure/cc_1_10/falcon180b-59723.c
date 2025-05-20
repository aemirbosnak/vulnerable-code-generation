//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct sockaddr_in server_addr;
    char buffer[1024];
    int timeout = 500; // in milliseconds
    int max_attempts = 5;
    int attempt_count = 0;
    time_t start_time, end_time;
    double elapsed_time;

    if (argc!= 4) {
        printf("Usage:./ping <IP address> <port number> <packet size>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed: %s\n", strerror(errno));
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(atoi(argv[2]));

    while (attempt_count < max_attempts) {
        start_time = time(NULL);
        send(sockfd, argv[3], strlen(argv[3]), 0);
        ret = recv(sockfd, buffer, sizeof(buffer), 0);
        if (ret > 0) {
            printf("Response received: %s\n", buffer);
            break;
        } else if (ret == 0) {
            printf("Connection closed\n");
            exit(1);
        } else if (errno!= EWOULDBLOCK) {
            printf("Recv error: %s\n", strerror(errno));
            exit(1);
        }
        end_time = time(NULL);
        elapsed_time = difftime(end_time, start_time);
        if (elapsed_time >= timeout) {
            printf("Timeout\n");
            close(sockfd);
            exit(1);
        }
        attempt_count++;
    }

    if (attempt_count == max_attempts) {
        printf("No response received\n");
        exit(1);
    }

    close(sockfd);
    exit(0);
}