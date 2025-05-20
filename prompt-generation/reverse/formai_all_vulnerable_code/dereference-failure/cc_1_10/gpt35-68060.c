//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<errno.h>

#define MAX_PORTS 10

void scan_ports(char* ip_address) {
    struct sockaddr_in remote_server;
    int port_number, socket_fd, connection_status;
    char *message = "Hello from client";

    // Scan for open ports from 1 to MAX_PORTS
    for (port_number = 1; port_number <= MAX_PORTS; port_number++) {
        remote_server.sin_family = AF_INET;
        remote_server.sin_addr.s_addr = inet_addr(ip_address);
        remote_server.sin_port = htons(port_number);

        socket_fd = socket(AF_INET, SOCK_STREAM, 0);

        // Check if socket creation was successful
        if (socket_fd == -1) {
            printf("Could not create socket: %s\n", strerror(errno));
            continue;
        }

        // Attempt connection to remote server
        connection_status = connect(socket_fd, (struct sockaddr*)&remote_server, sizeof(remote_server));

        // Check if connection was successful
        if (connection_status == -1) {
            // Port is not open
            printf("Port %d is closed.\n", port_number);
            close(socket_fd);
            continue;
        }

        // Connection successful, send message to server
        printf("Port %d is open.\n", port_number);
        send(socket_fd, message, strlen(message), 0);
        close(socket_fd);
    }
}

int main(int argc, char *argv[]) {
    char *ip_address;

    if (argc != 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }

    ip_address = argv[1];

    printf("Scanning ports for IP Address: %s\n", ip_address);
    scan_ports(ip_address);

    return 0;
}