//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024
#define BLOCKED_PORT 8080
#define BLOCKED_IP "192.168.1.10"

void log_blocked_access(char *ip, int port) {
    FILE *log_file = fopen("firewall.log", "a");
    if (log_file) {
        fprintf(log_file, "Blocked access from IP: %s on port: %d\n", ip, port);
        fclose(log_file);
    }
}

int is_blocked_ip(char *ip) {
    return strcmp(ip, BLOCKED_IP) == 0;
}

int is_blocked_port(int port) {
    return port == BLOCKED_PORT;
}

void handle_connection(int client_socket, struct sockaddr_in client_addr) {
    char buffer[MAX_BUFFER];
    char *client_ip = inet_ntoa(client_addr.sin_addr);
    int client_port = ntohs(client_addr.sin_port);

    if (is_blocked_ip(client_ip) || is_blocked_port(client_port)) {
        log_blocked_access(client_ip, client_port);
        close(client_socket);
        printf("Blocked connection attempt from IP: %s on port: %d\n", client_ip, client_port);
        return;
    }

    // Handle allowed connection
    recv(client_socket, buffer, MAX_BUFFER, 0);
    printf("Received data: %s\n", buffer);

    // Respond to the client
    char *response = "Hello from Firewall!";
    send(client_socket, response, strlen(response), 0);
    close(client_socket);
}

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) < 0) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Firewall listening on port %d...\n", ntohs(server_addr.sin_port));

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Failed to accept connection");
            continue;
        }

        handle_connection(client_socket, client_addr);
    }

    close(server_socket);
    return 0;
}