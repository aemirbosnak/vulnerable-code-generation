//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT_RANGE 1024

struct host_info {
    int port;
    char *ip;
};

void print_usage() {
    printf("Usage: %s <host> [<port>]\n", __func__);
}

int main(int argc, char *argv[]) {
    int sock = 0;
    struct host_info host;
    char buffer[BUFFER_SIZE];
    int port_range = PORT_RANGE;

    if (argc < 2) {
        print_usage();
        return 1;
    }

    // Parse command line arguments
    if (argv[1]) {
        host.ip = argv[1];
    } else {
        host.ip = "0.0.0.0";
    }

    if (argc > 2) {
        host.port = atoi(argv[2]);
    } else {
        host.port = 0;
    }

    // Initialize socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // Connect to the host
    if (connect(sock, (struct sockaddr *)&host, sizeof(host)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send a SYN packet to the host
    send(sock, "SYN", 3, 0);

    // Receive a SYN-ACK packet from the host
    recv(sock, buffer, BUFFER_SIZE, 0);

    // Extract the port number from the SYN-ACK packet
    struct sockaddr_in sin;
    memcpy(&sin, buffer, sizeof(sin));
    host.port = ntohs(sin.sin_port);

    // Print the port number
    printf("Port %d open on %s\n", host.port, host.ip);

    // Close the socket
    close(sock);

    return 0;
}