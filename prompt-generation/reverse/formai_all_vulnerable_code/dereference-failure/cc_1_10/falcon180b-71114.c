//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#define MAX_PORTS 65535

int scan_ports(char *hostname, int start_port, int end_port) {
    int sock, port;
    struct hostent *server;
    struct sockaddr_in address;
    char *error;

    if ((server = gethostbyname(hostname)) == NULL) {
        fprintf(stderr, "Error: %s\n", hstrerror(h_errno));
        exit(1);
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(start_port);
    address.sin_addr = *((struct in_addr *)server->h_addr);

    for (port = start_port; port <= end_port; port++) {
        if (connect(sock, (struct sockaddr *)&address, sizeof(address)) == 0) {
            close(sock);
            printf("Port %d is open\n", port);
        } else {
            error = strerror(errno);
            if (strcmp(error, "Connection refused") == 0) {
                printf("Port %d is closed\n", port);
            } else {
                printf("Error on port %d: %s\n", port, error);
            }
        }
        address.sin_port = htons(port);
    }

    close(sock);
    return 0;
}

int main(int argc, char *argv[]) {
    char *hostname;
    int start_port, end_port;

    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        exit(1);
    }

    hostname = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    if (start_port > end_port || start_port < 1 || end_port > MAX_PORTS) {
        fprintf(stderr, "Invalid port range\n");
        exit(1);
    }

    scan_ports(hostname, start_port, end_port);

    return 0;
}