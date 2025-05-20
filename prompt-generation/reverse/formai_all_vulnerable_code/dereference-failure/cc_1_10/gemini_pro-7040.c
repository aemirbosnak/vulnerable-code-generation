//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

// Port scanner program
int main(int argc, char *argv[]) {

    // Check for command-line arguments
    if (argc != 3) {
        printf("Usage: %s <target> <port>\n", argv[0]);
        return 1;
    }

    // Get the target host and port
    char *target = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 2;
    }

    // Connect to the target host and port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(target);

    int ret = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    if (ret < 0) {
        perror("connect");
        close(sock);
        return 3;
    }

    // Print the port status
    if (ret == 0) {
        printf("Port %d is open on %s\n", port, target);
    } else {
        printf("Port %d is closed on %s\n", port, target);
    }

    // Close the socket
    close(sock);
    return 0;
}