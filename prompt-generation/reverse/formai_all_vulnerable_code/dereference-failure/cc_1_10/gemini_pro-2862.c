//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PORTS 100

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <hostname> <port1> [port2] ... [portN]\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    int ports[MAX_PORTS];
    int num_ports = argc - 2;
    for (int i = 0; i < num_ports; i++) {
        ports[i] = atoi(argv[i + 2]);
    }

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: could not resolve hostname %s\n", hostname);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < num_ports; i++) {
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            printf("Error: could not create socket\n");
            return EXIT_FAILURE;
        }

        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr = *(struct in_addr *) host->h_addr;
        addr.sin_port = htons(ports[i]);

        int connect_result = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));
        if (connect_result < 0) {
            printf("Port %d: closed\n", ports[i]);
        } else {
            printf("Port %d: open\n", ports[i]);
        }

        close(sockfd);
    }

    return EXIT_SUCCESS;
}