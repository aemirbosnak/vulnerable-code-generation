//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, ret, opt = 1;
    struct sockaddr_in server_addr;
    char send_buf[BUF_SIZE], recv_buf[BUF_SIZE];

    if (argc!= 4) {
        printf("Usage: %s <IP address> <port number> <filename>\n", argv[0]);
        exit(1);
    }

    strcpy(send_buf, argv[3]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit(1);
    }

    setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, (char *)&opt, sizeof(opt));

    send(sockfd, send_buf, strlen(send_buf), 0);

    while (1) {
        memset(recv_buf, 0, BUF_SIZE);
        ret = recv(sockfd, recv_buf, BUF_SIZE, 0);

        if (ret <= 0) {
            break;
        }

        printf("%s", recv_buf);
    }

    close(sockfd);

    return 0;
}