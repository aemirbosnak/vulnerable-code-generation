//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    int fd;
    char cmd[BUF_SIZE];
    char buf[BUF_SIZE];
    struct sockaddr_in address;

    if (argc != 3) {
        printf("usage: %s <server-ip> <port>\n", argv[0]);
        return 1;
    }

    fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (fd == -1) {
        perror("socket");
        return 1;
    }

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(atoi(argv[2]));
    inet_aton(argv[1], &address.sin_addr);

    if (connect(fd, (struct sockaddr *)&address, sizeof(address)) == -1) {
        perror("connect");
        return 1;
    }

    printf("Connected to %s:%s\n", argv[1], argv[2]);

    while (1) {
        printf("ftp> ");
        fgets(cmd, BUF_SIZE, stdin);

        if (strncmp(cmd, "quit", 4) == 0 || strncmp(cmd, "exit", 4) == 0)
            break;

        cmd[strcspn(cmd, "\r\n")] = '\0';

        if (send(fd, cmd, strlen(cmd), 0) == -1) {
            perror("send");
            break;
        }

        if (recv(fd, buf, BUF_SIZE, 0) == -1) {
            perror("recv");
            break;
        }

        printf("%s", buf);
    }

    close(fd);

    return 0;
}