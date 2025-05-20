//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>

int scan(int sock, struct sockaddr_in target);

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    char *ip = argv[1];
    struct sockaddr_in target;
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, ip, &target.sin_addr);

    if (connect(sock, (struct sockaddr *)&target, sizeof(target)) < 0) {
        close(sock);
        return 1;
    }

    puts("Connected to target");
    return 0;
}

int scan(int sock, struct sockaddr_in target) {
    int port = 1;
    while (port <= 65535) {
        struct sockaddr_in server;
        memset(&server, 0, sizeof(server));
        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        server.sin_addr.s_addr = target.sin_addr.s_addr;

        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }

        port++;
    }

    close(sock);
    return 0;
}