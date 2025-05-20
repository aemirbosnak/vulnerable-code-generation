//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define BUFFER_SIZE 512

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void clear_buffer(char *buffer) {
    memset(buffer, 0, BUFFER_SIZE);
}

void pop3_send(int socket_fd, const char *msg) {
    if (send(socket_fd, msg, strlen(msg), 0) < 0) {
        error("Error sending message to server");
    }
}

void pop3_receive(int socket_fd, char *buffer) {
    ssize_t bytes_received;
    clear_buffer(buffer);
    bytes_received = recv(socket_fd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        error("Error receiving message from server");
    }
    buffer[bytes_received] = '\0'; // Null-terminate the buffer
}

void print_welcome_message() {
    printf("Welcome to the simple POP3 client!\n");
}

int main() {
    int socket_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    print_welcome_message();

    // Create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        error("Error opening socket");
    }

    // Define server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change to your POP3 server

    // Connect to the POP3 server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server");
    }

    pop3_receive(socket_fd, buffer);
    printf("Server: %s\n", buffer);

    // Login process (assuming username and password will be prompted)
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];

    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;  // Remove newline

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;  // Remove newline

    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    pop3_send(socket_fd, command);
    pop3_receive(socket_fd, buffer);
    printf("Server: %s\n", buffer);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    pop3_send(socket_fd, command);
    pop3_receive(socket_fd, buffer);
    printf("Server: %s\n", buffer);

    // Retrieve emails
    pop3_send(socket_fd, "LIST\r\n");
    pop3_receive(socket_fd, buffer);
    printf("Server: %s\n", buffer);

    // Fetching a specific email (assuming we have at least one email)
    snprintf(command, sizeof(command), "RETR 1\r\n");
    pop3_send(socket_fd, command);
    pop3_receive(socket_fd, buffer);
    printf("Server: %s\n", buffer);

    // Close socket and clean up
    pop3_send(socket_fd, "QUIT\r\n");
    pop3_receive(socket_fd, buffer);
    printf("Server: %s\n", buffer);
    
    close(socket_fd);
    printf("Connection closed. Goodbye!\n");

    return 0;
}