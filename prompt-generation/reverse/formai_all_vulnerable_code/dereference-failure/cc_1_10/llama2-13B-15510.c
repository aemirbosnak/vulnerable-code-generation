//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_HOSTNAME_LEN 255
#define MAX_PORTS 65535

// Structure to store host and port information
typedef struct {
    char hostname[MAX_HOSTNAME_LEN];
    unsigned short port;
} host_port_t;

// Function to parse command line arguments
void parse_args(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return;
    }

    // Store host and port in structure
    host_port_t host_port;
    strncpy(host_port.hostname, argv[1], MAX_HOSTNAME_LEN);
    host_port.port = atoi(argv[2]);
}

// Function to scan for open ports
int scan_ports(host_port_t *host_ports, int num_hosts) {
    int sock, i, j;
    struct sockaddr_in server_addr;
    socklen_t len = sizeof(server_addr);
    char buffer[256];

    // Initialize socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        return 0;
    }

    // Loop through hosts and scan for open ports
    for (i = 0; i < num_hosts; i++) {
        // Set server address
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(host_ports[i].port);
        inet_pton(AF_INET, host_ports[i].hostname, &server_addr.sin_addr);

        // Connect to server
        if (connect(sock, (struct sockaddr *)&server_addr, len) < 0) {
            perror("connect failed");
            continue;
        }

        // Send a packet and receive a response
        send(sock, "Hello, world!", 13, 0);
        recv(sock, buffer, 256, 0);

        // Check if response is "Hello, world!"
        if (strcmp(buffer, "Hello, world!") != 0) {
            printf("Port %d is open on %s\n", host_ports[i].port, host_ports[i].hostname);
        }

        // Close connection
        close(sock);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    // Parse command line arguments
    parse_args(argc, argv);

    // Create array of host_port structures
    host_port_t *host_ports = malloc(sizeof(host_port_t) * 10);
    int num_hosts = 0;

    // Loop through command line arguments and add to array
    for (int i = 2; i < argc; i++) {
        host_port_t host_port;
        parse_args(i, argv);
        host_ports[num_hosts] = host_port;
        num_hosts++;
    }

    // Scan for open ports
    scan_ports(host_ports, num_hosts);

    return 0;
}