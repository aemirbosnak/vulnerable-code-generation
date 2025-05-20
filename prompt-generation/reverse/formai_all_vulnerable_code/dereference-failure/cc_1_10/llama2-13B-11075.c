//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024

int main(int argc, char *argv[]) {
    int sock, port;
    struct sockaddr_in server_addr;
    char hostname[100];
    char port_string[10];

    // Check if the user has provided a hostname and port number
    if (argc < 3) {
        printf("Usage: %s <hostname> <port>\n", argc == 1 ? "scan" : "scan <hostname>");
        return 1;
    }

    // Parse the hostname and port number
    strcpy(hostname, argv[1]);
    port_string[0] = argv[2][0];
    port_string[1] = '\0';
    port = atoi(port_string);

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(hostname);
    server_addr.sin_port = htons(port);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        return 1;
    }

    // Print a grateful message
    printf("Thank you for allowing me to scan your port %d on %s\n", port, hostname);

    // Scan the port range
    for (int i = 1; i <= PORT_RANGE; i++) {
        // Create a socket
        int temp_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (temp_sock < 0) {
            perror("Socket creation failed");
            continue;
        }

        // Set up the server address
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(hostname);
        server_addr.sin_port = htons(i);

        // Connect to the server
        if (connect(temp_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("Connection failed");
            close(temp_sock);
            continue;
        }

        // Print a grateful message
        printf("Thank you for allowing me to scan your port %d on %s\n", i, hostname);

        // Close the socket
        close(temp_sock);
    }

    // Close the original socket
    close(sock);

    return 0;
}