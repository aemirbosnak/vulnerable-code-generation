//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_PORT 65535

void scan_ports(char *address, int port_start, int port_end);

void scan_ports(char *address, int port_start, int port_end) {
    int sockfd, port;
    struct sockaddr_in server;

    for(port=port_start; port <= port_end; port++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if(sockfd < 0) {
            printf("Can't open socket");
            continue;
        }

        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        inet_pton(AF_INET, address, &server.sin_addr);

        if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) >= 0) {
            printf("Port %d is open\n", port);
            close(sockfd);
        }
    }

    printf("Port scan complete\n");
}

int main(int argc, char *argv[]) {
    char *hostname;
    int port_start, port_end;

    if(argc < 4) {
        printf("Usage: %s <hostname> <port start> <port end>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    hostname = argv[1];
    port_start = atoi(argv[2]);
    port_end = atoi(argv[3]);

    struct hostent *host = gethostbyname(hostname);
    if(host == NULL) {
        printf("Error resolving hostname %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    char *address = inet_ntoa(*((struct in_addr*) host->h_addr_list[0]));

    printf("Scanning ports on %s:%d-%d\n", address, port_start, port_end);

    scan_ports(address, port_start, port_end);

    return EXIT_SUCCESS;
}