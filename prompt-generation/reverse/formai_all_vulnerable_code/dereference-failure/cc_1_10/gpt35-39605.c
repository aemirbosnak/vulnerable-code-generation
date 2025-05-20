//FormAI DATASET v1.0 Category: Port Scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

// function to scan for open ports
void scan_port(char *ip_address, int start_port, int end_port) {
    int client_socket, port;
    struct sockaddr_in address;

    // loop through all ports in range
    for (port = start_port; port <= end_port; port++) {
        // create socket
        client_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (client_socket < 0) {
            perror("socket() error");
            exit(1);
        }

        // set up address struct
        memset(&address, 0, sizeof(address));
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = inet_addr(ip_address);
        address.sin_port = htons(port);

        // attempt to connect to port
        if (connect(client_socket, (struct sockaddr *)&address, sizeof(address)) == 0) {
            printf("Port %d is open\n", port);
        }

        // close socket
        close(client_socket);
    }
}

int main(int argc, char *argv[]) {
    // check for correct number of arguments
    if (argc < 4) {
        printf("Usage: %s <IP address> <starting port> <ending port>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    printf("Scanning ports %d to %d on %s\n", start_port, end_port, ip_address);

    // call scan_port function to search for open ports
    scan_port(ip_address, start_port, end_port);

    return 0;
}