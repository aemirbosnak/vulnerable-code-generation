//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_OPEN_PORTS 1024
#define PORT_RANGE_START 1
#define PORT_RANGE_END 65535

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname or IP address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    struct hostent *host = gethostbyname(hostname);
    if (!host) {
        herror("gethostbyname");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT_RANGE_START);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    int num_open_ports = 0;
    int port;
    for (port = PORT_RANGE_START; port <= PORT_RANGE_END; port++) {
        server_addr.sin_port = htons(port);
        int connfd = connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
        if (connfd < 0 && errno != ECONNREFUSED) {
            perror("connect");
            return EXIT_FAILURE;
        }

        if (connfd >= 0) {
            close(connfd);
            printf("Port %d is open\n", port);
            num_open_ports++;
            if (num_open_ports >= MAX_OPEN_PORTS) {
                break;
            }
        }
    }

    close(sockfd);

    if (num_open_ports == 0) {
        printf("No open ports were found\n");
    }

    return EXIT_SUCCESS;
}