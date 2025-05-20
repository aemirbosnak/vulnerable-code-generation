//FormAI DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_START 1
#define PORT_END 65535

bool scan_port(const char* ip, int port);

int main(int argc, char* argv[]) {
    // Check if IP address and port range are provided
    if (argc != 3) {
        printf("Please provide IP address and port range to scan. Usage: %s <IP address> <port range>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    // Parse IP address
    struct in_addr ip_addr;
    if (inet_pton(AF_INET, argv[1], &ip_addr) <= 0) {
        printf("Invalid IP address: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    // Parse port range
    int start_port = atoi(strtok(argv[2], "-"));
    int end_port = atoi(strtok(NULL, "-"));
    
    // Check if port range is valid
    if (start_port < PORT_START || end_port > PORT_END || end_port < start_port) {
        printf("Invalid port range: %d-%d\n", start_port, end_port);
        exit(EXIT_FAILURE);
    }
    
    printf("Scanning ports %d-%d on IP address %s...\n", start_port, end_port, argv[1]);
    
    for (int port = start_port; port <= end_port; port++) {
        if (scan_port(argv[1], port)) {
            printf("Port %d is open!\n", port);
        }
    }
    
    printf("Scan finished!\n");
    
    return 0;
}

bool scan_port(const char* ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sock < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    
    struct sockaddr_in server;
    
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        close(sock);
        return false;
    }
    
    close(sock);
    return true;
}