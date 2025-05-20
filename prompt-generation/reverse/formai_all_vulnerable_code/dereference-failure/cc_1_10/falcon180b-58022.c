//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    struct hostent *host_info;
    if ((host_info = gethostbyname(ip_address)) == NULL) {
        printf("Error: Invalid IP address.\n");
        return 1;
    }

    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error: Could not create socket.\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)host_info->h_addr), &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Could not connect to server.\n");
        close(sockfd);
        return 1;
    }

    char send_buf[BUF_SIZE];
    strcpy(send_buf, "PING");
    send(sockfd, send_buf, strlen(send_buf), 0);

    char recv_buf[BUF_SIZE];
    int recv_len;
    if ((recv_len = recv(sockfd, recv_buf, BUF_SIZE, 0)) == -1) {
        printf("Error: Could not receive response.\n");
        close(sockfd);
        return 1;
    }

    printf("Response: %.*s\n", recv_len, recv_buf);

    close(sockfd);
    return 0;
}