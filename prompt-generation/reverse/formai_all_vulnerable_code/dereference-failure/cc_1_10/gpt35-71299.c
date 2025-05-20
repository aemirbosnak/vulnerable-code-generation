//FormAI DATASET v1.0 Category: Port Scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE_MIN 1
#define PORT_RANGE_MAX 65535

bool scan_port(const char* ip_addr, int port);

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <ip_addr>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char* ip_addr = argv[1];
    
    printf("Scanning ports on %s...\n", ip_addr);
    
    for (int port = PORT_RANGE_MIN; port <= PORT_RANGE_MAX; port++) {
        if (scan_port(ip_addr, port)) {
            printf("Port %d is open!\n", port);
        }
    }
    
    printf("Scan complete!\n");
    
    return EXIT_SUCCESS;
}

bool scan_port(const char* ip_addr, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return false;
    }
    
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_addr);
    addr.sin_port = htons(port);
    
    if (connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        // Port is closed
        close(sockfd);
        return false;
    } else {
        // Port is open
        close(sockfd);
        return true;
    }
}