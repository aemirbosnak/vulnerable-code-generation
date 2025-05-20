//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void scan_ports(char *hostname, int start_port, int end_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error resolving hostname: %s\n", strerror(errno));
        exit(1);
    }

    struct in_addr *addr = (struct in_addr *)host->h_addr;
    memset(&(struct sockaddr_in) {
       .sin_family = AF_INET,
       .sin_port = htons(start_port),
       .sin_addr = *addr
    }, 0, sizeof(struct sockaddr_in));

    for (int port = start_port; port <= end_port; port++) {
        if (connect(sock, (struct sockaddr *)&(struct sockaddr_in) {
               .sin_family = AF_INET,
               .sin_port = htons(port),
               .sin_addr = *addr
            }, sizeof(struct sockaddr_in)) == 0) {
            printf("Port %d is open\n", port);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Error connecting to port %d: %s\n", port, strerror(errno));
        }
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port || start_port < 1 || end_port > MAX_PORTS) {
        fprintf(stderr, "Invalid port range\n");
        exit(1);
    }

    scan_ports(hostname, start_port, end_port);

    return 0;
}