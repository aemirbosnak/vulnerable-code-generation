//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_DATA 1024

void die(const char *s) {
    perror(s);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sock, ret;
    struct sockaddr_in addr;
    char data[MAX_DATA];

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        return 1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) <= 0) {
        die("Invalid IP address");
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        die("socket");
    }

    ret = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == -1) {
        if (errno == EINPROGRESS) {
            printf("Connecting...\n");
            ret = 0;
        } else {
            die("connect");
        }
    }

    while (ret == 0) {
        memset(data, 0, sizeof(data));
        ret = recv(sock, data, MAX_DATA, 0);
        if (ret <= 0) {
            if (ret == 0) {
                printf("Connection closed by server\n");
            } else {
                die("recv");
            }
            break;
        }
        printf("Received: %s", data);
    }

    close(sock);
    return 0;
}