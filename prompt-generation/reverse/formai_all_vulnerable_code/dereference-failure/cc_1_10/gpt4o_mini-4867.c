//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void print_usage() {
    printf("Usage: ./firewall <ip> <port>\n");
    printf("Example: ./firewall 192.168.1.100 8080\n");
}

int is_ip_allowed(char *ip, char *allowed_ip) {
    return strcmp(ip, allowed_ip) == 0;
}

void handle_request(int client_socket, char *allowed_ip) {
    char buffer[BUFFER_SIZE];
    char client_ip[INET_ADDRSTRLEN];
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    getpeername(client_socket, (struct sockaddr*)&client_addr, &client_len);
    inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, sizeof(client_ip));

    printf("Incoming connection from %s\n", client_ip);

    if (!is_ip_allowed(client_ip, allowed_ip)) {
        printf("Connection rejected from %s\n", client_ip);
        close(client_socket);
        return;
    }

    printf("Connection accepted from %s\n", client_ip);
    
    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Received request: %s\n", buffer);

    // Construct a simple response
    char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, World!";
    send(client_socket, response, strlen(response), 0);

    close(client_socket);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    char *allowed_ip = argv[1];
    int port = atoi(argv[2]);

    int server_socket, client_socket;
    struct sockaddr_in server_addr;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    printf("Firewall running. Listening on port %d, allowing IP: %s\n", port, allowed_ip);

    while (1) {
        client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }
        handle_request(client_socket, allowed_ip);
    }

    close(server_socket);
    return EXIT_SUCCESS;
}