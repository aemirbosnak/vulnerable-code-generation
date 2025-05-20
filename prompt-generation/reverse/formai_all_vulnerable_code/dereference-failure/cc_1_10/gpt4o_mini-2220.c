//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PORT 8080
#define BLACKLIST_SIZE 5
#define BUFFER_SIZE 1024

const char *blacklist[BLACKLIST_SIZE] = {
    "192.168.1.100",
    "203.0.113.5",
    "10.0.0.1",
    "172.16.0.10",
    "198.51.100.23"
};

void check_ip(char *ip) {
    for (int i = 0; i < BLACKLIST_SIZE; i++) {
        if (strcmp(ip, blacklist[i]) == 0) {
            printf("Access denied for IP: %s\n", ip);
            return;
        }
    }
    printf("Access granted for IP: %s\n", ip);
}

void handle_connection(int new_socket) {
    char buffer[BUFFER_SIZE] = {0};
    struct sockaddr_in address;
    socklen_t addr_len = sizeof(address);
    
    // Get client address
    if (getpeername(new_socket, (struct sockaddr *)&address, &addr_len) < 0) {
        perror("getpeername");
        close(new_socket);
        return;
    }
    
    char *client_ip = inet_ntoa(address.sin_addr);
    check_ip(client_ip);

    // Echo back the message to the client
    int read_val = read(new_socket, buffer, BUFFER_SIZE);
    if (read_val > 0) {
        printf("Received message from %s: %s\n", client_ip, buffer);
        send(new_socket, buffer, strlen(buffer), 0);
    }

    close(new_socket);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Firewall running. Listening on port %d...\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                       (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        
        // Handle each connection
        handle_connection(new_socket);
    }

    return 0;
}