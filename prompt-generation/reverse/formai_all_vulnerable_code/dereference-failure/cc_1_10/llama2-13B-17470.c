//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define PORT 8080
#define IP_ADDRESS "192.168.1.100"

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[256];

    // Create a listening socket
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Set address and port number for the listening socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, IP_ADDRESS, &server_addr.sin_addr);

    // Bind the listening socket to the address and port
    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listen_fd, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Listening for incoming connections...\n");

    while (1) {
        // Accept an incoming connection
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_len);
        if (conn_fd < 0) {
            perror("accept failed");
            continue;
        }

        // Check if the client is trying to connect to the specific IP address
        if (strcmp(client_addr.sin_addr.s_addr, inet_addr(IP_ADDRESS)) != 0) {
            close(conn_fd);
            continue;
        }

        // Allow the connection and set up the communication
        printf("Connection accepted from %s\n", inet_ntoa(client_addr.sin_addr));
        // ... communicate with the client ...

        close(conn_fd);
    }

    return 0;
}