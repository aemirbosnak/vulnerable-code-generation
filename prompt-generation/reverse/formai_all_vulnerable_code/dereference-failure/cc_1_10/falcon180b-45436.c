//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX 65535
#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char *ip;
    int port;
    int result;
    int opt = TRUE;

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port>\n", argv[0]);
        exit(1);
    }

    ip = argv[1];
    port = atoi(argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket failed");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server))!= 0) {
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else if (errno == ETIMEDOUT) {
            printf("Connection timed out\n");
        } else {
            perror("connect failed");
        }
        close(sock);
        exit(1);
    } else {
        printf("Port %d is open\n", port);
    }

    close(sock);
    exit(0);
}