//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {

    // Check if the correct number of arguments have been provided
    if (argc != 3) {
        printf("Usage: %s <target IP> <target port>\n", argv[0]);
        exit(1);
    }

    // Get the target IP and port from the command-line arguments
    char *target_ip = argv[1];
    int target_port = atoi(argv[2]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        exit(1);
    }

    // Set up the target address
    struct sockaddr_in target_addr;
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(target_port);
    target_addr.sin_addr.s_addr = inet_addr(target_ip);

    // Connect to the target
    if (connect(sock, (struct sockaddr *)&target_addr, sizeof(target_addr)) < 0) {
        perror("connect() failed");
        exit(1);
    }

    // Send a message to the target
    char *message = "Hello, world!\n";
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("send() failed");
        exit(1);
    }

    // Receive a response from the target
    char *buffer = malloc(1024);
    if (recv(sock, buffer, 1024, 0) < 0) {
        perror("recv() failed");
        exit(1);
    }

    // Print the response
    printf("%s", buffer);

    // Close the socket
    close(sock);

    return 0;
}