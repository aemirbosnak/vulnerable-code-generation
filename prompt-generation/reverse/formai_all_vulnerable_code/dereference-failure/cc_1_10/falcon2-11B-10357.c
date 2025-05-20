//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: immersive
// C Client Server Application Example
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

// Global Variables
int socket_fd, server_addrlen;
char buffer[1024];

// Function Prototypes
void* connect_to_server(char* server_ip, int server_port);
void send_message_to_server(char* message);
void receive_message_from_server(char* message);

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments are provided
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        return 1;
    }

    // Convert the IP and port to integers
    int server_ip_addr = inet_addr(argv[1]);
    int server_port = atoi(argv[2]);

    // Create a socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Connect to the server
    void* server_addr = connect_to_server(argv[1], server_port);
    if (server_addr == NULL) {
        perror("Connection to server failed");
        return 1;
    }

    // Send message to the server
    char message[100];
    printf("Enter message to send: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';
    send_message_to_server(message);

    // Receive message from the server
    receive_message_from_server(buffer);
    printf("Received message from server: %s\n", buffer);

    // Close the socket
    close(socket_fd);

    return 0;
}

// Connect to the server
void* connect_to_server(char* server_ip, int server_port) {
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    server_addrlen = sizeof(server_addr);

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    if (connect(socket_fd, (struct sockaddr*)&server_addr, server_addrlen) < 0) {
        perror("Connection to server failed");
        return NULL;
    }

    return (void*)&server_addr;
}

// Send message to the server
void send_message_to_server(char* message) {
    int bytes_sent = send(socket_fd, message, strlen(message), 0);
    if (bytes_sent < 0) {
        perror("Sending message failed");
    }
}

// Receive message from the server
void receive_message_from_server(char* message) {
    int bytes_received = recv(socket_fd, message, sizeof(message), 0);
    if (bytes_received < 0) {
        perror("Receiving message failed");
    } else {
        message[bytes_received] = '\0';
    }
}