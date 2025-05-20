//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, ret;
    struct sockaddr_in server_addr;
    char send_buf[BUF_SIZE];
    char recv_buf[BUF_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        return -1;
    }

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error: Failed to create socket\n");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        printf("Error: Invalid IP address\n");
        close(sock);
        return -1;
    }

    while (1) {
        ret = sendto(sock, send_buf, BUF_SIZE, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (ret == -1) {
            printf("Error: Failed to send packet\n");
            close(sock);
            return -1;
        }

        ret = recv(sock, recv_buf, BUF_SIZE, 0);
        if (ret == -1) {
            printf("Error: Failed to receive packet\n");
            close(sock);
            return -1;
        }

        if (recv_buf[0] == 'Q' && recv_buf[1] == 'o' && recv_buf[2] == 'S') {
            printf("Quality of Service is good\n");
        } else {
            printf("Quality of Service is poor\n");
        }

        memset(send_buf, 0, BUF_SIZE);
        memset(recv_buf, 0, BUF_SIZE);
    }

    close(sock);
    return 0;
}