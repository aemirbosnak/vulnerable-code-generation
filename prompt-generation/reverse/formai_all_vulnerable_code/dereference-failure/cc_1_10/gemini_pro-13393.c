//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Retro-styled ASCII art banner
void banner() {
    printf(" _  _      _       __   _______  _  _   _       _            __  __        \n");
    printf("| || |    | |     / /  |__   __|| || | | |     | |          |  \/  |       \n");
    printf("| || |    | |    / /       | |   | || |_| |     | |          | |\/| |       \n");
    printf("|__   __ | |   / /        | |   |__   __  |     | |  ______  | |  | |       \n");
    printf("   | |  || |  / /         | |      | |  | |     | | |______| | |  | |       \n");
    printf("   |_|  ||_| /_/          |_|      |_|  |_|_____|_|__________|_|  |_|       \n\n");
}

// Function to scan a single port
int scan_port(char *ip, int port) {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        return -1;
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &servaddr.sin_addr) <= 0) {
        perror("Error converting IP address");
        return -1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        return 0;  // Port is closed
    }

    // Port is open
    close(sockfd);
    return 1;
}

int main(int argc, char **argv) {
    char *ip;
    int port;
    int start_port, end_port;
    int open_ports = 0;

    // Display the banner
    banner();

    // Get the command-line arguments
    if (argc < 4) {
        printf("Usage: %s <ip> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    ip = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    // Scan the ports
    for (port = start_port; port <= end_port; port++) {
        if (scan_port(ip, port)) {
            printf("Port %d is open\n", port);
            open_ports++;
        }
    }

    // Print the summary
    printf("\nTotal open ports: %d\n", open_ports);

    return 0;
}