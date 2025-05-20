//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    if (inet_pton(AF_INET, ip_address, &server_addr.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        close(socket_fd);
        return 1;
    }

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        close(socket_fd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Send ping request
    if (send(socket_fd, "PING", strlen("PING"), 0) == -1) {
        printf("Error sending ping request: %s\n", strerror(errno));
        close(socket_fd);
        return 1;
    }

    // Receive response
    memset(buffer, 0, BUFFER_SIZE);
    if ((bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0)) <= 0) {
        printf("Error receiving response: %s\n", strerror(errno));
        close(socket_fd);
        return 1;
    }

    printf("Response: %s\n", buffer);

    close(socket_fd);
    return 0;
}