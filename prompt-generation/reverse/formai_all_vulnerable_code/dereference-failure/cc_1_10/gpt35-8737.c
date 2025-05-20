//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_HOSTS 1024

struct host {
    char hostname[256];
    struct in_addr addr;
    int scanned;
};

int nhosts = 0;
struct host hosts[MAX_HOSTS];

int scan_host(struct host *h) {
    if (h->scanned) {
        return 0;
    }
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(22);
    addr.sin_addr = h->addr;
    int res = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (res == 0) {
        printf("%s\tup\n", h->hostname);
        h->scanned = 1;
    } else {
        printf("%s\tdown\n", h->hostname);
    }
    close(sockfd);
    return 1;
}

int scan_network(char *network) {
    char *net, *mask;
    net = strtok(network, "/");
    mask = strtok(NULL, "/");
    if (mask == NULL) {
        mask = "24";
    }
    struct in_addr netaddr, maskaddr;
    inet_aton(net, &netaddr);
    inet_aton("255.255.255.0", &maskaddr); // default mask
    int bits = 32 - atoi(mask);
    maskaddr.s_addr = htonl((0xFFFFFFFF << bits) & 0xFFFFFFFF);
    int i;
    for (i = 1; i < (1 << bits) - 1; i++) {
        struct in_addr addr = netaddr;
        addr.s_addr |= htonl(i);
        char *hostname = inet_ntoa(addr);
        strncpy(hosts[nhosts].hostname, hostname, 256);
        hosts[nhosts].addr = addr;
        hosts[nhosts].scanned = 0;
        nhosts++;
    }
    int nscanned = 0;
    do {
        nscanned = 0;
        for (i = 0; i < nhosts; i++) {
            nscanned += scan_host(&hosts[i]);
        }
    } while (nscanned < nhosts);
    return 1;
}

int main(int argc, char **argv) {
    if (argc < 2 || argc > 3) {
        printf("Usage: %s network [/mask]\n", argv[0]);
        return 1;
    }
    scan_network(argv[1]);
    return 0;
}