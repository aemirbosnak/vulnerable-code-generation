//LLAMA2-13B DATASET v1.0 Category: Socket programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

// Structure to store socket settings
struct socket_settings {
    int port;    // Port number to connect
    char host[50];  // Hostname or IP address of the server
};

// Function to parse command line arguments and set socket settings
void parse_arguments(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    struct socket_settings *settings = malloc(sizeof(struct socket_settings));
    settings->port = atoi(argv[1]);
    strcpy(settings->host, argv[2]);
}

// Function to create a socket and connect to the server
int create_socket_and_connect(struct socket_settings *settings) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(settings->port);
    inet_pton(AF_INET, settings->host, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Socket connection failed");
        exit(1);
    }

    return sock;
}

// Function to send a message to the server
int send_message(int sock, char *message) {
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("Message sending failed");
        exit(1);
    }

    return sock;
}

int main(int argc, char *argv[]) {
    struct socket_settings settings;
    parse_arguments(argc, argv);

    int sock = create_socket_and_connect(&settings);
    char message[] = "Hello, server!";

    send_message(sock, message);

    // Wait for the server to send a message back
    char buffer[BUFFER_SIZE];
    recv(sock, buffer, BUFFER_SIZE, 0);

    printf("Received message: %s\n", buffer);

    close(sock);
    return 0;
}