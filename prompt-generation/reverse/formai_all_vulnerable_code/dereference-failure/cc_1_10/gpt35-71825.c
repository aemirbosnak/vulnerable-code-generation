//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_PORT 65535

void scan_port(const char *host, int port);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [host]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get IP address from hostname
    struct addrinfo *result;
    int status = getaddrinfo(argv[1], NULL, NULL, &result);
    if (status != 0) {
        printf("Error: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    // Display IP address
    char ip[INET6_ADDRSTRLEN];
    void *addr = &((struct sockaddr_in *) result->ai_addr)->sin_addr;
    inet_ntop(result->ai_family, addr, ip, sizeof(ip));
    printf("Scanning ports on %s (%s):\n", argv[1], ip);

    freeaddrinfo(result);

    // Scan ports
    for (int port = 1; port <= MAX_PORT; port++) {
        scan_port(argv[1], port);
    }

    return 0;
}

void scan_port(const char *host, int port) {
    struct addrinfo hints;
    struct addrinfo *res;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    char port_str[6];
    sprintf(port_str, "%d", port);

    int status = getaddrinfo(host, port_str, &hints, &res);
    if (status != 0) {
        return;
    }

    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        return;
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        return;
    }

    char ip[INET6_ADDRSTRLEN];
    void *addr = &((struct sockaddr_in *) res->ai_addr)->sin_addr;
    inet_ntop(res->ai_family, addr, ip, sizeof(ip));

    printf("Port %d open on %s\n", port, ip);

    close(sockfd);
}