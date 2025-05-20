//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage:./port_scanner <IP Address> <Port Range>\n");
        return 1;
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + MAX_PORTS - 1;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(start_port);
    inet_pton(AF_INET, ip, &server.sin_addr);

    char buffer[BUFFER_SIZE];

    while (start_port <= end_port) {
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open\n", start_port);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", start_port);
        } else {
            printf("Error on port %d\n", start_port);
        }
        start_port++;
    }

    close(sock);
    return 0;
}