//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int scan_ports(char *hostname, int start_port, int end_port)
{
    int sock, ret, port;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(start_port);

    ret = inet_pton(AF_INET, hostname, &server.sin_addr);
    if (ret <= 0) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    for (port = start_port; port <= end_port; port++) {
        server.sin_port = htons(port);

        ret = connect(sock, (struct sockaddr *)&server, sizeof(server));
        if (ret == 0) {
            printf("Port %d is open\n", port);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else if (errno == ETIMEDOUT) {
            printf("Connection timed out on port %d\n", port);
        } else {
            printf("Error on port %d: %s\n", port, strerror(errno));
        }
    }

    close(sock);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc!= 4) {
        printf("Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port || start_port < 1 || end_port > MAX_PORTS) {
        printf("Invalid port range\n");
        exit(1);
    }

    scan_ports(hostname, start_port, end_port);

    return 0;
}