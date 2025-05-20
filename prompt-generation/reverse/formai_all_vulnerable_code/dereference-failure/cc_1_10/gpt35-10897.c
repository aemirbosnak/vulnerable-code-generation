//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    char *hostname = argv[1];
    struct hostent *host;
    struct sockaddr_in addr;

    if (argc < 2) {
        fprintf(stderr, "usage: %s hostname\n", argv[0]);
        return 1;
    }

    if ((host = gethostbyname(hostname)) == NULL) {
        fprintf(stderr, "%s: unknown host\n", hostname);
        return 2;
    }

    memset(&addr, 0, sizeof(addr));
    memcpy(&addr.sin_addr.s_addr, host->h_addr_list[0], sizeof(addr.sin_addr.s_addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);

    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("socket");
        return 3;
    }

    if (connect(fd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("connect");
        return 4;
    }

    struct sockaddr_in localaddr;
    socklen_t addrlen = sizeof(localaddr);

    if (getsockname(fd, (struct sockaddr *) &localaddr, &addrlen) < 0) {
        perror("getsockname");
        return 5;
    }

    char ipaddr[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &localaddr.sin_addr.s_addr, ipaddr, sizeof(ipaddr));

    printf("Local address for %s:%d is %s\n", hostname, ntohs(localaddr.sin_port), ipaddr);

    char cmd[BUFSIZE];
    snprintf(cmd, BUFSIZE, "nmap -sP %s/24", ipaddr);

    int status = system(cmd);
    if (status < 0) {
        perror("system");
        return 6;
    }

    return 0;
}