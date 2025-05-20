//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>

#define PORT 80     // Port to connect to
#define MAX 1000    // Maximum size of data to receive

int main(int argc, char *argv[]) {
    int sock, scan;
    struct sockaddr_in server;
    struct hostent *host;
    char ip[16];
    char hostname[MAX];

    // Get hostname to scan
    printf("Enter hostname to scan: ");
    scanf("%s", hostname);

    // Get IP address of hostname
    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Unable to resolve hostname.\n");
        return 1;
    }
    strcpy(ip, inet_ntoa(*(struct in_addr *)host->h_addr_list[0]));

    // Create socket for TCP connection
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Failed to create socket.\n");
        return 1;
    }

    // Setup socket address structure
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection error.\n");
        return 1;
    }

    // Scan port
    printf("Scanning %s on port %d...\n", hostname, PORT);
    for (scan = 1; scan <= 100; scan++) {
        struct sockaddr_in sa;
        socklen_t len = sizeof(sa);
        sa.sin_family = AF_INET;
        sa.sin_addr.s_addr = inet_addr(ip);
        sa.sin_port = htons(scan);

        // Create socket for UDP connection
        int udp_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if (udp_sock == -1) {
            printf("Failed to create UDP socket.\n");
            return 1;
        }

        // Set socket timeout
        struct timeval tv;
        tv.tv_sec = 1;
        tv.tv_usec = 0;

        if (setsockopt(udp_sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
            printf("setsockopt failed.\n");
            return 1;
        }

        // Send UDP packet to port
        if (sendto(udp_sock, NULL, 0, 0, (struct sockaddr *)&sa, len) < 0) {
            printf("Port %d closed.\n", scan);
        } else {
            printf("Port %d open.\n", scan);
        }

        close(udp_sock);
    }

    printf("Scan complete.\n");
    close(sock);
    return 0;
}