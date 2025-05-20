//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_SIZE 1024

// Functions declaration
int create_socket(char *server_address, int port);
void send_data(int socket_fd, char *data, char *expected_response_prefix);

int main(int argc, char *argv[]) {
    // Check if enough command line arguments were provided
    if (argc != 4) {
        printf("Usage: %s SERVER_ADDRESS SERVER_PORT EMAIL_ADDRESS\n", argv[0]);
        return 1;
    }

    // Extract command line arguments
    char *server_address = argv[1];
    int server_port = atoi(argv[2]);
    char *email_address = argv[3];

    // Create socket
    int socket_fd = create_socket(server_address, server_port);
    if (socket_fd < 0) {
        printf("Failed to create socket!\n");
        return 1;
    }

    // Send HELO command
    send_data(socket_fd, "HELO local\r\n", "250");

    // Send MAIL FROM command
    char *mail_from = "MAIL FROM:<sender@example.com>\r\n";
    send_data(socket_fd, mail_from, "250");

    // Send RCPT TO command
    char rcpt_to[MAX_SIZE] = {0};
    sprintf(rcpt_to, "RCPT TO:<%s>\r\n", email_address);
    send_data(socket_fd, rcpt_to, "250");

    // Send DATA command
    send_data(socket_fd, "DATA\r\n", "354");

    // Send email body
    char email_data[MAX_SIZE] = {0};
    printf("Enter email body (end input with a single dot):");
    while (fgets(email_data, MAX_SIZE, stdin) != NULL) {
        // Remove newline character from input
        email_data[strcspn(email_data, "\n")] = 0;
        if (strcmp(email_data, ".") == 0) {
            break;
        }
        strcat(email_data, "\r\n"); // Add CRLF to each line
        write(socket_fd, email_data, strlen(email_data));
    }

    // End email with a single dot on a line
    send_data(socket_fd, ".\r\n", "250");

    // Send QUIT command
    send_data(socket_fd, "QUIT\r\n", "221");

    // Close socket
    close(socket_fd);

    return 0;
}

// Create and connect to a socket
int create_socket(char *server_address, int port) {
    struct sockaddr_in server;

    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Check if socket creation succeeded
    if (socket_fd < 0) {
        perror("Failed to create socket");
        return -1;
    }

    // Set server address and port
    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Failed to connect to server");
        return -1;
    }

    return socket_fd;
}

// Send data to server and expect a specific response code prefix
void send_data(int socket_fd, char *data, char *expected_response_prefix) {
    char server_response[MAX_SIZE] = {0};
    write(socket_fd, data, strlen(data));

    // Wait for server response
    while (recv(socket_fd, server_response, MAX_SIZE, 0) > 0) {
        // Check if response prefix matches expected prefix
        if (strncmp(server_response, expected_response_prefix, strlen(expected_response_prefix)) == 0) {
            break;
        }
        printf("%s", server_response);
        memset(server_response, 0, MAX_SIZE);
    }
}