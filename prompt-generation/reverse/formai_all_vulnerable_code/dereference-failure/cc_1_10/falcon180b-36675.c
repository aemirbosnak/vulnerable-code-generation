//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    int sock;
    struct hostent *host;
    char *ip;
    int port;
    int opt = 1;
    char buffer[BUF_SIZE];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    ip = argv[1];
    port = atoi(argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    host = gethostbyname(ip);
    if (host == NULL) {
        fprintf(stderr, "Error resolving host: %s\n", ip);
        exit(1);
    }

    memcpy(&buffer, host->h_addr, host->h_length);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = *(uint32_t *)buffer;

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        fprintf(stderr, "Error connecting: %s\n", strerror(errno));
        exit(1);
    }

    char request[BUF_SIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", ip);

    write(sock, request, strlen(request));

    char response[BUF_SIZE];
    memset(response, 0, BUF_SIZE);
    int len = read(sock, response, BUF_SIZE);

    if (len == -1) {
        fprintf(stderr, "Error reading response: %s\n", strerror(errno));
        exit(1);
    }

    close(sock);

    printf("Response:\n%s", response);

    return 0;
}