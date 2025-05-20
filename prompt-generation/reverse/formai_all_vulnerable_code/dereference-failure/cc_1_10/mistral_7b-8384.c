//MISTRAL-7B DATASET v1.0 Category: Network Ping Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <time.h>

#define MAX_PACKET_LEN 64
#define TIMEOUT 500
#define SERVER_PORT 80
#define BUFFER_SIZE 2048

int main(int argc, char *argv[]) {
    int sockfd, ret, i;
    struct sockaddr_in serv_addr;
    char send_buf[MAX_PACKET_LEN];
    char recv_buf[BUFFER_SIZE];
    struct timeval tv;
    fd_set readfds;

    if (argc != 2) {
        printf("Usage: %s <server_ip>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    while (1) {
        sendto(sockfd, send_buf, MAX_PACKET_LEN, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        tv.tv_usec = 0;
        tv.tv_sec = TIMEOUT / 1000;

        ret = select(sockfd + 1, &readfds, NULL, NULL, &tv);
        if (ret > 0 && FD_ISSET(sockfd, &readfds)) {
            ssize_t recv_len = recvfrom(sockfd, recv_buf, BUFFER_SIZE, 0, NULL, NULL);
            if (recv_len > 0) {
                printf("Reply received from %s\n", inet_ntoa(serv_addr.sin_addr));
                break;
            }
        }

        if (errno != EAGAIN) {
            perror("select");
            close(sockfd);
            exit(1);
        }

        for (i = 0; i < MAX_PACKET_LEN; i++) {
            send_buf[i] = i + 'A';
        }

        if (sendto(sockfd, send_buf, MAX_PACKET_LEN, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            perror("sendto");
            close(sockfd);
            exit(1);
        }
    }

    close(sockfd);
    return 0;
}