//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

void scan_ports(int sockfd, struct sockaddr_in *serv_addr, int port_start, int port_end) {
    int i, opt = 1;
    char buf[BUF_SIZE];
    struct sockaddr_in client_addr;
    socklen_t addr_size = sizeof(client_addr);

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    for (i = port_start; i <= port_end; i++) {
        if (i == 80) {
            printf("Port 80 is open\n");
        } else if (i == 443) {
            printf("Port 443 is open\n");
        } else {
            memset(&client_addr, 0, sizeof(client_addr));
            client_addr.sin_family = AF_INET;
            client_addr.sin_port = htons(i);
            client_addr.sin_addr.s_addr = inet_addr("192.168.0.1");

            if (connect(sockfd, (struct sockaddr *)&client_addr, sizeof(client_addr)) == 0) {
                close(sockfd);
                printf("Port %d is open\n", i);
            } else if (errno!= ECONNREFUSED) {
                perror("connect");
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int sockfd, port_start, port_end;
    struct sockaddr_in serv_addr;

    if (argc!= 4) {
        printf("Usage: %s <IP Address> <Port Start> <Port End>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(0);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    port_start = atoi(argv[2]);
    port_end = atoi(argv[3]);

    scan_ports(sockfd, &serv_addr, port_start, port_end);

    close(sockfd);
    return 0;
}