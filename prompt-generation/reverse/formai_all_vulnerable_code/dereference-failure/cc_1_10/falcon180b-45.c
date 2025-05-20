//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>

#define MAX 65535
#define TRUE 1
#define FALSE 0
#define DEBUG 0

#ifdef DEBUG
#define debug(args...) fprintf(stdout, args)
#else
#define debug(args...)
#endif

int scan(char *hostname, int start_port, int end_port);

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

    scan(hostname, start_port, end_port);

    return 0;
}

int scan(char *hostname, int start_port, int end_port) {
    int sock, port;
    struct sockaddr_in server;
    int opt = 1;
    char buffer[1024];
    int bytes_received;

    for (port = start_port; port <= end_port; port++) {
        memset(&server, 0, sizeof(server));
        server.sin_family = AF_INET;
        server.sin_port = htons(port);

        if (inet_pton(AF_INET, hostname, &server.sin_addr) <= 0) {
            if (DEBUG) {
                fprintf(stdout, "Invalid hostname or IP address\n");
            }
            continue;
        }

        sock = socket(AF_INET, SOCK_STREAM, 0);

        if (sock == -1) {
            if (DEBUG) {
                perror("socket");
            }
            continue;
        }

        if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
            if (DEBUG) {
                perror("setsockopt");
            }
            close(sock);
            continue;
        }

        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            if (DEBUG) {
                fprintf(stdout, "Port %d: Open\n", port);
            }
        } else if (errno == ECONNREFUSED) {
            if (DEBUG) {
                fprintf(stdout, "Port %d: Closed\n", port);
            }
        } else {
            if (DEBUG) {
                perror("connect");
            }
        }

        close(sock);
    }

    return 0;
}