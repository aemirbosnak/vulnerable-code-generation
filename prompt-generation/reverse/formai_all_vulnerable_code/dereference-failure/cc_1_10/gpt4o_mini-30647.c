//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_server(int server_fd) {
    char buffer[BUFFER_SIZE] = {0};
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int new_socket;

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);
        if (new_socket < 0) {
            perror("Accept failed");
            continue;
        }
        
        int valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread < 0) {
            perror("Read failed");
            close(new_socket);
            continue;
        }

        printf("Received: %s\n", buffer);
        send(new_socket, buffer, valread, 0);
        printf("Echoed: %s\n", buffer);
        close(new_socket);
    }
}

void start_server() {
    int server_fd;
    struct sockaddr_in address;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);
    handle_server(server_fd);
    close(server_fd);
}

void start_client() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *message = "Hello from client";
    char buffer[BUFFER_SIZE] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation error");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        return;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        return;
    }

    send(sock, message, strlen(message), 0);
    printf("Message sent: %s\n", message);
    
    int valread = read(sock, buffer, BUFFER_SIZE);
    if (valread < 0) {
        perror("Read failed");
    } else {
        printf("Message received: %s\n", buffer);
    }

    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <server|client>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "server") == 0) {
        start_server();
    } else if (strcmp(argv[1], "client") == 0) {
        sleep(1);  // Ensure server starts up
        start_client();
    } else {
        fprintf(stderr, "Unknown argument: %s\n", argv[1]);
    }

    return 0;
}