//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

// Define constants
#define SLEEP_TIME 5
#define MAX_ATTEMPTS 3
#define SCAN_PORT 80
#define SCAN_TIMEOUT 2

// Define function to perform a scan on a specific IP address and port
int scan_ip(const char *ip_address, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip_address);
    server.sin_port = htons(port);

    // Set the timeout for the socket
    struct timeval tv;
    tv.tv_sec = SCAN_TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

    int res = connect(sock, (struct sockaddr*)&server, sizeof(server));
    if(res == 0) {
        printf("Open: %s:%d\n", ip_address, port);
        close(sock);
        return 1;
    } else {
        close(sock);
        return 0;
    }
}

// Define function to scan a range of IP addresses on a given port
void scan_range(char *ip_range, int port) {
    int num_attempts = 0;
    char command[100];
    sprintf(command, "ping -c 1 %s > /dev/null 2>&1", ip_range);
    while(num_attempts < MAX_ATTEMPTS) {
        int result = system(command);
        if(result == 0) {
            if(scan_ip(ip_range, port)) {
                break;
            }
        }
        num_attempts++;
        sleep(SLEEP_TIME);
    }
}

// Define program entry point
int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: %s [IP RANGE]\n", argv[0]);
        exit(1);
    }

    // Obtain the IP range to scan
    char *ip_range = argv[1];

    // Get the first three parts of the IP address
    char *ip_first_three = strtok(ip_range, ".");

    // Loop through all possible IP addresses in the range
    for(int i=0;i<=255;i++) {
        for(int j=1;j<=255;j++) {
            for(int k=1;k<=255;k++) {
                char ip_addr[16];
                sprintf(ip_addr, "%s.%d.%d.%d", ip_first_three, i, j, k);
                scan_range(ip_addr, SCAN_PORT);
            }
        }
    }

    return 0;
}