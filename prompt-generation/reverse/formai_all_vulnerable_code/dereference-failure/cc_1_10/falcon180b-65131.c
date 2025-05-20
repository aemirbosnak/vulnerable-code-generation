//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    int opt = 1;
    char buffer[MAX_DATA];
    int n;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    strncpy(server.sin_zero, "", sizeof(server.sin_zero));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server.sin_addr);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "socket() failed: %s\n", strerror(errno));
        exit(1);
    }

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        fprintf(stderr, "setsockopt() failed: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        fprintf(stderr, "connect() failed: %s\n", strerror(errno));
        exit(1);
    }

    while (1) {
        memset(buffer, 0, MAX_DATA);
        n = recv(sock, buffer, MAX_DATA, 0);
        if (n <= 0) {
            fprintf(stderr, "recv() failed: %s\n", strerror(errno));
            exit(1);
        }

        printf("Received: %s\n", buffer);
    }

    close(sock);
    return 0;
}