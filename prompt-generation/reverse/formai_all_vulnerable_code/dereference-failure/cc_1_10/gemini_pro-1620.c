//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_PORTS 1024

// Structure to store host information
typedef struct host_info {
    char hostname[MAX_HOSTNAME_LEN];
    uint16_t ports[MAX_PORTS];
    int num_ports;
} host_info;

// Function to get the hostname from an IP address
char *get_hostname(char *ip_addr) {
    struct hostent *host_entry;
    host_entry = gethostbyaddr(ip_addr, strlen(ip_addr), AF_INET);
    if (host_entry == NULL) {
        return NULL;
    }
    return host_entry->h_name;
}

// Function to scan a host for open ports
int scan_host(char *hostname, host_info *host) {
    int sockfd;
    struct sockaddr_in addr;
    int port;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(hostname);
    addr.sin_port = 0;

    for (port = 0; port < MAX_PORTS; port++) {
        addr.sin_port = htons(port);
        if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            host->ports[host->num_ports] = port;
            host->num_ports++;
        }
    }

    close(sockfd);
    return 0;
}

// Function to print the host information
void print_host_info(host_info *host) {
    int i;

    printf("Hostname: %s\n", host->hostname);
    printf("Open ports:\n");
    for (i = 0; i < host->num_ports; i++) {
        printf("%d ", host->ports[i]);
    }
    printf("\n\n");
}

int main(int argc, char **argv) {
    char *ip_addr;
    char hostname[MAX_HOSTNAME_LEN];
    host_info host;

    if (argc < 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    ip_addr = argv[1];

    // Get the hostname from the IP address
    if (get_hostname(ip_addr) == NULL) {
        printf("Invalid IP address: %s\n", ip_addr);
        return 1;
    }

    // Scan the host for open ports
    strcpy(host.hostname, get_hostname(ip_addr));
    host.num_ports = 0;
    if (scan_host(host.hostname, &host) < 0) {
        printf("Error scanning host: %s\n", host.hostname);
        return 1;
    }

    // Print the host information
    print_host_info(&host);

    return 0;
}