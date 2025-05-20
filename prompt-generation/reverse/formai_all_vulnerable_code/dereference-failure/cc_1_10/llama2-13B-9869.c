//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_HOST_LEN 1024
#define MAX_PORT_LEN 64

struct host_port {
    char host[MAX_HOST_LEN];
    int port;
};

void init_host_port(struct host_port *hp, char *host, int port) {
    strcpy(hp->host, host);
    hp->port = port;
}

void scan_host(struct host_port *hp, int sock) {
    char buffer[256];
    socklen_t address_len = sizeof(hp->host);
    getsockname(sock, (struct sockaddr *)&hp->host, &address_len);
    printf("Scanning host %s...\n", hp->host);

    // Scan for open ports
    for (int i = 1; i <= 65535; i++) {
        struct sockaddr_in serv_addr;
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(i);
        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0) {
            printf("Port %d is open on %s\n", i, hp->host);
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <host> <port_range>\n", argv[0]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        return 2;
    }

    struct host_port hp;
    init_host_port(&hp, argv[1], atoi(argv[2]));

    scan_host(&hp, sock);

    close(sock);
    return 0;
}