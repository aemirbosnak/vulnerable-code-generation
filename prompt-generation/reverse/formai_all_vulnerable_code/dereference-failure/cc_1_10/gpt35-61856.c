//FormAI DATASET v1.0 Category: Port Scanner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define NUM_PORTS 1000 // number of ports to scan
#define TIMEOUT 1 // number of seconds to wait for response
#define MAX_IP_SIZE 16 // maximum size of an IP address string
#define MAX_PORT_SIZE 6 // maximum size of a port number string

void scan_ports(char* ip_address);

int main(int argc, char *argv[]) {

    char *ip_address;

    if(argc == 1) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 0;
    }

    ip_address = argv[1];

    scan_ports(ip_address);

    return 0;
}

void scan_ports(char* ip_address) {

    int sockfd, port, result;
    struct hostent *host;
    struct sockaddr_in server_address;
    char port_str[MAX_PORT_SIZE];

    printf("Scanning ports on %s...\n", ip_address);

    // resolve hostname
    host = gethostbyname(ip_address);
    if(host == NULL) {
        printf("Could not resolve hostname.\n");
        return;
    }

    // set server address structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = *((unsigned long *) host->h_addr);

    // scan ports
    for(port = 1; port <= NUM_PORTS; port++) {
        sprintf(port_str, "%d", port);
        server_address.sin_port = htons(port);

        // create socket file descriptor
        if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("socket() error");
            exit(-1);
        }

        // set socket timeout
        struct timeval timeout;      
        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;

        if(setsockopt (sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
            perror("setsockopt() error");
            exit(-1);
        }

        // connect to port
        result = connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address));
        if(result == 0) {
            printf("Port %d open.\n", port);
        }

        close(sockfd);
    }

    printf("Done.\n");

    return;
}