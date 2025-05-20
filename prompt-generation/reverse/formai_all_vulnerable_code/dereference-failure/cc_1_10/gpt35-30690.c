//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_HOSTS 1024

/* Structure to hold information about a host */
struct host {
    char *name;
    char *ip;
};

/* Function to print out usage instructions */
void usage(char *program_name) {
    printf("Usage: %s [-t timeout] [-p start_port-end_port] host\n", program_name);
}

/* Function to check if a string represents a valid port range */
int is_valid_port_range(char *port_range) {
    int i;
    for (i = 0; port_range[i] != '\0'; i++) {
        if (port_range[i] == '-') {
            return 1;
        }
    }
    return 0;
}

/* Function to parse command line arguments */
int parse_args(int argc, char **argv, char **hostname, int *port_range_start, int *port_range_end, int *timeout) {
    int i;
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-t") == 0 && i + 1 < argc) {
            *timeout = atoi(argv[i+1]);
            i++;
        } else if (strcmp(argv[i], "-p") == 0 && i + 1 < argc) {
            char *port_range = argv[i+1];
            if (!is_valid_port_range(port_range)) {
                return -1;
            }
            *port_range_start = atoi(strtok(port_range, "-"));
            *port_range_end = atoi(strtok(NULL, "-"));
            i++;
        } else {
            *hostname = argv[i];
        }
    }
    return 0;
}

/* Function to resolve a hostname to an IP address */
char *resolve_hostname(char *hostname) {
    struct hostent *he;
    if ((he = gethostbyname(hostname)) == NULL) {
        return NULL;
    }
    return inet_ntoa(*((struct in_addr*) he->h_addr));
}

/* Function to test if a port is open on a given host */
int test_port(char *ip, int port, int timeout) {
    struct sockaddr_in target_addr;
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        return -1;
    }
    setsockopt(sock_fd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &(target_addr.sin_addr));
    int connect_result = connect(sock_fd, (struct sockaddr*)&target_addr, sizeof(target_addr));
    close(sock_fd);
    if (connect_result < 0) {
        return 0;
    } else {
        return 1;
    }
}

/* Function to scan a host for open ports */
void scan_host(char *name, char *ip, int port_range_start, int port_range_end, int timeout) {
    struct host h = { name, ip };
    int open_ports[MAX_HOSTS];
    int num_open_ports = 0;
    int i;
    for (i = port_range_start; i <= port_range_end; i++) {
        if (test_port(ip, i, timeout) == 1) {
            open_ports[num_open_ports++] = i;
        }
    }
    if (num_open_ports > 0) {
        printf("%s (%s):\n", h.name, h.ip);
        for (i = 0; i < num_open_ports; i++) {
            printf("  %d open\n", open_ports[i]);
        }
    }
}

int main(int argc, char **argv) {
    /* Parse command line arguments */
    char *hostname = NULL;
    int port_range_start = 1;
    int port_range_end = 1024;
    int timeout = 1000;
    if (parse_args(argc, argv, &hostname, &port_range_start, &port_range_end, &timeout) < 0 || hostname == NULL) {
        usage(argv[0]);
        return -1;
    }
    /* Resolve hostname to IP address */
    char *ip = resolve_hostname(hostname);
    if (ip == NULL) {
        printf("Could not resolve hostname '%s'\n", hostname);
        return -1;
    }
    /* Scan host for open ports */
    scan_host(hostname, ip, port_range_start, port_range_end, timeout);
    return 0;
}