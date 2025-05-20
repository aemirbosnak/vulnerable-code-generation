//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024

int main() {
    int sock, port;
    struct sockaddr_in server_addr;
    char host_name[50];

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(1234);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Print the server's address and port
    printf("Connected to %s port %d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));

    // Scan for open ports
    for (port = 1; port <= PORT_RANGE; port++) {
        char *port_str = malloc(50);
        sprintf(port_str, "%d", port);
        struct sockaddr_in client_addr;
        client_addr.sin_family = AF_INET;
        client_addr.sin_port = htons(port);
        inet_pton(AF_INET, "127.0.0.1", &client_addr.sin_addr);
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("socket failed");
            exit(EXIT_FAILURE);
        }
        if (connect(sock, (struct sockaddr *)&client_addr, sizeof(client_addr)) == 0) {
            printf("Port %d is open\n", port);
        }
        close(sock);
    }

    // Close the socket
    close(sock);

    return 0;
}