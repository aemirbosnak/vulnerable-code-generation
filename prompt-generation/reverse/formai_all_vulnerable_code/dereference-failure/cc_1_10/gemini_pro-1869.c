//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEFAULT_TARGET_IP "127.0.0.1"
#define DEFAULT_PORT_START 1
#define DEFAULT_PORT_END 65535
#define DEFAULT_TIMEOUT_MS 1000

// Function to print usage information and exit the program
void print_usage(char *program_name) {
    printf("Usage: %s [target_ip] [port_start] [port_end] [timeout_ms]\n", program_name);
    printf("  target_ip: The IP address of the target host (default: %s)\n", DEFAULT_TARGET_IP);
    printf("  port_start: The starting port to scan (default: %d)\n", DEFAULT_PORT_START);
    printf("  port_end: The ending port to scan (default: %d)\n", DEFAULT_PORT_END);
    printf("  timeout_ms: The timeout in milliseconds for each port scan attempt (default: %d)\n", DEFAULT_TIMEOUT_MS);
    exit(EXIT_FAILURE);
}

// Function to create a socket and connect to the target host on the specified port
int create_socket_and_connect(char *target_ip, int port, int timeout_ms) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the timeout for the socket
    struct timeval tv;
    tv.tv_sec = timeout_ms / 1000;
    tv.tv_usec = (timeout_ms % 1000) * 1000;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, target_ip, &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        return -1;
    }

    return sockfd;
}

// Function to scan the specified port on the target host and return the result
int scan_port(char *target_ip, int port, int timeout_ms) {
    int sockfd = create_socket_and_connect(target_ip, port, timeout_ms);
    if (sockfd == -1) {
        return -1;
    }

    // Send a message to the server
    char *message = "Hello, world!";
    if (send(sockfd, message, strlen(message), 0) == -1) {
        perror("send");
        close(sockfd);
        return -1;
    }

    // Receive a response from the server
    char buffer[1024];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
        perror("recv");
        close(sockfd);
        return -1;
    }

    // Close the socket
    close(sockfd);

    // Return the result of the scan
    return bytes_received > 0;
}

// Function to scan the specified range of ports on the target host and print the results
void scan_ports(char *target_ip, int port_start, int port_end, int timeout_ms) {
    for (int port = port_start; port <= port_end; port++) {
        int result = scan_port(target_ip, port, timeout_ms);
        if (result == -1) {
            printf("Error scanning port %d: %s\n", port, strerror(errno));
        } else if (result > 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
    }
}

// Main function
int main(int argc, char **argv) {
    // Parse the command-line arguments
    char *target_ip = DEFAULT_TARGET_IP;
    int port_start = DEFAULT_PORT_START;
    int port_end = DEFAULT_PORT_END;
    int timeout_ms = DEFAULT_TIMEOUT_MS;
    if (argc > 1) {
        target_ip = argv[1];
    }
    if (argc > 2) {
        port_start = atoi(argv[2]);
    }
    if (argc > 3) {
        port_end = atoi(argv[3]);
    }
    if (argc > 4) {
        timeout_ms = atoi(argv[4]);
    }

    // Check if the port range is valid
    if (port_start < 1 || port_start > 65535 || port_end < 1 || port_end > 65535 || port_start > port_end) {
        print_usage(argv[0]);
    }

    // Scan the specified ports
    scan_ports(target_ip, port_start, port_end, timeout_ms);

    return EXIT_SUCCESS;
}