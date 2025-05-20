//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

// Constants
#define DEFAULT_PORT 80
#define DEFAULT_TIMEOUT 1000 // milliseconds

// Function prototypes
int create_socket(const char *hostname, int port);
void send_packet(int socket_fd, struct sockaddr_in *addr);
void receive_packet(int socket_fd, struct sockaddr_in *addr);
void close_socket(int socket_fd);

int main(int argc, char **argv) {
    // Check command-line arguments
    if (argc < 2) {
        printf("Usage: %s hostname [port] [timeout]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse command-line arguments
    const char *hostname = argv[1];
    int port = DEFAULT_PORT;
    int timeout = DEFAULT_TIMEOUT;
    if (argc >= 3) {
        port = atoi(argv[2]);
    }
    if (argc >= 4) {
        timeout = atoi(argv[3]);
    }

    // Create a socket
    int socket_fd = create_socket(hostname, port);
    if (socket_fd == -1) {
        perror("create_socket");
        return EXIT_FAILURE;
    }

    // Construct the destination address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(hostname);

    // Send a packet
    send_packet(socket_fd, &addr);

    // Receive a packet
    receive_packet(socket_fd, &addr);

    // Close the socket
    close_socket(socket_fd);

    return EXIT_SUCCESS;
}

int create_socket(const char *hostname, int port) {
    // Create a socket
    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd == -1) {
        return -1;
    }

    // Bind the socket to a random port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = 0;
    if (bind(socket_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        close(socket_fd);
        return -1;
    }

    // Set the socket timeout
    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 1000 * DEFAULT_TIMEOUT;
    if (setsockopt(socket_fd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        close(socket_fd);
        return -1;
    }

    return socket_fd;
}

void send_packet(int socket_fd, struct sockaddr_in *addr) {
    // Send a packet
    char *data = "PING";
    int data_len = strlen(data);
    if (sendto(socket_fd, data, data_len, 0, (struct sockaddr *)addr, sizeof(*addr)) == -1) {
        perror("sendto");
    }
}

void receive_packet(int socket_fd, struct sockaddr_in *addr) {
    // Receive a packet
    char buffer[1024];
    int addr_len = sizeof(*addr);
    int bytes_received = recvfrom(socket_fd, buffer, sizeof(buffer), 0, (struct sockaddr *)addr, &addr_len);
    if (bytes_received == -1) {
        perror("recvfrom");
    } else {
        printf("Received packet from %s:%d\n", inet_ntoa(addr->sin_addr), ntohs(addr->sin_port));
        printf("Data: %s\n", buffer);
    }
}

void close_socket(int socket_fd) {
    // Close the socket
    close(socket_fd);
}