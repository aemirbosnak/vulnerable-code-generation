//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024
#define ALLOW_LIST_SIZE 3

const char *allowed_ips[ALLOW_LIST_SIZE] = {
    "192.168.0.5",
    "192.168.0.10",
    "10.0.0.1"
};

int is_ip_allowed(const char *ip) {
    for (int i = 0; i < ALLOW_LIST_SIZE; i++) {
        if (strcmp(ip, allowed_ips[i]) == 0) {
            return 1; // IP is allowed
        }
    }
    return 0; // IP is not allowed
}

void log_attempt(const char *ip) {
    FILE *log_file = fopen("firewall.log", "a");
    if (log_file == NULL) {
        perror("Could not open log file");
        return;
    }
    
    fprintf(log_file, "Connection attempt from disallowed IP: %s\n", ip);
    fclose(log_file);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Listen on any IP address
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Firewall running... Listening on port %d\n", PORT);
    
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        char *client_ip = inet_ntoa(address.sin_addr);
        printf("Connection attempt from IP: %s\n", client_ip);

        if (is_ip_allowed(client_ip)) {
            printf("IP %s is allowed.\n", client_ip);
            send(new_socket, "Welcome to the server!\n", 24, 0);
        } else {
            printf("IP %s is not allowed. Closing connection.\n", client_ip);
            log_attempt(client_ip);
            send(new_socket, "Access denied!\n", 16, 0);
            close(new_socket);
            continue;
        }

        int valread = read(new_socket, buffer, BUFFER_SIZE);
        printf("Received message: %s\n", buffer);
        
        // Echo back the message
        send(new_socket, buffer, valread, 0);
        printf("Echoed message back to %s\n", client_ip);
        close(new_socket);
    }

    return 0;
}