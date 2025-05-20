//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Structure to hold the target information
typedef struct {
    char *target_ip;
    int target_port;
} target_info;

// Function to create a socket and connect to the target
int connect_to_target(target_info *target) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        return -1;
    }

    // Set the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(target->target_port);
    server_addr.sin_addr.s_addr = inet_addr(target->target_ip);

    // Connect to the target
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to target");
        return -1;
    }

    return sockfd;
}

// Function to scan a target for open ports
int scan_target(target_info *target) {
    int sockfd;
    int status = -1;

    // Create a socket and connect to the target
    sockfd = connect_to_target(target);
    if (sockfd == -1) {
        return -1;
    }

    // Send a message to the target
    char *message = "Hello from the port scanner!";
    if (send(sockfd, message, strlen(message), 0) == -1) {
        perror("Error sending message to target");
        close(sockfd);
        return -1;
    }

    // Receive a response from the target
    char response[1024];
    if (recv(sockfd, response, 1024, 0) == -1) {
        perror("Error receiving response from target");
        close(sockfd);
        return -1;
    }

    // Check if the target responded
    if (strcmp(response, "Hello from the target!") == 0) {
        status = 0;
    }

    // Close the socket
    close(sockfd);

    return status;
}

// Main function
int main(int argc, char **argv) {
    int i;
    int num_ports;
    int num_targets;
    target_info *targets;

    // Check the arguments
    if (argc < 4) {
        printf("Usage: %s <target IP> <target port> <number of targets>\n", argv[0]);
        return 1;
    }

    // Parse the arguments
    num_targets = atoi(argv[3]);
    targets = (target_info *) malloc(sizeof(target_info) * num_targets);
    for (i = 0; i < num_targets; i++) {
        targets[i].target_ip = argv[1];
        targets[i].target_port = atoi(argv[2]);
    }

    // Scan the targets
    for (i = 0; i < num_targets; i++) {
        if (scan_target(&targets[i]) == 0) {
            printf("Port %d is open on %s\n", targets[i].target_port, targets[i].target_ip);
        }
    }

    // Free the memory allocated for the targets
    free(targets);

    return 0;
}