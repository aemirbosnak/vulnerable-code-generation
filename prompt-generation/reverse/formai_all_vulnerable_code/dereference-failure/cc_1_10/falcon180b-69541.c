//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUF_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "speedtest.net"

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_buf[BUF_SIZE], recv_buf[BUF_SIZE];
    double start_time, end_time;
    long file_size;
    FILE *fp;

    if (argc!= 3) {
        printf("Usage:./speedtest <filename> <filesize>\n");
        return 1;
    }

    file_size = atoi(argv[2]);
    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error: File not found\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    if (ftell(fp)!= file_size) {
        printf("Error: File size mismatch\n");
        return 1;
    }

    rewind(fp);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        error("socket failed");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("connect failed");

    start_time = clock();
    while (fread(send_buf, 1, BUF_SIZE, fp) > 0) {
        n = send(sockfd, send_buf, strlen(send_buf), 0);
        if (n < 0)
            error("send failed");
    }
    end_time = clock();

    close(sockfd);
    fclose(fp);

    printf("Time taken: %.2f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    printf("Bandwidth: %.2f KB/s\n", (double)file_size / (end_time - start_time));

    return 0;
}