//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define IP_CLASS_A  0xFF000000
#define IP_CLASS_B  0xFFFF0000
#define IP_CLASS_C  0xFFFFFF00

void handle_client(int client_socket);
void filter_ips(const char *ip);
int is_ip_allowed(const char *ip);
void log_event(const char *event);

int banned_ips_count = 0;
char *banned_ips[100];

int main() {
    // Initialize the banned IPs
    banned_ips[banned_ips_count++] = "192.168.1.100"; // Example of a banned IP
    banned_ips[banned_ips_count++] = "10.0.0.50";    // Another banned IP

    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Initialize the socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_socket, 5) == -1) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    printf("Firewall is running and listening on port %d\n", PORT);

    while (1) {
        // Accept an incoming connection
        if ((client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_len)) == -1) {
            perror("Accept failed");
            continue;
        }

        // Convert IP address to string
        char ip_str[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(client_addr.sin_addr), ip_str, sizeof(ip_str));

        // Filter the incoming IP
        filter_ips(ip_str);

        // Handle client interaction
        handle_client(client_socket);
    }

    close(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read = read(client_socket, buffer, sizeof(buffer) - 1);
    
    if (bytes_read < 0) {
        perror("Read failed");
        close(client_socket);
        return;
    }

    buffer[bytes_read] = '\0';
    
    printf("Received request: %s\n", buffer);
    const char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 42\n\nHello from the Firewall!";
    write(client_socket, response, strlen(response));

    log_event("Handled request successfully.");
    close(client_socket);
}

void filter_ips(const char *ip) {
    if (is_ip_allowed(ip)) {
        log_event("IP allowed: ");
    } else {
        log_event("Blocked IP attempted access: ");
        fprintf(stderr, "Blocked access from IP: %s\n", ip);
        exit(EXIT_FAILURE); // To demonstrate, we exit on block
    }
}

int is_ip_allowed(const char *ip) {
    for (int i = 0; i < banned_ips_count; i++) {
        if (strcmp(ip, banned_ips[i]) == 0) {
            return 0; // IP is banned
        }
    }
    return 1; // IP is allowed
}

void log_event(const char *event) {
    FILE *log_file = fopen("firewall.log", "a");
    if (log_file) {
        fprintf(log_file, "%s: %s\n", event, strerror(errno));
        fclose(log_file);
    } else {
        perror("Could not open log file");
    }
}