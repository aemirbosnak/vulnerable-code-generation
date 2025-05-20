//Falcon-180B DATASET v1.0 Category: Networking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

// Function to print error message and exit program
void error(char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

// Function to print usage instructions
void usage() {
    printf("Usage:./client <ip_address> <port_number>\n");
    printf("Example:./client 127.0.0.1 8080\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        usage();
        return 1;
    }

    // Convert string IP address to integer format
    struct in_addr server_addr;
    if (inet_pton(AF_INET, argv[1], &server_addr) <= 0) {
        error("Invalid IP address");
    }

    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        error("Socket creation failed");
    }

    // Set socket options
    int opt = 1;
    setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Connect to server
    struct sockaddr_in server_addr_in;
    memset(&server_addr_in, 0, sizeof(server_addr_in));
    server_addr_in.sin_family = AF_INET;
    server_addr_in.sin_port = htons(atoi(argv[2]));
    server_addr_in.sin_addr.s_addr = server_addr.s_addr;

    if (connect(socket_fd, (struct sockaddr *)&server_addr_in, sizeof(server_addr_in)) == -1) {
        error("Connection failed");
    }

    printf("Connected to server\n");

    // Send data to server
    char send_buffer[BUFFER_SIZE];
    sprintf(send_buffer, "Hello from client!");
    send(socket_fd, send_buffer, strlen(send_buffer), 0);

    // Receive data from server
    char recv_buffer[BUFFER_SIZE];
    int bytes_received = recv(socket_fd, recv_buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        error("Data reception failed");
    }

    printf("Received from server: %s\n", recv_buffer);

    // Close socket
    close(socket_fd);

    return 0;
}