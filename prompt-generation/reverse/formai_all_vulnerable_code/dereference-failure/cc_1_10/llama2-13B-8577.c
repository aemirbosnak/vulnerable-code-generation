//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: standalone
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

    // Check if there are any command line arguments
    if (argc < 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    // Parse the hostname from the command line argument
    strcpy(hostname, argv[1]);

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return 1;
    }

    // Set up the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(hostname);
    server_addr.sin_port = htons(0);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        return 1;
    }

    // Send a SYN packet to the server to initiate the handshake
    send(sock, "SYN", 3, 0);

    // Receive the SYN-ACK packet from the server
    recv(sock, NULL, 0, MSG_PEEK);

    // Send an ACK packet to the server to complete the handshake
    send(sock, "ACK", 3, 0);

    // Receive the final ACK packet from the server
    recv(sock, NULL, 0, MSG_PEEK);

    // Close the connection
    close(sock);

    // Iterate over the range of possible ports and perform a connect()
    for (port = 1; port <= PORT_RANGE; port++) {
        // Set up the server address structure with the current port
        server_addr.sin_port = htons(port);

        // Connect to the server
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("socket() failed");
            continue;
        }

        // Send a SYN packet to the server to initiate the handshake
        send(sock, "SYN", 3, 0);

        // Receive the SYN-ACK packet from the server
        recv(sock, NULL, 0, MSG_PEEK);

        // Send an ACK packet to the server to complete the handshake
        send(sock, "ACK", 3, 0);

        // Receive the final ACK packet from the server
        recv(sock, NULL, 0, MSG_PEEK);

        // Close the connection
        close(sock);
    }

    return 0;
}