//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define FTP_PORT 21
#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <host> <file>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    char *file = argv[2];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(FTP_PORT);

    if (inet_pton(AF_INET, host, &serv_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return 1;
    }

    char buf[MAX_BUF_SIZE];
    sprintf(buf, "USER anonymous\r\n");
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    if (recv(sock, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv");
        return 1;
    }

    sprintf(buf, "PASS anonymous@\r\n");
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    if (recv(sock, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv");
        return 1;
    }

    sprintf(buf, "TYPE I\r\n");
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    if (recv(sock, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv");
        return 1;
    }

    sprintf(buf, "PASV\r\n");
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    if (recv(sock, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv");
        return 1;
    }

    char *pasv = strstr(buf, "(");
    if (pasv == NULL) {
        printf("Invalid PASV response\n");
        return 1;
    }

    pasv++;
    char *end = strchr(pasv, ')');
    if (end == NULL) {
        printf("Invalid PASV response\n");
        return 1;
    }

    *end = '\0';
    char *host_port = pasv;
    int port = atoi(end + 1);

    struct sockaddr_in data_addr;
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, host_port, &data_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    int data_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sock < 0) {
        perror("socket");
        return 1;
    }

    if (connect(data_sock, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        perror("connect");
        return 1;
    }

    sprintf(buf, "RETR %s\r\n", file);
    if (send(data_sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    FILE *fp = fopen(file, "wb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    while (1) {
        int n = recv(data_sock, buf, MAX_BUF_SIZE, 0);
        if (n < 0) {
            perror("recv");
            return 1;
        } else if (n == 0) {
            break;
        }

        fwrite(buf, 1, n, fp);
    }

    fclose(fp);
    close(data_sock);
    close(sock);

    return 0;
}