//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

// Function to scan a single port
void scan_port(int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Error connecting to port %d: %s\n", port, strerror(errno));
        }
        close(sock);
        return;
    }

    printf("Port %d is open\n", port);
    close(sock);
}

// Function to scan a range of ports
void scan_range(int start_port, int end_port) {
    for (int i = start_port; i <= end_port; i++) {
        scan_port(i);
    }
}

// Main function to get user input and start scanning
int main() {
    char ip[16];
    printf("Enter IP address: ");
    scanf("%s", ip);

    int start_port, end_port;
    printf("Enter start port: ");
    scanf("%d", &start_port);
    printf("Enter end port: ");
    scanf("%d", &end_port);

    scan_range(start_port, end_port);

    return 0;
}