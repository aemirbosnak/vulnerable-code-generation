//LLAMA2-13B DATASET v1.0 Category: Socket programming ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MESSAGE_BUFFER_SIZE 1024

// Structure to hold client information
struct client {
    int sock;
    char name[50];
};

// Function to create socket
int create_socket(int domain, int type, int protocol) {
    int sock;
    sock = socket(domain, type, protocol);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }
    return sock;
}

// Function to bind socket to port
int bind_socket(int sock, int port) {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("binding failed");
        exit(1);
    }
    return sock;
}

// Function to listen for incoming connections
int listen_socket(int sock) {
    if (listen(sock, MAX_CLIENTS) < 0) {
        perror("listening failed");
        exit(1);
    }
    return sock;
}

// Function to accept incoming connection
int accept_connection(int sock) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
        perror("accept failed");
        exit(1);
    }
    return client_sock;
}

// Function to send and receive messages
int send_receive_messages(int sock, char *message) {
    int sent = send(sock, message, strlen(message), 0);
    if (sent < 0) {
        perror("sending failed");
        exit(1);
    }
    char buffer[MESSAGE_BUFFER_SIZE];
    int received = recv(sock, buffer, MESSAGE_BUFFER_SIZE, 0);
    if (received < 0) {
        perror("receiving failed");
        exit(1);
    }
    printf("Received message: %s\n", buffer);
    return received;
}

// Main function
int main(int argc, char *argv[]) {
    int sock = create_socket(AF_INET, SOCK_STREAM, 0);
    bind_socket(sock, PORT);
    listen_socket(sock);

    // Loop to handle incoming connections
    while (1) {
        int client_sock = accept_connection(sock);
        struct client *client = malloc(sizeof(struct client));
        client->sock = client_sock;
        client->name[0] = '\0';

        // Loop to handle messages from client
        while (1) {
            char message[MESSAGE_BUFFER_SIZE];
            int received = send_receive_messages(client_sock, message);
            if (received == 0) {
                break;
            }
            printf("Client %s says: %s\n", client->name, message);
        }

        // Close client socket and free memory
        close(client_sock);
        free(client);
    }

    return 0;
}