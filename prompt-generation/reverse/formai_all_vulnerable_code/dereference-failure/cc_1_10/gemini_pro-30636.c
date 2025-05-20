//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_PORTS 10000
#define MAX_HOST_LEN 256

typedef struct host_port {
    char host[MAX_HOST_LEN];
    int port;
} host_port_t;

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port1> [port2] ... [portN]\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *host = argv[1];
    int num_ports = argc - 2;
    host_port_t *ports = malloc(sizeof(host_port_t) * num_ports);
    if (ports == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < num_ports; i++) {
        strcpy(ports[i].host, host);
        ports[i].port = atoi(argv[i + 2]);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(host);
    for (int i = 0; i < num_ports; i++) {
        servaddr.sin_port = htons(ports[i].port);
        int conn = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
        if (conn < 0) {
            printf("Port %d: closed\n", ports[i].port);
        } else {
            printf("Port %d: open\n", ports[i].port);
            close(conn);
        }
    }

    close(sockfd);
    free(ports);
    return EXIT_SUCCESS;
}