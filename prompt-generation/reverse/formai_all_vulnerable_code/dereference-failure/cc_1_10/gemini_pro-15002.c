//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535
#define MAX_HOSTNAME_LENGTH 256

// Function to scan a single port
int scan_port(char *hostname, int port) {
    int sockfd;
    struct sockaddr_in addr;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(hostname);
    
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        printf("Port %d is open on host %s\n", port, hostname);
        close(sockfd);
        return 0;
    } else {
        close(sockfd);
        return -1;
    }
}

// Function to scan a range of ports
int scan_ports(char *hostname, int start_port, int end_port) {
    int i;
    
    for (i = start_port; i <= end_port; i++) {
        if (scan_port(hostname, i) == 0) {
            return 0;
        }
    }
    
    return -1;
}

// Function to get the hostname from the command line arguments
char *get_hostname(int argc, char *argv[]) {
    char *hostname;
    
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }
    
    hostname = argv[1];
    
    return hostname;
}

// Function to get the port range from the command line arguments
int *get_port_range(int argc, char *argv[]) {
    int *port_range;
    int start_port;
    int end_port;
    
    if (argc < 3) {
        printf("Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        exit(1);
    }
    
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);
    
    port_range = malloc(2 * sizeof(int));
    port_range[0] = start_port;
    port_range[1] = end_port;
    
    return port_range;
}

// Main function
int main(int argc, char *argv[]) {
    char *hostname;
    int *port_range;
    
    hostname = get_hostname(argc, argv);
    port_range = get_port_range(argc, argv);
    
    if (scan_ports(hostname, port_range[0], port_range[1]) == 0) {
        printf("At least one port is open on host %s\n", hostname);
    } else {
        printf("No ports are open on host %s\n", hostname);
    }
    
    free(port_range);
    
    return 0;
}