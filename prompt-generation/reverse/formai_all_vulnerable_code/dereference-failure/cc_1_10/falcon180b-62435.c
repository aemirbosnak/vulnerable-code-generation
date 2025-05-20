//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int sock, port = 0;
    struct hostent *server;
    char *ip;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage:./port_scanner <IP Address> <Port Range>\n");
        exit(1);
    }

    ip = argv[1];
    port = atoi(argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    while (port <= MAX) {
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open.\n", port);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed.\n", port);
        } else {
            printf("Error connecting to port %d: %s\n", port, strerror(errno));
        }
        close(sock);
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Error creating socket: %s\n", strerror(errno));
            exit(1);
        }
        port++;
    }

    close(sock);
    return 0;
}