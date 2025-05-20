//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, n;
    struct sockaddr_in serv_addr;
    char send_buf[BUF_SIZE], recv_buf[BUF_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(143);
    inet_pton(AF_INET, "localhost", &serv_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to IMAP server successfully\n");

    while (1) {
        printf("Enter command: ");
        fgets(send_buf, BUF_SIZE, stdin);
        send_buf[strcspn(send_buf, "\r\n")] = '\0';

        if (strcasecmp(send_buf, "LOGIN") == 0) {
            strcat(send_buf, " ");
            strcat(send_buf, argv[1]);
            strcat(send_buf, " ");
            strcat(send_buf, argv[2]);
        }

        if (strcasecmp(send_buf, "LOGOUT") == 0) {
            break;
        }

        n = send(sock, send_buf, strlen(send_buf), 0);

        if (n < 0) {
            perror("send failed");
            exit(EXIT_FAILURE);
        }

        memset(recv_buf, 0, BUF_SIZE);
        n = recv(sock, recv_buf, BUF_SIZE, 0);

        if (n < 0) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }

        printf("Received: %s\n", recv_buf);
    }

    close(sock);

    return 0;
}