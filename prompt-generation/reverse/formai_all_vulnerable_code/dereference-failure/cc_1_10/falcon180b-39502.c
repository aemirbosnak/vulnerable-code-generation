//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_PORTS 65535
#define BUF_SIZE 1024

void die(const char* msg) {
    perror(msg);
    exit(1);
}

void print_usage(const char* program_name) {
    fprintf(stderr, "Usage: %s <hostname> <start_port> <end_port>\n", program_name);
}

int is_valid_port(int port) {
    if (port <= 0 || port > MAX_PORTS) {
        return 0;
    }
    return 1;
}

int main(int argc, char** argv) {
    if (argc!= 4) {
        print_usage(argv[0]);
        return 1;
    }

    const char* hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (!is_valid_port(start_port) ||!is_valid_port(end_port)) {
        die("Invalid port range.");
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        die("socket");
    }

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, NULL, &hints, &res)!= 0) {
        die("getaddrinfo");
    }

    char buf[BUF_SIZE];
    for (int port = start_port; port <= end_port; port++) {
        if (connect(sock, res->ai_addr, res->ai_addrlen) == -1) {
            if (errno == ECONNREFUSED) {
                printf("Port %d is closed.\n", port);
            } else if (errno == ETIMEDOUT) {
                printf("Port %d is filtered.\n", port);
            } else {
                printf("Error on port %d: %s\n", port, strerror(errno));
            }
        } else {
            printf("Port %d is open.\n", port);
            close(sock);
            break;
        }
    }

    freeaddrinfo(res);
    close(sock);

    return 0;
}