//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define PORT 8080
#define ALLOWED_IPS "192.168.1.100,192.168.1.200"

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Allow only specified IP addresses to connect
    char *ips = ALLOWED_IPS;
    char *token;
    token = strtok(ips, ",");
    while (token != NULL) {
        struct in_addr addr;
        inet_pton(AF_INET, token, &addr);
        if (inet_pton(AF_INET, token, &server_addr.sin_addr) > 0) {
            printf("Allowing connection from %s\n", token);
        }
        token = strtok(NULL, ",");
    }

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sock, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", PORT);

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Handle incoming connections
        char buffer[1024];
        read(client_sock, buffer, 1024);
        printf("Received message from client: %s\n", buffer);

        // Send a response back to the client
        char *message = "Hello, world!";
        send(client_sock, message, strlen(message), 0);

        close(client_sock);
    }

    close(sock);
    return 0;
}