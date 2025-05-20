//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handleError(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        handleError("socket failed");

    // Attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
        handleError("setsockopt");

    // Binding the socket to the port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
        handleError("bind failed");
    
    if (listen(server_fd, 3) < 0)
        handleError("listen");

    printf("🌼 Server is listening on port %d...\n", PORT);
    
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
        handleError("accept");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int read_size = read(new_socket, buffer, BUFFER_SIZE);
        if (read_size == 0) {
            printf("❌ Client disconnected...\n");
            break;
        }
        printf("🌼 Client: %s\n", buffer);
        
        if (strncmp(buffer, "exit", 4) == 0) {
            printf("🌼 Ending conversation...\n");
            break;
        }

        printf("🌼 You: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(new_socket, buffer, strlen(buffer), 0);
    }

    close(new_socket);
    close(server_fd);
}

void client() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        handleError("Socket creation error");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
        handleError("Invalid address/ Address not supported");
    
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        handleError("Connection Failed");

    while (1) {
        printf("🌼 You: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(sock, buffer, strlen(buffer), 0);

        if (strncmp(buffer, "exit", 4) == 0) {
            printf("🌼 Ending conversation...\n");
            break;
        }

        memset(buffer, 0, BUFFER_SIZE);
        int read_size = read(sock, buffer, BUFFER_SIZE);
        if (read_size == 0) {
            printf("❌ Server disconnected...\n");
            break;
        }
        printf("🌼 Server: %s\n", buffer);
    }

    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc < 2 || (strcmp(argv[1], "server") != 0 && strcmp(argv[1], "client") != 0)) {
        fprintf(stderr, "Usage: %s [server|client]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "server") == 0) {
        server();
    } else {
        client();
    }

    return 0;
}