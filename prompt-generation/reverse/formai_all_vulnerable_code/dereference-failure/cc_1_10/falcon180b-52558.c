//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sock, ret;
    struct sockaddr_in server;
    char buf[BUF_SIZE];

    if (argc!= 3)
    {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        error("socket()");

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(atoi(argv[2]));

    ret = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (ret == -1)
        error("connect()");

    printf("Connected to %s:%d\n", argv[1], atoi(argv[2]));

    while (1)
    {
        memset(buf, 0, BUF_SIZE);
        ret = read(sock, buf, BUF_SIZE);
        if (ret <= 0)
        {
            error("read()");
        }
        printf("%s", buf);
    }

    close(sock);
    return 0;
}