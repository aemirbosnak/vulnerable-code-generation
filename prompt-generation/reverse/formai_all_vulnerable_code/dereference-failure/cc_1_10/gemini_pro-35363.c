//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef struct {
    unsigned short port;
    char *hostname;
    int sockfd;
} port_scan_t;

port_scan_t *port_scan_init(unsigned short port, char *hostname) {
    port_scan_t *port_scan = malloc(sizeof(port_scan_t));
    if (port_scan == NULL) {
        perror("malloc");
        return NULL;
    }

    port_scan->port = port;
    port_scan->hostname = hostname;
    port_scan->sockfd = -1;

    return port_scan;
}

int port_scan_open(port_scan_t *port_scan) {
    struct sockaddr_in addr;

    port_scan->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (port_scan->sockfd < 0) {
        perror("socket");
        return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port_scan->port);
    addr.sin_addr.s_addr = inet_addr(port_scan->hostname);

    if (connect(port_scan->sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        if (errno == ECONNREFUSED) {
            return 0; // port is closed
        } else {
            perror("connect");
            return -1;
        }
    }

    return 1; // port is open
}

void port_scan_close(port_scan_t *port_scan) {
    if (port_scan->sockfd >= 0) {
        close(port_scan->sockfd);
        port_scan->sockfd = -1;
    }
}

void port_scan_free(port_scan_t *port_scan) {
    if (port_scan != NULL) {
        free(port_scan);
        port_scan = NULL;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    unsigned short port = atoi(argv[2]);

    port_scan_t *port_scan = port_scan_init(port, hostname);
    if (port_scan == NULL) {
        return EXIT_FAILURE;
    }

    int result = port_scan_open(port_scan);
    if (result < 0) {
        fprintf(stderr, "Error opening port %d on hostname %s\n", port, hostname);
        port_scan_free(port_scan);
        return EXIT_FAILURE;
    }

    printf("Port %d on hostname %s is ", port, hostname);
    if (result == 0) {
        printf("closed\n");
    } else {
        printf("open\n");
    }

    port_scan_close(port_scan);
    port_scan_free(port_scan);

    return EXIT_SUCCESS;
}