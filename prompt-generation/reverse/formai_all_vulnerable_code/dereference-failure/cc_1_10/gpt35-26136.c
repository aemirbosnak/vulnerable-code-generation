//FormAI DATASET v1.0 Category: Port Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_PORTS 65535 // maximum number of ports to scan

// function to scan a single port
void scan_port(char *host, int port) {
    // create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return;
    }
    
    // resolve the hostname
    struct hostent *he;
    struct in_addr **addr_list;
    if ((he = gethostbyname(host)) == NULL) {
        herror("gethostbyname");
        return;
    }
    addr_list = (struct in_addr **) he->h_addr_list;
    
    // set up the address struct
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *addr_list[0];
    memset(&(addr.sin_zero), '\0', 8);
    
    // connect to the port
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        printf("Port %d is open on %s\n", port, host);
    }
    
    // close the socket
    close(sockfd);
}

// main function
int main(int argc, char *argv[]) {
    // check for valid arguments
    if (argc < 2) {
        printf("Usage: %s <host> [end-port]\n", argv[0]);
        return 0;
    }
    
    // get the host to scan
    char *host = argv[1];
    
    // get the end port (if provided)
    int end_port = MAX_PORTS;
    if (argc > 2) {
        end_port = atoi(argv[2]);
        if (end_port < 1 || end_port > MAX_PORTS) {
            printf("Invalid end port: %s\n", argv[2]);
            return 1;
        }
    }
    
    // scan the ports
    printf("Scanning ports 1-%d on %s...\n", end_port, host);
    for (int port = 1; port <= end_port; port++) {
        scan_port(host, port);
    }
    printf("Done.\n");
    
    return 0;
}