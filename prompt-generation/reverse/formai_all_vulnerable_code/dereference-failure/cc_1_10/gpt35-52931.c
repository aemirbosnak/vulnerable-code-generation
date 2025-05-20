//FormAI DATASET v1.0 Category: Port Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PORTS 100                // Maximum number of ports to scan
#define DEFAULT_TIMEOUT_MS 200       // Default timeout period in milliseconds

void usage(char *name) {
    fprintf(stderr, "Usage: %s <hostname> [-p <port1,port2,...>] [-t <timeout_ms>]\n", name);
    exit(1);
}

int main(int argc, char **argv) {
    char *hostname, *ports_str = NULL;
    int timeout_ms = DEFAULT_TIMEOUT_MS;

    // Parse command line arguments
    if (argc < 2) {
        usage(argv[0]);
    }
    hostname = argv[1];
    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-p") == 0) {
            if (argc > i + 1) {
                ports_str = argv[i + 1];
            } else {
                usage(argv[0]);
            }
            i++;
        } else if (strcmp(argv[i], "-t") == 0) {
            if (argc > i + 1) {
                timeout_ms = atoi(argv[i + 1]);
                if (timeout_ms <= 0) {
                    fprintf(stderr, "Error: invalid timeout period\n");
                    exit(1);
                }
            } else {
                usage(argv[0]);
            }
            i++;
        } else {
            usage(argv[0]);
        }
    }

    // Resolve hostname to IP address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: could not resolve hostname\n");
        exit(1);
    }

    // Create socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        fprintf(stderr, "Error: could not create socket\n");
        exit(1);
    }

    // Set socket options
    struct timeval tv;
    tv.tv_sec = timeout_ms / 1000;
    tv.tv_usec = (timeout_ms % 1000) * 1000;
    setsockopt(sock_fd, SOL_SOCKET, SO_RCVTIMEO, (const char*) &tv, sizeof tv);
    setsockopt(sock_fd, SOL_SOCKET, SO_SNDTIMEO, (const char*) &tv, sizeof tv);

    // Try to connect to each port in the specified range
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr = *((struct in_addr*) host->h_addr);
    if (ports_str != NULL) {
        char *port_str = strtok(ports_str, ",");
        while (port_str != NULL) {
            int port = atoi(port_str);
            if (port < 1 || port > 65535) {
                fprintf(stderr, "Error: invalid port number\n");
                exit(1);
            }
            addr.sin_port = htons(port);
            if (connect(sock_fd, (struct sockaddr*) &addr, sizeof addr) == 0) {
                printf("Port %d is open\n", port);
            }
            port_str = strtok(NULL, ",");
        }
    } else {
        for (int port = 1; port <= MAX_PORTS; port++) {
            addr.sin_port = htons(port);
            if (connect(sock_fd, (struct sockaddr*) &addr, sizeof addr) == 0) {
                printf("Port %d is open\n", port);
            }
        }
    }

    // Clean up and exit
    close(sock_fd);
    exit(0);
}