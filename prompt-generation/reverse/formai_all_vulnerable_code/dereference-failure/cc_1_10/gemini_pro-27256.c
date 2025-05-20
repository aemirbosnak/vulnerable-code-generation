//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_CLIENTS 10
#define MAX_DATA_SIZE 1024

typedef struct {
    int sockfd;
    char username[100];
    char password[100];
    char diary[MAX_DATA_SIZE];
} Client;

// Create a new client
Client* create_client(int sockfd) {
    Client* client = (Client*)malloc(sizeof(Client));
    client->sockfd = sockfd;
    client->username[0] = '\0';
    client->password[0] = '\0';
    client->diary[0] = '\0';
    return client;
}

// Free a client
void free_client(Client* client) {
    free(client);
}

// Send a message to a client
void send_message(Client* client, char* message) {
    if (send(client->sockfd, message, strlen(message), 0) < 0) {
        perror("send");
        exit(1);
    }
}

// Receive a message from a client
char* receive_message(Client* client) {
    char* message = (char*)malloc(MAX_DATA_SIZE);
    if (recv(client->sockfd, message, MAX_DATA_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }
    return message;
}

// Handle a new client connection
void handle_client(Client* client) {
    // Receive the username and password from the client
    char* username = receive_message(client);
    char* password = receive_message(client);

    // Check if the username and password are correct
    if (strcmp(username, "admin") == 0 && strcmp(password, "secret") == 0) {
        // Send a welcome message to the client
        send_message(client, "Welcome to your digital diary!");

        // Receive the diary from the client
        char* diary = receive_message(client);

        // Save the diary to the server
        // ...

        // Send a confirmation message to the client
        send_message(client, "Your diary has been saved.");
    } else {
        // Send an error message to the client
        send_message(client, "Invalid username or password.");
    }

    // Close the client connection
    close(client->sockfd);
    free_client(client);
}

int main(int argc, char** argv) {
    // Create a server socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Bind the server socket to an address and port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(12345);
    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming client connections
    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(1);
    }

    // Accept incoming client connections and handle them in a separate thread
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_sockfd < 0) {
            perror("accept");
            continue;
        }
        Client* client = create_client(client_sockfd);
        pthread_t thread;
        pthread_create(&thread, NULL, (void* (*)(void*))handle_client, (void*)client);
    }

    // Close the server socket
    close(sockfd);

    return 0;
}