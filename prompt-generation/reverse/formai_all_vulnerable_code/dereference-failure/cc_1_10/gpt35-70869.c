//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PACKET_SIZE 1024 // Packet size to be sent
#define TIMEOUT 2 // Timeout for receiving server response

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <Server IP> <Server Port>\n", argv[0]);
        exit(1);
    }
    
    // Create socket
    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd < 0) { 
        perror("ERROR: Failed to create socket");
        exit(1);
    }

    // Set QoS for the socket
    int qos = 3; // Example QoS level
    if (setsockopt(sock_fd, SOL_SOCKET, SO_PRIORITY, &qos, sizeof(qos)) < 0) {
        perror("ERROR: Failed to set QoS");
        exit(1);
    }

    // Server address to send data to
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr)); // Initialize memory
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2])); // Server port
    server_addr.sin_addr.s_addr = inet_addr(argv[1]); // Server IP address

    // Send data packet to server
    char data[PACKET_SIZE];
    memset(data, 'a', PACKET_SIZE); // Fill packet with data
    if (sendto(sock_fd, data, PACKET_SIZE, 0, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR: Failed to send data packet");
        exit(1);
    }

    // Wait for response from server
    char response[PACKET_SIZE];
    memset(response, 0, PACKET_SIZE); // Initialize memory
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0; // Set timeout value
    if (setsockopt(sock_fd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("ERROR: Failed to set timeout for socket");
        exit(1);
    }
    int addr_len = sizeof(struct sockaddr);
    if (recvfrom(sock_fd, response, PACKET_SIZE, 0, (struct sockaddr *) &server_addr, &addr_len) < 0) {
        perror("ERROR: Failed to receive response from server");
        exit(1);
    }

    // Display received response from server
    printf("Server response: %s\n", response);

    // Close socket
    close(sock_fd);

    return 0;
}