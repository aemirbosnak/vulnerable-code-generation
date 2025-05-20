//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {

    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    char hostname[1024];
    strcpy(hostname, argv[1]);

    struct hostent *he;
    he = gethostbyname(hostname);
    if (he == NULL) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)he->h_addr), &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    char send_buf[BUF_SIZE];
    memset(send_buf, 'A', BUF_SIZE);
    send(sockfd, send_buf, BUF_SIZE, 0);

    char recv_buf[BUF_SIZE];
    memset(recv_buf, 0, BUF_SIZE);
    int bytes_recv = recv(sockfd, recv_buf, BUF_SIZE, 0);

    printf("Received %d bytes: %s\n", bytes_recv, recv_buf);

    close(sockfd);
    return 0;
}