//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;
    
    while ((bytes_read = read(client_socket, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Client: %s", buffer);
        // Echo back the message
        write(client_socket, buffer, bytes_read);
    }
    
    if (bytes_read < 0) {
        perror("Read error");
    }
    
    close(client_socket);
    printf("Client disconnected.\n");
}

void start_server() {
    int server_fd, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addrlen = sizeof(client_addr);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d.\n", PORT);
    
    while (1) {
        if ((client_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }

        printf("New client connected.\n");

        if (fork() == 0) {
            close(server_fd);
            handle_client(client_socket);
            exit(0);
        }

        close(client_socket);
    }
}

void client_send_message(const char *message) {
    int sock;
    struct sockaddr_in server_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        return;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return;
    }

    send(sock, message, strlen(message), 0);
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "server") == 0) {
        start_server();
    } else {
        char message[BUFFER_SIZE];
        while (1) {
            printf("Enter message: ");
            fgets(message, sizeof(message), stdin);
            client_send_message(message);
        }
    }
    return 0;
}