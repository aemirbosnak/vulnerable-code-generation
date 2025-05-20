//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_DATA_SIZE 1024
#define TIME_OUT 5

struct sockaddr_in server_addr;
int sockfd;
char data[MAX_DATA_SIZE];

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int opt = TRUE;
    int addrlen = sizeof(server_addr);
    int bytes_sent, bytes_recv;
    struct timeval timeout;
    fd_set readfds;

    if (argc!= 4) {
        printf("Usage: %s <IP Address> <Port Number> <Time Out>\n", argv[0]);
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        error_handling("socket failed");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("connect failed");
        return 1;
    }

    timeout.tv_sec = atoi(argv[3]);
    timeout.tv_usec = 0;

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    while (opt) {
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);

        if (select(sockfd + 1, &readfds, NULL, NULL, &timeout) == -1) {
            error_handling("select failed");
            return 1;
        }

        if (FD_ISSET(sockfd, &readfds)) {
            bytes_recv = recv(sockfd, data, MAX_DATA_SIZE, 0);

            if (bytes_recv <= 0) {
                error_handling("recv failed");
                return 1;
            }

            printf("Received Data: %s\n", data);
        }
    }

    close(sockfd);
    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(1);
}