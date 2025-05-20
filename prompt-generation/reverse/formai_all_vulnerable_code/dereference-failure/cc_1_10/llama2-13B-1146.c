//LLAMA2-13B DATASET v1.0 Category: Socket programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

// Structure to hold server and client settings
typedef struct {
    int port;
    int num_messages;
    int message_size;
} settings_t;

// Function to print usage and exit
void print_usage_and_exit(int status) {
    printf("Usage: %s <port> <num_messages> <message_size>\n",
           __func__);
    printf("Example: %s 8080 10 1024\n", __func__);
    exit(status);
}

// Function to create a socket
int create_socket(int domain, int type, int protocol) {
    int sock;
    sock = socket(domain, type, protocol);
    if (sock < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }
    return sock;
}

// Function to bind a socket to a port
int bind_socket(int sock, int port) {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind() failed");
        exit(EXIT_FAILURE);
    }
    return sock;
}

// Function to listen for incoming connections
int listen_socket(int sock) {
    if (listen(sock, 3) < 0) {
        perror("listen() failed");
        exit(EXIT_FAILURE);
    }
    return sock;
}

// Function to accept an incoming connection
int accept_socket(int sock) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
        perror("accept() failed");
        exit(EXIT_FAILURE);
    }
    return client_sock;
}

// Function to send and receive messages
int send_receive_messages(int sock, char *message, int message_size) {
    int sent = send(sock, message, message_size, 0);
    if (sent < 0) {
        perror("send() failed");
        exit(EXIT_FAILURE);
    }
    char buffer[BUFFER_SIZE];
    int received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (received < 0) {
        perror("recv() failed");
        exit(EXIT_FAILURE);
    }
    printf("Received message: %s\n", buffer);
    return received;
}

int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc != 4) {
        print_usage_and_exit(EXIT_FAILURE);
    }

    // Get the port number, num_messages, and message size from the command line
    int port = atoi(argv[1]);
    int num_messages = atoi(argv[2]);
    int message_size = atoi(argv[3]);

    // Create a socket
    int sock = create_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        perror("create_socket() failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the port
    sock = bind_socket(sock, port);
    if (sock < 0) {
        perror("bind_socket() failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    sock = listen_socket(sock);
    if (sock < 0) {
        perror("listen_socket() failed");
        exit(EXIT_FAILURE);
    }

    // Accept an incoming connection
    sock = accept_socket(sock);
    if (sock < 0) {
        perror("accept_socket() failed");
        exit(EXIT_FAILURE);
    }

    // Send and receive messages
    char message[BUFFER_SIZE];
    for (int i = 0; i < num_messages; i++) {
        snprintf(message, BUFFER_SIZE, "Message %d", i);
        int sent = send_receive_messages(sock, message, message_size);
        if (sent < 0) {
            perror("send_receive_messages() failed");
            exit(EXIT_FAILURE);
        }
    }

    // Close the socket
    close(sock);
    return 0;
}