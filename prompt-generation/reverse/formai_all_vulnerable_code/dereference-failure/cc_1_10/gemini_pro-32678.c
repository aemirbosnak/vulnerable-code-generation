//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <target> <port>\n", argv[0]);
        exit(1);
    }

    // Get the target IP address
    struct in_addr target_addr;
    if (inet_pton(AF_INET, argv[1], &target_addr) != 1) {
        printf("Invalid target IP address: %s\n", argv[1]);
        exit(1);
    }

    // Get the target port
    int target_port = atoi(argv[2]);
    if (target_port < 0 || target_port > 65535) {
        printf("Invalid target port: %s\n", argv[2]);
        exit(1);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set the socket options
    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    // Connect to the target
    struct sockaddr_in target_addr_struct;
    target_addr_struct.sin_family = AF_INET;
    target_addr_struct.sin_addr = target_addr;
    target_addr_struct.sin_port = htons(target_port);
    if (connect(sockfd, (struct sockaddr *)&target_addr_struct, sizeof(target_addr_struct)) == -1) {
        perror("connect");
        close(sockfd);
        exit(1);
    }

    // Send some data to the target
    char *data = "Hello from the port scanner!";
    if (send(sockfd, data, strlen(data), 0) == -1) {
        perror("send");
        close(sockfd);
        exit(1);
    }

    // Receive some data from the target
    char buffer[1024];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
        perror("recv");
        close(sockfd);
        exit(1);
    }

    // Print the data received from the target
    printf("Received %d bytes from %s:%d:\n", bytes_received, argv[1], target_port);
    printf("%s", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}