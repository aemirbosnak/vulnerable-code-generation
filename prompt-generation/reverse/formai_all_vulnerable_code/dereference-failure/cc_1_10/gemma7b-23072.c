//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <openssl/ssl.h>

// Define a macro for easy socket creation
#define sock_create(port) sockfd = socket(AF_INET, SOCK_STREAM, htons(port))

// Define a structure for holding information about a scanned port
typedef struct PortInfo {
    int port_num;
    char status;
    struct PortInfo* next;
} PortInfo;

int main() {
    // Create a list of scanned ports
    PortInfo* head = NULL;

    // Define the port range to scan
    int start_port = 1024;
    int end_port = 65535;

    // Scan each port in the range
    for (int port = start_port; port <= end_port; port++) {
        // Create a socket
        int sockfd;
        sock_create(port);

        // Connect to the port
        int connect_result = connect(sockfd, (struct sockaddr*)NULL, 0);

        // Check if the port is open
        if (connect_result == 0) {
            // Add the port information to the list
            PortInfo* new_port_info = malloc(sizeof(PortInfo));
            new_port_info->port_num = port;
            new_port_info->status = 'O';
            new_port_info->next = head;
            head = new_port_info;
        } else {
            // Add the port information to the list
            PortInfo* new_port_info = malloc(sizeof(PortInfo));
            new_port_info->port_num = port;
            new_port_info->status = 'C';
            new_port_info->next = head;
            head = new_port_info;
        }

        // Close the socket
        close(sockfd);
    }

    // Print the scanned ports
    PortInfo* current_port = head;
    while (current_port) {
        printf("Port: %d, Status: %c\n", current_port->port_num, current_port->status);
        current_port = current_port->next;
    }

    return 0;
}