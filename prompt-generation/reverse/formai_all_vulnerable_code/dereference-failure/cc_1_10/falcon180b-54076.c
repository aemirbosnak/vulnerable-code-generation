//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

// Function to print usage instructions
void print_usage() {
    printf("Usage:./port_scanner <IP Address> <Start Port> <End Port>\n");
    exit(1);
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        print_usage();
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Create a socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, ip_address);

    for (int i = start_port; i <= end_port; i++) {
        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(i);
        inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

        int connect_result = connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (connect_result == -1) {
            // Port is closed
            printf("%d - Closed\n", i);
        } else {
            // Port is open
            close(socket_fd);
            printf("%d - Open\n", i);
        }
    }

    close(socket_fd);
    return 0;
}