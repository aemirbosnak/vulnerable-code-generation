//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error: %s not found.\n", argv[1]);
        return 1;
    }

    char *ip = inet_ntoa(*(struct in_addr *)host->h_addr);
    if (ip == NULL) {
        fprintf(stderr, "Error: Invalid IP address.\n");
        return 1;
    }

    printf("Scanning %s...\n", ip);

    int port = 0;
    for (port = 0; port < 65535; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            perror("Error creating socket");
            continue;
        }

        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr(ip);

        int ret = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
        if (ret == -1) {
            perror("Error connecting to socket");
            continue;
        }

        if (ret == 0) {
            printf("Port %d is open\n", port);
        }

        close(sock);
    }

    return 0;
}