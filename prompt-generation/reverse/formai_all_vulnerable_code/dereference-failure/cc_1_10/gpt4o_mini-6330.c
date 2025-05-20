//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 256

void start_server() {
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

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Watson: Ready to assist, Holmes!\n");

    // Accept the incoming connection from Holmes
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        read(new_socket, buffer, BUFFER_SIZE);
        printf("Holmes: \"%s\"\n", buffer);
    
        // Respond with a clever quip
        if (strcmp(buffer, "What is the case?") == 0) {
            send(new_socket, "It is elementary, my dear Watson.", strlen("It is elementary, my dear Watson."), 0);
        } else if (strcmp(buffer, "What do we know?") == 0) {
            send(new_socket, "Knowledge is power, as we both know.", strlen("Knowledge is power, as we both know."), 0);
        } else {
            send(new_socket, "A mystery yet unsolved, dear Holmes.", strlen("A mystery yet unsolved, dear Holmes."), 0);
        }
    }

    close(new_socket);
    close(server_fd);
}

void start_client() {
    struct sockaddr_in serv_addr;
    int sock = 0;
    char *message;
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return;
    }

    // Inquiries to be made by Holmes
    message = "What is the case?";
    send(sock, message, strlen(message), 0);
    read(sock, buffer, BUFFER_SIZE);
    printf("Watson: \"%s\"\n", buffer);

    message = "What do we know?";
    send(sock, message, strlen(message), 0);
    read(sock, buffer, BUFFER_SIZE);
    printf("Watson: \"%s\"\n", buffer);

    message = "Tell me, Watson!";
    send(sock, message, strlen(message), 0);
    read(sock, buffer, BUFFER_SIZE);
    printf("Watson: \"%s\"\n", buffer);

    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <server/client>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "server") == 0) {
        start_server();
    } else if (strcmp(argv[1], "client") == 0) {
        start_client();
    } else {
        fprintf(stderr, "Invalid argument. Please use 'server' or 'client'.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}