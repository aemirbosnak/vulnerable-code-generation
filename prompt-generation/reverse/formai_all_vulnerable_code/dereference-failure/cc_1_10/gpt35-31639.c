//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <net/if.h>
#include <sys/ioctl.h>

#define MAX_IPADDR_LEN 16  // Maximum IPv4 address length
#define IF_NAME "wlan0"    // Name of interface to scan on
#define TIMEOUT 1          // Timeout value for socket operations

// Print usage instructions if command-line args not provided correctly
void usage(const char *progname) {
    printf("Usage: %s [start_ip] [end_ip]\n", progname);
    printf("    start_ip: the first IP address to scan (default is 192.168.0.1)\n");
    printf("    end_ip: the last IP address to scan (default is 192.168.0.255)\n");
}

// Get the IP address of the current device
void get_ip_address(char *ipaddr) {
    int sock_fd;
    struct ifreq ifr;

    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    strncpy(ifr.ifr_name, IF_NAME, IFNAMSIZ - 1);
    ifr.ifr_name[IFNAMSIZ - 1] = '\0';

    if (ioctl(sock_fd, SIOCGIFADDR, &ifr) < 0) {
        perror("Error getting IP address");
        exit(EXIT_FAILURE);
    }

    close(sock_fd);

    inet_ntop(AF_INET, &(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr), ipaddr, INET_ADDRSTRLEN);
}

// Check if an IP address is valid
bool is_valid_ip(const char *ipaddr) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ipaddr, &(sa.sin_addr));
    return (result == 1);
}

// Scan a range of IP addresses for open ports
void scan_network(const char *start_ip, const char *end_ip) {
    printf("Scanning network from %s to %s...\n", start_ip, end_ip);

    // Convert start and end IP addresses to integers
    struct in_addr start_addr, end_addr;
    if (inet_pton(AF_INET, start_ip, &start_addr) != 1) {
        perror("Error parsing start IP address");
        exit(EXIT_FAILURE);
    }

    if (inet_pton(AF_INET, end_ip, &end_addr) != 1) {
        perror("Error parsing end IP address");
        exit(EXIT_FAILURE);
    }

    // Loop through IP addresses in range and try to connect to port 80
    struct in_addr curr_addr;
    for (uint32_t i = ntohl(start_addr.s_addr); i <= ntohl(end_addr.s_addr); i++) {
        curr_addr.s_addr = htonl(i);

        char curr_ip[MAX_IPADDR_LEN];
        if (inet_ntop(AF_INET, &curr_addr, curr_ip, INET_ADDRSTRLEN) == NULL) {
            perror("Error converting IP address to string");
            continue;
        }

        printf("Testing IP address: %s\n", curr_ip);

        int sock_fd;
        struct sockaddr_in addr;

        sock_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (sock_fd < 0) {
            perror("Error creating socket");
            exit(EXIT_FAILURE);
        }

        memset(&addr, 0, sizeof(addr));

        addr.sin_family = AF_INET;
        addr.sin_port = htons(80);  // HTTP port
        addr.sin_addr.s_addr = curr_addr.s_addr;

        if (connect(sock_fd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            printf("    --> %s is online!\n", curr_ip);
        }

        close(sock_fd);
    }

    printf("Done scanning network.\n");
}

int main(int argc, char **argv) {
    char start_ip[MAX_IPADDR_LEN] = "192.168.0.1";  // Default start IP address
    char end_ip[MAX_IPADDR_LEN] = "192.168.0.255";  // Default end IP address

    if (argc > 1) {
        strncpy(start_ip, argv[1], MAX_IPADDR_LEN - 1);
        start_ip[MAX_IPADDR_LEN - 1] = '\0';
    }

    if (argc > 2) {
        strncpy(end_ip, argv[2], MAX_IPADDR_LEN - 1);
        end_ip[MAX_IPADDR_LEN - 1] = '\0';
    }

    if (!is_valid_ip(start_ip) || !is_valid_ip(end_ip)) {
        printf("Error: Invalid IP address\n");
        usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    char my_ip[MAX_IPADDR_LEN];
    get_ip_address(my_ip);
    printf("My IP address: %s\n", my_ip);

    if (strcmp(start_ip, my_ip) == 0) {
        printf("Error: Cannot scan own IP address\n");
        usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    scan_network(start_ip, end_ip);

    return 0;
}