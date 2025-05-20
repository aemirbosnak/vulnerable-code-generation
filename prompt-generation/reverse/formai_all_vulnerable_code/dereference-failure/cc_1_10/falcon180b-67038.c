//Falcon-180B DATASET v1.0 Category: Firewall ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock_raw, sock_cooked;
    struct sockaddr_in server_addr;
    int opt = 1;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP Address> <Port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock_raw == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    setsockopt(sock_raw, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (bind(sock_raw, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    sock_cooked = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_cooked == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    setsockopt(sock_cooked, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sock_cooked, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int nbytes;
        char *ptr;

        nbytes = recv(sock_raw, buffer, BUFFER_SIZE, 0);
        if (nbytes == -1) {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        for (ptr = buffer; ptr < buffer + nbytes; ptr++) {
            if (*ptr == '\n') {
                *ptr = '\0';
                break;
            }
        }

        send(sock_cooked, buffer, strlen(buffer), 0);
    }

    close(sock_raw);
    close(sock_cooked);

    return 0;
}