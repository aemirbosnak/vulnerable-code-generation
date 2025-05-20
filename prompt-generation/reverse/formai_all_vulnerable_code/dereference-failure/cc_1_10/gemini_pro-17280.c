//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 1024

struct port_scan_result {
    int port;
    char *state;
};

struct port_scan_result scan_port(char *host, int port) {
    struct port_scan_result result;
    result.port = port;
    result.state = "closed";

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return result;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) == 0) {
        result.state = "open";
    }

    close(sockfd);
    return result;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <host> <port1,port2,...>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    char *ports = argv[2];

    char *port_strtok = strtok(ports, ",");
    while (port_strtok != NULL) {
        int port = atoi(port_strtok);
        if (port < 0 || port > MAX_PORTS) {
            printf("Invalid port: %d\n", port);
            return 1;
        }

        struct port_scan_result result = scan_port(host, port);
        printf("Port %d: %s\n", result.port, result.state);

        port_strtok = strtok(NULL, ",");
    }

    return 0;
}