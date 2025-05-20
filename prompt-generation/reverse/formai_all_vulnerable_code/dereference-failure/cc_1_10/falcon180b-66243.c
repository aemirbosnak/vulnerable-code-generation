//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>

#define MAXHOSTNAMELEN 1024
#define MAXDATASIZE 1024

int main(int argc, char *argv[]) {
    int sock, ret;
    struct hostent *host;
    struct sockaddr_in addr;
    char hostname[MAXHOSTNAMELEN];
    char data[MAXDATASIZE];
    int datalen;
    struct timeval timeout;

    if (argc!= 3) {
        printf("Usage: %s <hostname> <data>\n", argv[0]);
        return 1;
    }

    strcpy(hostname, argv[1]);
    strcpy(data, argv[2]);
    datalen = strlen(data);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("socket() failed: %s\n", strerror(errno));
        return 1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(7);
    ret = inet_pton(AF_INET, hostname, &addr.sin_addr);
    if (ret <= 0) {
        printf("inet_pton() failed: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    ret = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == -1) {
        printf("connect() failed: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    send(sock, data, datalen, 0);
    memset(data, 0, MAXDATASIZE);
    ret = recv(sock, data, MAXDATASIZE, 0);
    if (ret <= 0) {
        printf("recv() failed: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    printf("Received data: %s\n", data);
    close(sock);

    return 0;
}