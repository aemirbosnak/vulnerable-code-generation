//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, port, i;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    if (argc < 2) {
        printf("Usage: %s <IP_ADDRESS>\n", argv[0]);
        return 1;
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        return 1;
    }

    // Set IP address and port number
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    port = atoi(argv[2]);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        return 1;
    }

    // Send SYN packet to the server
    send(sock, "SYN", 3, 0);

    // Receive response from the server
    recv(sock, buffer, BUFFER_SIZE, 0);

    // Check the response
    if (strcmp(buffer, "ACK") != 0) {
        printf("Invalid response from the server\n");
        return 1;
    }

    // Scan the port range
    for (i = 1; i < PORT_RANGE; i++) {
        // Create a socket for the current port
        int temp_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (temp_sock < 0) {
            perror("socket failed");
            continue;
        }

        // Set the port number
        server_addr.sin_port = htons(i);

        // Connect to the server
        if (connect(temp_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("connect failed");
            close(temp_sock);
            continue;
        }

        // Send a packet to the server
        send(temp_sock, "Hello, this is a port scan\n", 24, 0);

        // Receive the response from the server
        recv(temp_sock, buffer, BUFFER_SIZE, 0);

        // Check the response
        if (strcmp(buffer, "Hello, this is a port scan\n") != 0) {
            printf("Port %d is open\n", i);
        }

        // Close the socket
        close(temp_sock);
    }

    // Close the original socket
    close(sock);

    return 0;
}