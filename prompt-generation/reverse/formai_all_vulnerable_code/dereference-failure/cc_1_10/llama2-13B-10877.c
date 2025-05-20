//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024  // range of ports to scan, start from 1024
#define IP_ADDRESS "192.168.1.100" // IP address to scan

void print_usage() {
    printf("Usage: %s <IP_ADDRESS> <PORT_RANGE>\n", __func__);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        print_usage();
        return 1;
    }

    char *ip_address = argv[1];
    int port_range = atoi(argv[2]);

    struct sockaddr_in server_addr;
    socklen_t address_len = sizeof(server_addr);
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    // Set IP address and port range
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_range);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    // Connect to the IP address and port range
    if (connect(sock, (struct sockaddr *)&server_addr, address_len) < 0) {
        perror("connect failed");
        exit(1);
    }

    // Send a SYN packet to open a connection
    char packet[1024];
    memset(packet, 0, 1024);
    packet[1024 - 1] = 1; // set the SYN bit
    send(sock, packet, 1024, 0);

    // Receive a response packet
    char *response = malloc(1024);
    recv(sock, response, 1024, 0);

    // Print the open ports
    int port = ntohs(server_addr.sin_port);
    printf("Port %d is open on %s\n", port, ip_address);

    // Close the connection
    close(sock);

    return 0;
}