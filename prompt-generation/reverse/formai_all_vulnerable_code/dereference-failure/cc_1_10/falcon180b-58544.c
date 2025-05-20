//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_LINE 1024
#define BUF_SIZE 8192

int main(int argc, char** argv) {
    int sock;
    struct sockaddr_in serv_addr;
    char recv_buf[BUF_SIZE];
    char send_buf[MAX_LINE];
    int n;

    if (argc!= 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        return 1;
    }

    strcpy(send_buf, "LOGIN ");
    strcat(send_buf, argv[2]);
    strcat(send_buf, " ");
    strcat(send_buf, argv[3]);
    strcat(send_buf, "\r\n");

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: socket() failed\n");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(143);

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        printf("Error: inet_pton() failed\n");
        return 1;
    }

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error: connect() failed\n");
        return 1;
    }

    if (send(sock, send_buf, strlen(send_buf), 0) == -1) {
        printf("Error: send() failed\n");
        return 1;
    }

    while ((n = recv(sock, recv_buf, BUF_SIZE, 0)) > 0) {
        recv_buf[n] = '\0';
        printf("%s", recv_buf);
    }

    close(sock);
    return 0;
}