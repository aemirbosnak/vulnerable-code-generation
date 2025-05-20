//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char **argv)
{
    int sock;
    struct sockaddr_in si_other;
    socklen_t slen = sizeof(si_other);
    char buf[BUF_SIZE];
    int len;
    int status;

    if (argc!= 3)
    {
        fprintf(stderr, "Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        perror("socket failed");
        exit(1);
    }

    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(atoi(argv[2]));
    si_other.sin_addr.s_addr = inet_addr(argv[1]);

    status = connect(sock, (struct sockaddr *)&si_other, slen);
    if (status == -1)
    {
        perror("connect failed");
        exit(1);
    }

    while (1)
    {
        memset(buf, 0, BUF_SIZE);
        len = recv(sock, buf, BUF_SIZE, 0);
        if (len <= 0)
        {
            break;
        }
        printf("%s", buf);
    }

    close(sock);
    return 0;
}