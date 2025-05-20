//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_HOST_LEN 256
#define MAX_SEND_LEN 1024
#define MAX_RECV_LEN 1024

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len;
    char send_buf[MAX_SEND_LEN], recv_buf[MAX_RECV_LEN];
    int port = 8080;

    if (argc == 1) {
        printf("Usage: %s <IP Address> <Port>\n", argv[0]);
        exit(1);
    }

    if (argc == 3) {
        port = atoi(argv[2]);
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        printf("Error: Failed to create socket.\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    addr_len = sizeof(server_addr);

    while (1) {
        ret = sendto(sockfd, send_buf, strlen(send_buf), 0, (struct sockaddr *)&server_addr, addr_len);
        if (ret == -1) {
            printf("Error: Failed to send packet.\n");
            exit(1);
        }

        memset(recv_buf, 0, sizeof(recv_buf));
        addr_len = sizeof(client_addr);
        ret = recvfrom(sockfd, recv_buf, sizeof(recv_buf), 0, (struct sockaddr *)&client_addr, &addr_len);
        if (ret == -1) {
            printf("Error: Failed to receive packet.\n");
            exit(1);
        }

        printf("Received message from %s:%d: %s\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), recv_buf);
    }

    close(sockfd);
    return 0;
}