//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER 1024

int main(int argc, char* argv[]) {
    int client_socket;
    char* message;
    char buffer[MAX_BUFFER];
    struct sockaddr_in server_address;
    int port = atoi(argv[2]);

    if(argc != 3) {
        fprintf(stderr, "Usage: %s <server-ip-address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        perror("Invalid server IP address");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if(connect(client_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    printf("Connected to SMTP server on port %d\n", port);

    // Receive server greeting
    recv(client_socket, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send HELO command
    message = "HELO example.com\r\n";
    send(client_socket, message, strlen(message), 0);
    printf("%s", message);

    // Receive response to HELO command
    recv(client_socket, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send MAIL FROM command
    message = "MAIL FROM:<user@example.com>\r\n";
    send(client_socket, message, strlen(message), 0);
    printf("%s", message);

    // Receive response to MAIL FROM command
    recv(client_socket, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send RCPT TO command
    message = "RCPT TO:<recipient@example.com>\r\n";
    send(client_socket, message, strlen(message), 0);
    printf("%s", message);

    // Receive response to RCPT TO command
    recv(client_socket, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send DATA command
    message = "DATA\r\n";
    send(client_socket, message, strlen(message), 0);
    printf("%s", message);

    // Receive response to DATA command
    recv(client_socket, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send email message
    message = "Subject: Example email message\r\n\r\nThis is the body of the email message.\r\n.\r\n";
    send(client_socket, message, strlen(message), 0);
    printf("%s", message);

    // Receive response to email message
    recv(client_socket, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send QUIT command
    message = "QUIT\r\n";
    send(client_socket, message, strlen(message), 0);
    printf("%s", message);

    // Receive response to QUIT command
    recv(client_socket, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Close socket
    close(client_socket);

    return EXIT_SUCCESS;
}