//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 80
#define BUFFER_SIZE 1024

void error(char *msg) {
   perror(msg);
   exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(0);
    }

    struct hostent *hostent_ptr;
    struct sockaddr_in target_addr;
    char ip_buffer[INET_ADDRSTRLEN];
    char buffer[BUFFER_SIZE];

    // Set up the socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        error("Error opening socket");
    }

    // Get the IP address of the hostname
    hostent_ptr = gethostbyname(argv[1]);
    if (hostent_ptr == NULL) {
        error("Error getting IP address of host");
    }

    // Fill in the target address struct
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(PORT);
    memcpy(&target_addr.sin_addr, hostent_ptr->h_addr, hostent_ptr->h_length);

    // Connect to target
    if (connect(sock_fd, (struct sockaddr*)&target_addr, sizeof(target_addr)) < 0) {
        error("Error connecting to host");
    }

    // Print the target IP address
    inet_ntop(AF_INET, &target_addr.sin_addr, ip_buffer, INET_ADDRSTRLEN);
    printf("Target IP Address: %s\n", ip_buffer);

    // Send a test message and print response
    char *message = "GET / HTTP/1.1\r\n\r\n";
    if (send(sock_fd, message, strlen(message), 0) < 0) {
        error("Error sending message to host");
    }
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        error("Error receiving message from host");
    }
    printf("Response:\n%s", buffer);

    // Close the socket
    close(sock_fd);

    return 0;
}