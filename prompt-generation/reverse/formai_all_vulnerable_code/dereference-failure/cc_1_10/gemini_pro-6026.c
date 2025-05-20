//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_PORTS 65535
#define MAX_HOSTNAME 256
#define TIMEOUT_SECS 1

static int port_scanner(const char *hostname, int start_port, int end_port) {
    struct sockaddr_in addr;
    struct hostent *host;
    int sockfd, i;
    clock_t start, end;

    printf("Scanning %s for open ports from %d to %d:\n", hostname, start_port, end_port);
    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", hostname);
        return -1;
    }

    for (i = start_port; i <= end_port; i++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            fprintf(stderr, "Error: could not create socket\n");
            return -1;
        }

        addr.sin_family = AF_INET;
        addr.sin_port = htons(i);
        addr.sin_addr = *(struct in_addr *) host->h_addr;

        start = clock();
        int conn = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));
        end = clock();
        close(sockfd);

        if (conn == 0) {
            printf("Port %d: open (%ld ms)\n", i, (end - start) / (CLOCKS_PER_SEC / 1000));
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    const char *hostname;
    int start_port, end_port;
    
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        return -1;
    }

    hostname = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    if (start_port < 0 || start_port > MAX_PORTS || end_port < 0 || end_port > MAX_PORTS) {
        fprintf(stderr, "Error: invalid port range\n");
        return -1;
    }

    return port_scanner(hostname, start_port, end_port);
}