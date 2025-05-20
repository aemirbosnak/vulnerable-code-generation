//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 8192

int main(int argc, char *argv[]) {
    int sd, n;
    struct sockaddr_in server_addr;
    char buffer[BUFSIZE];
    char *hostname = argv[1];
    int port = atoi(argv[2]);
    int opt = 1;

    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0) {
        printf("socket() failed\n");
        exit(1);
    }

    if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("setsockopt() failed\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        printf("inet_pton() failed\n");
        exit(1);
    }

    if (connect(sd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("connect() failed\n");
        exit(1);
    }

    while (1) {
        n = read(sd, buffer, BUFSIZE);
        if (n <= 0) {
            printf("read() failed\n");
            exit(1);
        }
        printf("%s", buffer);
    }

    close(sd);

    return 0;
}