//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

void diep(const char *s) {
    perror(s);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buf[BUF_SIZE];
    char *host = argv[1];
    char *port = argv[2];
    int port_num;

    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    port_num = atoi(port);

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        diep("socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_num);
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        diep("inet_pton");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        diep("connect");
    }

    while (1) {
        memset(buf, 0, BUF_SIZE);
        if ((recv(sock, buf, BUF_SIZE, 0)) <= 0) {
            diep("recv");
        }
        printf("%s", buf);
    }

    close(sock);
    return 0;
}