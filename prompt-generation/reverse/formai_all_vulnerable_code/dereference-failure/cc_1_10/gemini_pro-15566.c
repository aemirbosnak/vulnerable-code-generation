//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Custom data structures

typedef struct _port_scanner {
    int fd;                 // Socket descriptor
    int port;               // Port number
    char *host;             // Hostname or IP address
} port_scanner;

// Function declarations

int create_socket(port_scanner *scanner);
int connect_to_port(port_scanner *scanner);
void print_port_status(port_scanner *scanner);

// Main function

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    port_scanner scanner;

    // Create a socket
    if (create_socket(&scanner) < 0) {
        perror("create_socket");
        return EXIT_FAILURE;
    }

    // Set the port number
    scanner.port = atoi(argv[2]);

    // Set the hostname or IP address
    scanner.host = strdup(argv[1]);

    // Connect to the port
    if (connect_to_port(&scanner) < 0) {
        perror("connect_to_port");
        return EXIT_FAILURE;
    }

    // Print the port status
    print_port_status(&scanner);

    // Cleanup
    close(scanner.fd);
    free(scanner.host);

    return EXIT_SUCCESS;
}

// Function definitions

int create_socket(port_scanner *scanner) {
    // Create a socket
    scanner->fd = socket(AF_INET, SOCK_STREAM, 0);
    if (scanner->fd < 0) {
        return -1;
    }

    // Set the socket options
    int optval = 1;
    if (setsockopt(scanner->fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        return -1;
    }

    return 0;
}

int connect_to_port(port_scanner *scanner) {
    // Set the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(scanner->port);
    if (inet_pton(AF_INET, scanner->host, &server_addr.sin_addr) <= 0) {
        return -1;
    }

    // Connect to the server
    if (connect(scanner->fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        return -1;
    }

    return 0;
}

void print_port_status(port_scanner *scanner) {
    // Get the port status
    int error_code;
    socklen_t error_code_len = sizeof(error_code);
    if (getsockopt(scanner->fd, SOL_SOCKET, SO_ERROR, &error_code, &error_code_len) < 0) {
        perror("getsockopt");
        return;
    }

    // Print the port status
    if (error_code == 0) {
        printf("Port %d is open.\n", scanner->port);
    } else {
        printf("Port %d is closed or filtered.\n", scanner->port);
    }
}