//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

void die(const char *s)
{
    perror(s);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server;
    int addrlen = sizeof(server);
    char buf[BUF_SIZE];
    int n;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s host port\n", argv[0]);
        return 1;
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        die("socket");

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0)
        die("inet_pton");

    if (connect(sock, (struct sockaddr *)&server, addrlen) == -1)
        die("connect");

    while (fgets(buf, BUF_SIZE, stdin)!= NULL) {
        n = send(sock, buf, strlen(buf), 0);
        if (n == -1)
            die("send");
    }

    close(sock);

    return 0;
}