//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024
#define MIN_ARGUMENTS 2
#define DEFAULT_PROXY_PORT 8080
#define VALID_PROXY_PORT(port) ((port) > 0 && (port) <= 65535)

// Function prototypes
int parse_arguments(int argc, char *argv[], char **proxy_address, int *proxy_port);
void print_usage(char *program_name);
bool is_valid_ip(char *ip_address);
int start_proxy(char *proxy_address, int proxy_port);

int main(int argc, char *argv[]) {
    char *proxy_address;
    int proxy_port;

    if (parse_arguments(argc, argv, &proxy_address, &proxy_port) != 0) {
        print_usage(argv[0]);
        return -1;
    }

    if (start_proxy(proxy_address, proxy_port) != 0) {
        fprintf(stderr, "Failed to start the proxy\n");
        return -1;
    }

    return 0;
}

/**
 * Parses the command line arguments and validates them.
 * @param argc The number of arguments.
 * @param argv The array of argument strings.
 * @param proxy_address A pointer to the variable that will hold the proxy address entered by the user.
 * @param proxy_port A pointer to the variable that will hold the proxy port entered by the user.
 * @return 0 on success, -1 on failure.
 */
int parse_arguments(int argc, char *argv[], char **proxy_address, int *proxy_port) {
    // Check if the minimum number of arguments have been provided.
    if (argc < MIN_ARGUMENTS) {
        return -1;
    }

    // The proxy address is the first argument.
    *proxy_address = argv[1];

    // The proxy port is the second argument (if provided).
    if (argc > MIN_ARGUMENTS) {
        int port = atoi(argv[2]);

        // Make sure the port is valid.
        if (!VALID_PROXY_PORT(port)) {
            return -1;
        } else {
            *proxy_port = port;
        }
    } else {
        *proxy_port = DEFAULT_PROXY_PORT;
    }

    return 0;
}

/**
 * Prints the usage information for this program.
 * @param program_name The name of the program as entered on the command line.
 */
void print_usage(char *program_name) {
    printf("Usage: %s <proxy-ip> [proxy-port]\n", program_name);
    printf("Proxy IP must be a valid IPv4 address.\n");
    printf("Proxy port must be between 1 and 65535 (inclusive).\n");
}

/**
 * Checks if the given string is a valid IP address (IPv4).
 * @param ip_address The IP address string to check.
 * @return true if the string is a valid IP address, false otherwise.
 */
bool is_valid_ip(char *ip_address) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip_address, &(sa.sin_addr)) != 0;
}

/**
 * Starts the HTTP proxy on the given address and port.
 * @param proxy_address The IP address of the proxy.
 * @param proxy_port The port number of the proxy.
 * @return 0 on success, -1 on failure.
 */
int start_proxy(char *proxy_address, int proxy_port) {
    int socket_fd, client_fd;
    struct sockaddr_in proxy_address_in, client_address_in;
    char client_buffer[MAX_BUFFER_SIZE];
    ssize_t read_count;

    // Create a TCP socket.
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd < 0) {
        fprintf(stderr, "Failed to create socket: %s\n", strerror(errno));
        return -1;
    }

    // Set up the proxy address structure.
    memset(&proxy_address_in, 0, sizeof(proxy_address_in));
    proxy_address_in.sin_family = AF_INET;
    proxy_address_in.sin_addr.s_addr = INADDR_ANY;
    proxy_address_in.sin_port = htons(proxy_port);

    // Bind the proxy socket to the given address and port.
    if (bind(socket_fd, (struct sockaddr *) &proxy_address_in, sizeof(proxy_address_in)) < 0) {
        fprintf(stderr, "Failed to bind: %s\n", strerror(errno));
        return -1;
    }

    // Listen for incoming connections.
    if (listen(socket_fd, 10) < 0) {
        fprintf(stderr, "Failed to listen: %s\n", strerror(errno));
        return -1;
    }

    printf("Proxy running at %s:%d\n", proxy_address, proxy_port);

    // Handle incoming connections.
    while (true) {
        socklen_t client_address_in_len = sizeof(client_address_in);

        // Accept a new connection.
        client_fd = accept(socket_fd, (struct sockaddr *) &client_address_in, &client_address_in_len);

        if (client_fd < 0) {
            fprintf(stderr, "Failed to accept: %s\n", strerror(errno));
            continue;
        }

        // Read the incoming data.
        read_count = recv(client_fd, client_buffer, MAX_BUFFER_SIZE, 0);

        if (read_count < 0) {
            fprintf(stderr, "Failed to read: %s\n", strerror(errno));
            continue;
        }

        // Print the incoming data.
        printf("Incoming request:\n");
        printf("%s\n", client_buffer);

        // Close the client socket.
        close(client_fd);
    }

    // Close the server socket.
    close(socket_fd);

    return 0;
}