//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to create and set up the server
void setup_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    // Defining the server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("🛑 Server is listening on port %d...\n", PORT);

    // Accepting a connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Communicating with the client
    while (1) {
        int read_size = read(new_socket, buffer, BUFFER_SIZE);
        if (read_size <= 0) {
            printf("❌ Connection closed by client.\n");
            break;
        }
        printf("📩 Received message: %s\n", buffer);
        send(new_socket, buffer, strlen(buffer), 0);
        printf("📬 Echoed message back to client.\n");
        memset(buffer, 0, BUFFER_SIZE);
    }

    close(new_socket);
    close(server_fd);
}

// Function to create the client
void setup_client(const char* ip_address) {
    struct sockaddr_in serv_addr;
    char *message = "Hello, Server! This is Client.";
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    int sock = 0;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("❌ Socket creation error\n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, ip_address, &serv_addr.sin_addr) <= 0) {
        printf("❌ Invalid address/ Address not supported\n");
        return;
    }

    // Attempt to connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("❌ Connection failed\n");
        return;
    }

    // Send message to server
    send(sock, message, strlen(message), 0);
    printf("📤 Sent message to server: %s\n", message);

    // Receive echoed message from server
    int valread = read(sock, buffer, BUFFER_SIZE);
    printf("📥 Received echoed message: %s\n", buffer);

    // Close the socket
    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc == 2 && strcmp(argv[1], "server") == 0) {
        setup_server();
    } else if (argc == 3 && strcmp(argv[1], "client") == 0) {
        setup_client(argv[2]);
    } else {
        printf("Usage:\n");
        printf("  To run server: %s server\n", argv[0]);
        printf("  To run client: %s client <server_ip>\n", argv[0]);
    }
    return 0;
}