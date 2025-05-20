//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>

#define BUF_SIZE 1024
#define PORT 110
#define TIMEOUT 10

int main(int argc, char *argv[]) {
    int sockfd, bytes_read;
    struct sockaddr_in serv_addr;
    char send_buf[BUF_SIZE], recv_buf[BUF_SIZE];
    struct hostent *server;
    int opt = 1;

    if (argc!= 3) {
        printf("Usage: %s <server_address> <port>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: could not resolve hostname\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: could not create socket\n");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = *(unsigned long *)server->h_addr;

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: could not connect to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(send_buf, 0, BUF_SIZE);
        printf("Enter command: ");
        fgets(send_buf, BUF_SIZE, stdin);
        send(sockfd, send_buf, strlen(send_buf), 0);

        memset(recv_buf, 0, BUF_SIZE);
        bytes_read = recv(sockfd, recv_buf, BUF_SIZE, 0);
        if (bytes_read <= 0) {
            printf("Error: could not receive data from server\n");
            exit(1);
        }

        printf("Received from server: %s", recv_buf);
    }

    close(sockfd);
    return 0;
}