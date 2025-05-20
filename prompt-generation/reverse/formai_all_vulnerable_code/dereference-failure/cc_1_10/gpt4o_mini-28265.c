//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>

// A beautiful serenade of bits and bytes, my love...
void reveal_ports(int start_port, int end_port, const char *ip_address) {
    struct sockaddr_in target;
    int sock, port;
    char response[3];

    // Prepare the target address
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip_address);

    printf("Oh, my dear, we shall discover the secrets of the ports...\n");
    printf("Scanning from port %d to port %d on %s...\n", start_port, end_port, ip_address);
    
    for (port = start_port; port <= end_port; port++) {
        // Create the socket
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("Could not create socket");
            continue;
        }

        // Set the socket to non-blocking
        struct timeval timeout;
        timeout.tv_sec = 1;  // set timeout to 1 second
        timeout.tv_usec = 0;
        setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));

        // Connect to the port
        target.sin_port = htons(port);
        int connection_status = connect(sock, (struct sockaddr*)&target, sizeof(target));

        // Delicately listen to the heartbeat of the connection
        if (connection_status != -1) {
            printf("Oh, sweet port %d is OPEN! ❤️\n", port);
        } else {
            printf("Port %d is closed... my heart aches. 💔\n", port);
        }
        
        // Close the socket gently
        close(sock);
        // Pause for a moment of contemplation...
        usleep(200000); // sleep for 200ms
    }
    
    printf("Our journey through the ports has come to an end, but love remains...\n");
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <IP> <start_port> <end_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Please use valid ports (1-65535).\n");
        return EXIT_FAILURE;
    }

    // The dance of the ports begins...
    reveal_ports(start_port, end_port, ip_address);

    return EXIT_SUCCESS; // Love conquers all!
}