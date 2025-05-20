//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s host port\n", argv[0]);
        exit(1);
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        exit(1);
    }

    char *request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
    if (send(sock, request, strlen(request), 0) == -1) {
        perror("send");
        exit(1);
    }

    char buffer[1024];
    int n;
    while ((n = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, 1, n, stdout);
    }

    if (n == -1) {
        perror("recv");
        exit(1);
    }

    close(sock);
    return 0;
}