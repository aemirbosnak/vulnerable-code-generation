//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define MAX_PORTS 1000
#define MAX_HOST_LEN 256

struct host_port {
    char host[MAX_HOST_LEN];
    int ports[MAX_PORTS];
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <host> [<port> <port> ...]\n", argv[0]);
        return 1;
    }

    struct host_port host_ports;
    memset(&host_ports, 0, sizeof(host_ports));
    strcpy(host_ports.host, argv[1]);

    int i;
    for (i = 2; i < argc; i++) {
        int port = atoi(argv[i]);
        if (port <= 0 || port > 65535) {
            printf("Invalid port: %d\n", port);
            return 1;
        }
        host_ports.ports[i - 2] = port;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    if (inet_aton(host_ports.host, &server_addr.sin_addr) == 0) {
        printf("Invalid host: %s\n", host_ports.host);
        close(sockfd);
        return 1;
    }

    for (i = 0; i < MAX_PORTS && host_ports.ports[i] != 0; i++) {
        server_addr.sin_port = htons(host_ports.ports[i]);
        if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open on host %s\n", host_ports.ports[i], host_ports.host);
        } else {
            printf("Port %d is closed on host %s\n", host_ports.ports[i], host_ports.host);
        }
    }

    close(sockfd);
    return 0;
}