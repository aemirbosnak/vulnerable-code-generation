//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535
#define PORT_OFFSET (1024 - 1)
#define MAX_HOSTS 1
#define MAX_NAME 256

void printUsage() {
    printf("Usage: c_port_scanner [-t timeout] [-p port_offset] [-n hostname]\n");
    printf("Options:\n");
    printf("  -t timeout         Specify the timeout value in seconds\n");
    printf("  -p port_offset      Specify the port offset value\n");
    printf("  -n hostname         Specify the hostname to scan\n");
}

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 4) {
        printUsage();
        exit(1);
    }

    int timeout = 1;
    int port_offset = PORT_OFFSET;
    char* hostname = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-t") == 0) {
            timeout = atoi(argv[i+1]);
        } else if (strcmp(argv[i], "-p") == 0) {
            port_offset = atoi(argv[i+1]);
        } else if (strcmp(argv[i], "-n") == 0) {
            hostname = argv[i+1];
        } else {
            printf("Unknown option: %s\n", argv[i]);
            exit(1);
        }
    }

    if (timeout <= 0 || port_offset < 0 || port_offset > (MAX_PORTS - 1)) {
        printf("Invalid option: -t, -p, or -n\n");
        exit(1);
    }

    if (hostname == NULL) {
        printf("Please specify the hostname to scan\n");
        exit(1);
    }

    int num_hosts = 0;
    if (argc > 3) {
        num_hosts = atoi(argv[3]);
        if (num_hosts < 1 || num_hosts > MAX_HOSTS) {
            printf("Invalid number of hosts: %s\n", argv[3]);
            exit(1);
        }
    }

    struct hostent* host;
    struct in_addr* ipv4_address;

    for (int i = 0; i < num_hosts; i++) {
        if (inet_pton(AF_INET, hostname, &ipv4_address) == 1) {
            host = gethostbyaddr((const void*)&ipv4_address, sizeof(struct in_addr), AF_INET);
            if (host == NULL) {
                printf("Error: Failed to resolve hostname: %s\n", hostname);
                exit(1);
            }
        } else {
            printf("Error: Invalid hostname: %s\n", hostname);
            exit(1);
        }

        for (int port = port_offset; port <= (port_offset + MAX_PORTS); port++) {
            printf("%s:%d ", host->h_name, port);
        }
        printf("\n");
    }

    return 0;
}