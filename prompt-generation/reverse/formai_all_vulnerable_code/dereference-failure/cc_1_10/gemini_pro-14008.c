//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the port scanner function
int port_scanner(char *target_ip, int start_port, int end_port) {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return -1;
    }

    // Set the target IP and port
    struct sockaddr_in target;
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(target_ip);

    // Scan the ports
    for (int port = start_port; port <= end_port; port++) {
        target.sin_port = htons(port);

        // Connect to the port
        int ret = connect(sock, (struct sockaddr *) &target, sizeof(target));
        if (ret == 0) {
            printf("Port %d is open\n", port);
        }
    }

    // Close the socket
    close(sock);

    return 0;
}

// Define the main function
int main(int argc, char *argv[]) {
    // Check the arguments
    if (argc != 4) {
        printf("Usage: %s <target_ip> <start_port> <end_port>\n", argv[0]);
        return -1;
    }

    // Get the target IP, start port, and end port
    char *target_ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Scan the ports
    port_scanner(target_ip, start_port, end_port);

    return 0;
}