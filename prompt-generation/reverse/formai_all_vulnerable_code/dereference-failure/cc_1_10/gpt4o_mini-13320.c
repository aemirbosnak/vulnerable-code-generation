//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 110
#define BUFFER_SIZE 1024

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int connect_to_server(const char *server_ip) {
    int sock;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("Socket creation failed");
    }

    // Set up server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid address/ Address not supported");
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to the server failed");
    }

    return sock;
}

void send_command(int sock, const char *command) {
    send(sock, command, strlen(command), 0);
}

void receive_response(int sock, char *buffer) {
    int bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        handle_error("Failed to receive response");
    }
    buffer[bytes_received] = '\0'; // Null-terminate the string
}

void login(int sock, const char *username, const char *password) {
    char buffer[BUFFER_SIZE];

    // Send USER command
    sprintf(buffer, "USER %s\r\n", username);
    send_command(sock, buffer);
    receive_response(sock, buffer);
    printf("Response: %s", buffer);

    // Send PASS command
    sprintf(buffer, "PASS %s\r\n", password);
    send_command(sock, buffer);
    receive_response(sock, buffer);
    printf("Response: %s", buffer);
}

void list_messages(int sock) {
    char buffer[BUFFER_SIZE];

    // Send LIST command
    send_command(sock, "LIST\r\n");
    receive_response(sock, buffer);
    printf("Response: %s", buffer);

    // Expecting "+OK" for a successful LIST response 
    if (strncmp(buffer, "+OK", 3) == 0) {
        // We can further parse the buffer to list individual messages
        printf("List of messages:\n%s", buffer);
    }
}

void quit_session(int sock) {
    char buffer[BUFFER_SIZE];

    // Send QUIT command
    send_command(sock, "QUIT\r\n");
    receive_response(sock, buffer);
    printf("Response: %s", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_ip> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    const char *server_ip = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sock = connect_to_server(server_ip);
    
    char buffer[BUFFER_SIZE];
    receive_response(sock, buffer);
    printf("Server Response: %s", buffer); // Initial server greeting

    login(sock, username, password); // Log in with credentials
    list_messages(sock);              // List available messages
    quit_session(sock);               // Cleanly quit the session

    close(sock);
    return 0;
}