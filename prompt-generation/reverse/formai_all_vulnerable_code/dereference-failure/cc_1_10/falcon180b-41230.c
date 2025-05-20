//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int scan_port(int sock, int port);

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Invalid number of arguments.\n");
        return 1;
    }

    char *ip = argv[1];
    struct hostent *host = gethostbyname(ip);

    if (host == NULL) {
        printf("Invalid IP address.\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket.\n");
        return 1;
    }

    for (int i = 1; i <= MAX_PORTS; i++) {
        if (scan_port(sock, i)) {
            printf("Port %d is open.\n", i);
        }
    }

    close(sock);
    return 0;
}

int scan_port(int sock, int port) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        close(sock);
        return 1;
    } else if (errno!= ECONNREFUSED) {
        close(sock);
        return 0;
    }

    return 0;
}