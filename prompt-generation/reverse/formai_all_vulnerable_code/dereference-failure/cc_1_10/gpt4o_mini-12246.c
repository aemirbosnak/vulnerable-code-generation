//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CONNECTIONS 10
#define MAX_IP_LENGTH 16
#define MAX_IP_RULES 100

static char *allowed_ips[MAX_IP_RULES];
static int ip_rule_count = 0;

void add_ip_rule(const char *ip) {
    if (ip_rule_count < MAX_IP_RULES) {
        allowed_ips[ip_rule_count] = strdup(ip);
        ip_rule_count++;
    } else {
        printf("IP rule limit reached!\n");
    }
}

int is_ip_allowed(const char *ip) {
    for (int i = 0; i < ip_rule_count; i++) {
        if (strcmp(allowed_ips[i], ip) == 0) {
            return 1; // Allowed
        }
    }
    return 0; // Not allowed
}

void clean_up() {
    for (int i = 0; i < ip_rule_count; i++) {
        free(allowed_ips[i]);
    }
}

void log_connection(const char *ip) {
    printf("Connection from %s accepted.\n", ip);
}

void log_denied(const char *ip) {
    printf("Connection from %s denied.\n", ip);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Initialize IP rules
    add_ip_rule("192.168.1.10");
    add_ip_rule("192.168.1.15");

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }
    
    // Configure server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Firewall running on port %d...\n", PORT);
    
    while (1) {
        // Accept incoming connections
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue; // Skip to next iteration
        }
        
        char client_ip[MAX_IP_LENGTH];
        inet_ntop(AF_INET, &address.sin_addr, client_ip, sizeof(client_ip));
        
        // Check if the IP is allowed
        if (is_ip_allowed(client_ip)) {
            log_connection(client_ip);
            // Here, you would handle the accepted connection.
        } else {
            log_denied(client_ip);
            close(new_socket); // Close the connection for denied IPs
        }
    }
    
    clean_up();

    return 0;
}