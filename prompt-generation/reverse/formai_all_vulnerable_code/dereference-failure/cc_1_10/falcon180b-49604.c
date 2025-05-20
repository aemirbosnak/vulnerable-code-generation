//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, ret, timeout;
    struct hostent *host;
    struct sockaddr_in serv_addr;
    char send_buf[BUF_SIZE], recv_buf[BUF_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Timeout in seconds>\n", argv[0]);
        exit(1);
    }

    strcpy(send_buf, "PING");
    strcat(send_buf, " ");
    strcat(send_buf, argv[1]);
    strcat(send_buf, " ");
    strcat(send_buf, argv[2]);
    strcat(send_buf, "\r\n");

    timeout = atoi(argv[2]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Socket creation failed\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed\n");
        exit(1);
    }

    send(sockfd, send_buf, strlen(send_buf), 0);

    memset(recv_buf, 0, BUF_SIZE);
    ret = recv(sockfd, recv_buf, BUF_SIZE, 0);

    if (ret < 0) {
        printf("Receive failed\n");
        exit(1);
    } else if (ret == 0) {
        printf("No response from server\n");
        exit(1);
    } else {
        printf("Response from server:\n%s\n", recv_buf);
    }

    close(sockfd);
    return 0;
}