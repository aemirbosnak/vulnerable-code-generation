//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

void display_greeting() {
    printf("====================================\n");
    printf("   Welcome to the Grateful Port    \n");
    printf("             Scanner!               \n");
    printf("====================================\n");
    printf("We appreciate your curiosity and willingness to explore.\n");
    printf("Thank you for using this port scanner!\n");
    printf("====================================\n");
}

int scan_port(const char* ip_address, int port) {
    int sock_fd;
    struct sockaddr_in target;

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        fprintf(stderr, "Could not create socket! Thank you for your understanding.\n");
        exit(EXIT_FAILURE);
    }

    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    target.sin_addr.s_addr = inet_addr(ip_address);

    // Set socket timeout
    struct timeval timeout;
    timeout.tv_sec = 1; // Timeout after 1 second
    timeout.tv_usec = 0;
    
    setsockopt(sock_fd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));

    int connection_status = connect(sock_fd, (struct sockaddr*)&target, sizeof(target));
    close(sock_fd);

    // Here is our heartfelt message for the open port
    if (connection_status == 0) {
        printf("Port %d on %s is open! Thank you for letting us discover this together!\n", port, ip_address);
    } else {
        printf("Port %d on %s is closed. No worries, there are plenty of other ports to explore!\n", port, ip_address);
    }

    return connection_status;
}

void scan_ports(const char* ip_address, int start_port, int end_port) {
    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip_address, port);
        // To be kind to the network and systems, we will wait a bit between scans
        usleep(50000); // 50 milliseconds
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP address> <start port> <end port>\n", argv[0]);
        fprintf(stderr, "Thank you for your attention to details in using this program!\n");
        exit(EXIT_FAILURE);
    }

    const char* ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    display_greeting();

    // Providing some useful information on the scanning process
    printf("Starting scan on %s from port %d to %d.\n", ip_address, start_port, end_port);
    scan_ports(ip_address, start_port, end_port);

    printf("====================================\n");
    printf("Thank you for using our Grateful Port Scanner!\n");
    printf("Feel free to explore even more in the future!\n");
    printf("====================================\n");
    
    return 0;
}