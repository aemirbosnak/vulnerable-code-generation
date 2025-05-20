//FormAI DATASET v1.0 Category: Port Scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#define MAX_PORT_NUMBER 65535
#define TIMEOUT 1
#define BUFFER_SIZE 1024

int connect_to_port(char *address, int port)
{
    struct sockaddr_in server_address;
    struct hostent *server;
    int client_fd;
    int error_num;

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    // Convert hostname to IP address
    if (inet_pton(AF_INET, address, &server_address.sin_addr) <= 0) {
        server = gethostbyname(address);
        if (server == NULL) {
            return -1;
        }
        memcpy(&server_address.sin_addr, server->h_addr, server->h_length);
    }

    // Create socket
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0) {
        return -2;
    }

    // Set socket timeout
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    if (setsockopt(client_fd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        return -3;
    }

    // Connect to the port
    error_num = connect(client_fd, (struct sockaddr *)&server_address, sizeof(server_address));

    if (error_num < 0) {
        return -4;
    }

    return client_fd;
}

int main(int argc, char *argv[])
{
    char *address;
    int port;
    int error_num;
    char buffer[BUFFER_SIZE];
    time_t start_time, end_time;
    double time_taken;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    address = argv[1];

    printf("Scanning ports on %s...\n", address);

    // Start time
    start_time = time(NULL);

    // Scan all ports
    for (port = 1; port <= MAX_PORT_NUMBER; port++) {
        error_num = connect_to_port(address, port);

        switch (error_num) {
            case -1:
                // Unsupported address family
                break;
            case -2:
                // Could not create socket
                break;
            case -3:
                // Failed to set socket timeout
                break;
            case -4:
                // Connection to port failed
                break;
            default:
                // Connection to port success!
                printf("Port %d OPEN\n", port);

                // Receive any data sent by the server
                recv(error_num, buffer, BUFFER_SIZE, 0);
                printf("Received data from port %d:\n%s\n", port, buffer);

                // Close connection to the port
                close(error_num);
        }
    }

    // End time
    end_time = time(NULL);

    // Calculate total time taken
    time_taken = difftime(end_time, start_time);

    printf("Port scan completed in %0.2f seconds\n", time_taken);

    return 0;
}