//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 110
#define BUFFER_SIZE 1024

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void send_command(int sock, const char *cmd) {
    if (send(sock, cmd, strlen(cmd), 0) < 0) {
        handle_error("Failed to send command");
    }
}

void receive_response(int sock, char *response) {
    int bytes_received = recv(sock, response, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        handle_error("Failed to receive response");
    }
    response[bytes_received] = '\0'; // Null terminate the string
}

void print_welcome_message() {
    printf("Welcome to the Simple POP3 Client!\n");
    printf("Please enter your POP3 server details.\n");
}

int main() {
    print_welcome_message();

    char server[100], username[100], password[100];
    
    printf("Enter POP3 server address: ");
    fgets(server, sizeof(server), stdin);
    server[strcspn(server, "\n")] = 0; // Remove newline character

    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handle_error("Socket creation failed");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(server);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to POP3 server failed");
    }

    char response[BUFFER_SIZE];
    receive_response(sock, response);
    printf("Server response: %s\n", response);

    // Authenticate using USER and PASS commands
    char cmd[BUFFER_SIZE];

    snprintf(cmd, sizeof(cmd), "USER %s\r\n", username);
    send_command(sock, cmd);
    receive_response(sock, response);
    printf("Server response: %s\n", response);

    snprintf(cmd, sizeof(cmd), "PASS %s\r\n", password);
    send_command(sock, cmd);
    receive_response(sock, response);
    printf("Server response: %s\n", response);

    // List the messages in the mailbox
    send_command(sock, "LIST\r\n");
    receive_response(sock, response);
    printf("Server response: %s\n", response);

    // Quit the session
    send_command(sock, "QUIT\r\n");
    receive_response(sock, response);
    printf("Server response: %s\n", response);

    // Clean up and exit
    close(sock);
    printf("Thank you for using the POP3 client!\n");
    return 0;
}