//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUF 1024

// Function prototypes
void start_server();
void start_client(const char *message);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <message to echo>\n", argv[0]);
        printf("Starting server...\n");
        start_server();
    } else {
        printf("Starting client with message: \"%s\"\n", argv[1]);
        start_client(argv[1]);
    }
    return 0;
}

void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_BUF] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Setting up server address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accepting new connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    while (1) {
        memset(buffer, 0, MAX_BUF);
        int valread = read(new_socket, buffer, MAX_BUF);
        if (valread <= 0) {
            perror("read error or client disconnected");
            break;
        }
        printf("Received: %s\n", buffer);
        send(new_socket, buffer, strlen(buffer), 0);
        printf("Echoed: %s\n", buffer);
    }

    close(new_socket);
    close(server_fd);
}

void start_client(const char *message) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUF] = {0};

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return;
    }

    // Server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }

    // Connecting to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return;
    }

    // Sending message
    send(sock, message, strlen(message), 0);
    printf("Message sent: %s\n", message);

    // Receiving echoed message
    int valread = read(sock, buffer, MAX_BUF);
    if (valread <= 0) {
        printf("Error reading echoed message\n");
    } else {
        printf("Received echo: %s\n", buffer);
    }

    close(sock);
}