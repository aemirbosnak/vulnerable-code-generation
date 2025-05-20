//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024

int main(int argc, char *argv[]) {
    int sock, port, i;
    struct sockaddr_in server_addr;
    char buffer[256];

    // Check if user entered a valid port range
    if (argc < 2 || atoi(argv[1]) < 1 || atoi(argv[1]) > 65535) {
        printf("Invalid port range. Please enter a valid range (e.g. 1-65535)\n");
        return 1;
    }

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        return 2;
    }

    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(0);

    // Bind the socket to a specific address and port
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        return 3;
    }

    // Listen for incoming connections
    if (listen(sock, 5) < 0) {
        perror("listen failed");
        return 4;
    }

    // Loop through the port range and perform a connect() on each port
    for (i = 1; i <= atoi(argv[1]); i++) {
        // Set up the client address structure
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(i);

        // Perform a connect() on the current port
        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            // If connect() fails, print an error message
            perror("connect failed");
            continue;
        }

        // Print the successful port number
        printf("Port %d is open\n", ntohs(server_addr.sin_port));

        // Close the socket and move on to the next port
        close(sock);
    }

    // Close the listening socket
    close(sock);

    return 0;
}