//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define MAX_HOST_LEN 1025
#define MAX_DATA_LEN 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
        printf("gethostbyname error\n");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr.s_addr, he->h_addr, he->h_length);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    char request[MAX_DATA_LEN];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", host);

    send(sock, request, strlen(request), 0);

    char buf[MAX_DATA_LEN];
    int len = recv(sock, buf, sizeof(buf), 0);
    if (len <= 0) {
        perror("recv");
        exit(1);
    }

    printf("Received %d bytes:\n%s\n", len, buf);

    close(sock);
    return 0;
}