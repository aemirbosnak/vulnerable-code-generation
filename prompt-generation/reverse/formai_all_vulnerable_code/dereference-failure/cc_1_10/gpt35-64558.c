//FormAI DATASET v1.0 Category: Port Scanner ; Style: grateful
/* Welcome to my Grateful Port Scanner! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    printf("Scanning ports on %s...\n", ip);

    int sock, error, optval;
    struct sockaddr_in target;
    char buffer[BUFFER_SIZE];
    fd_set fds;

    for(int port = start_port; port <= end_port; port++) {
        sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if(sock == -1) {
            continue;
        }

        target.sin_family = AF_INET;
        target.sin_port = htons(port);
        inet_pton(AF_INET, ip, &target.sin_addr);

        error = connect(sock, (struct sockaddr *)&target, sizeof(struct sockaddr_in));
        if(error == -1) {
            close(sock);
            continue;
        }

        FD_ZERO(&fds);
        FD_SET(sock, &fds);
        struct timeval tv;
        tv.tv_sec = 1;
        tv.tv_usec = 0;

        optval = 1;
        setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

        error = send(sock, "Hello, world!", 13, 0);
        if(error == -1) {
            close(sock);
            continue;
        }

        error = select(sock + 1, &fds, NULL, NULL, &tv);
        if(error == -1) {
            close(sock);
            continue;
        }
        else if(error == 0) {
            close(sock);
            continue;
        }

        memset(buffer, 0, BUFFER_SIZE);
        error = recv(sock, buffer, BUFFER_SIZE, 0);

        printf("Port %d is open!\n", port);
        close(sock);
    }

    printf("Done scanning ports on %s.\n", ip);

    return 0;
}