//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define MAX_BUFF 1024
#define MAX_PORTS 65535

void scan_port(const char *host, int port) {
    struct sockaddr_in srv_addr;
    int sockfd;

    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sockfd == -1) {
        perror("socket");
        return;
    }

    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(port);
    srv_addr.sin_addr.s_addr = inet_addr(host);

    if(connect(sockfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr)) != -1) {
        printf("port %d is open\n", port);
    }

    close(sockfd);
}

int main(int argc, char **argv) {
    char *host;
    int start, end;
    struct hostent *he;

    if(argc != 4) {
        printf("Usage: %s <hostname/IP> <start port> <end port>\n", argv[0]);
        return -1;
    }

    host = argv[1];
    start = atoi(argv[2]);
    end = atoi(argv[3]);

    if(start < 1 || end > MAX_PORTS || start > end) {
        printf("Invalid port range!\n");
        return -1;
    }

    if(isdigit(*host)) {
        struct in_addr addr;
        inet_aton(host, &addr);
        he = gethostbyaddr(&addr, sizeof(addr), AF_INET);
    }
    else {
        he = gethostbyname(host);
    }

    if(he == NULL) {
        perror("gethostbyname");
        return -1;
    }

    printf("Scanning %s...\n", he->h_name);

    for(int i=start; i <= end; i++) {
        scan_port(he->h_addr_list[0], i);
    }

    return 0;
}