//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define MAX_HOSTNAME_LEN 1024

int main(int argc, char *argv[])
{
    int sock, ret;
    struct sockaddr_in dest;
    char hostname[MAX_HOSTNAME_LEN];
    int port;
    int timeout;
    char *endptr;

    if (argc!= 4) {
        printf("Usage: %s <hostname> <port> <timeout>\n", argv[0]);
        return 1;
    }

    strcpy(hostname, argv[1]);
    port = atoi(argv[2]);
    timeout = atoi(argv[3]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("socket() failed: %s\n", strerror(errno));
        return 1;
    }

    dest.sin_family = AF_INET;
    dest.sin_port = htons(port);
    ret = inet_pton(AF_INET, hostname, &dest.sin_addr);
    if (ret == 0) {
        printf("inet_pton() failed: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    ret = connect(sock, (struct sockaddr *)&dest, sizeof(dest));
    if (ret == -1) {
        printf("connect() failed: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout)) == -1) {
        printf("setsockopt() failed: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    if (send(sock, "PING\r\n", strlen("PING\r\n"), 0) == -1) {
        printf("send() failed: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    char buf[1024];
    memset(buf, 0, sizeof(buf));
    ret = recv(sock, buf, sizeof(buf), 0);
    if (ret <= 0) {
        printf("recv() failed: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    buf[ret] = '\0';
    printf("Received: %s\n", buf);

    close(sock);

    return 0;
}