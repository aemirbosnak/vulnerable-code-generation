//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void scan_ports(char *hostname, int start_port, int end_port) {
    int sock;
    struct sockaddr_in server;
    int port;
    char buffer[BUFFER_SIZE];
    char *response;
    int response_len;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket. ");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(start_port);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server))!= 0) {
        printf("Connection failed. ");
        close(sock);
        exit(1);
    }

    printf("Scanning ports on %s...\n", hostname);

    for (port = start_port; port <= end_port; port++) {
        server.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open.\n", port);
        } else {
            printf("Port %d is closed.\n", port);
        }
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    scan_ports(hostname, start_port, end_port);

    return 0;
}