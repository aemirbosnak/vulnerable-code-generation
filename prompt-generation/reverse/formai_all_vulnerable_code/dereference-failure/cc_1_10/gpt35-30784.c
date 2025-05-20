//FormAI DATASET v1.0 Category: Port Scanner ; Style: shape shifting
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define MAXPORTS 100

// Shape-shifting function to scan for open ports on a given host
int port_scanner(char* hostname, int start_port, int end_port) {

    // Create a socket for the scanner
    int scanner_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Check if scanner socket was created successfully
    if (scanner_socket == -1) {
        printf("Socket could not be created: %d\n", errno);
        return 1;
    }

    // Struct to hold IP address
    struct sockaddr_in target_server;

    // Fill the struct with the target server IP address
    target_server.sin_addr.s_addr = inet_addr(hostname);

    // Set the family, port, and other properties of the target_server struct
    target_server.sin_family = AF_INET;

    // Initialize empty array for storing open ports discovered by scanner
    int open_ports[MAXPORTS];
    int num_ports = 0;

    // Loop through all possible ports in range and connect to each one
    for (int port = start_port; port <= end_port; port++) {

        // Set the port for the target server
        target_server.sin_port = htons(port);

        // Connect to the target server on the initialized port
        int status = connect(scanner_socket, (struct sockaddr *) &target_server, sizeof(target_server));

        // If connect() returns 0, then port is open
        if (status == 0) {
            printf("Port %d is open\n", port);

            // Add open port to array of open ports
            open_ports[num_ports] = port;
            num_ports++;
        }
    }
    // If no open ports were found, print appropriate message
    if (num_ports == 0) {
        printf("No open ports found\n");
    }
    // Otherwise, print all discovered open ports
    else {
        printf("Open ports:\n");
        for (int i = 0; i < num_ports; i++) {
            printf("\t%d\n", open_ports[i]);
        }
    }

    // Close scanner socket
    close(scanner_socket);

    // Successful execution
    return 0;
}

int main(int argc, char* argv[]) {

    // Parse command-line arguments
    if (argc < 3 || argc > 4) {
        printf("Usage: %s hostname start_port [end_port]\n", argv[0]);
        return 1;
    }

    char* hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = (argc == 4) ? atoi(argv[3]) : start_port;

    // Run the port scanner
    return port_scanner(hostname, start_port, end_port);
}