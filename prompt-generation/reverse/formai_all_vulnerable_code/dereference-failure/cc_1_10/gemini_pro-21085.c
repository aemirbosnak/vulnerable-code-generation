//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_MIN 1
#define PORT_MAX 65535

// Prints the usage of the program.
void usage(char *program_name) {
    printf("Usage: %s <ip_address> <port_range>\n", program_name);
    printf("Example: %s 127.0.0.1 1-100\n", program_name);
    exit(1);
}

// Parses the port range from the given string.
void parse_port_range(char *port_range, int *port_min, int *port_max) {
    char *dash = strchr(port_range, '-');
    if (dash == NULL) {
        *port_min = atoi(port_range);
        *port_max = atoi(port_range);
    } else {
        *port_min = atoi(port_range);
        *port_max = atoi(dash + 1);
    }

    if (*port_min < PORT_MIN || *port_min > PORT_MAX || *port_max < PORT_MIN || *port_max > PORT_MAX) {
        usage("Invalid port range");
    }
}

// Scans the given IP address for open ports in the given port range.
void scan_ports(char *ip_address, int port_min, int port_max) {
    int sockfd;
    struct sockaddr_in serv_addr;

    // Create a socket.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set the server address.
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip_address);

    // Scan the ports.
    for (int port = port_min; port <= port_max; port++) {
        serv_addr.sin_port = htons(port);

        // Connect to the server.
        if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == 0) {
            printf("Port %d: open\n", port);
        }
    }

    // Close the socket.
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage(argv[0]);
    }

    int port_min, port_max;
    parse_port_range(argv[2], &port_min, &port_max);

    scan_ports(argv[1], port_min, port_max);

    return 0;
}