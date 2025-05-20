//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, n;
    struct sockaddr_in serv_addr;
    char buffer[BUF_SIZE];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <ip address> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        n = read(sock, buffer, BUF_SIZE);
        if (n < 0) {
            perror("read");
            exit(1);
        } else if (n == 0) {
            printf("Server closed connection\n");
            break;
        }

        printf("%s", buffer);
    }

    close(sock);

    return 0;
}