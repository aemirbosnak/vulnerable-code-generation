//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 993
#define BUFFER_SIZE 1024
#define IMAP_COMMAND_SIZE 512

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void send_imap_command(int sockfd, const char *cmd) {
    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        die("Error sending command to server");
    }
}

void receive_response(int sockfd, char *response) {
    memset(response, 0, BUFFER_SIZE);
    int bytes_received = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        die("Error receiving response from server");
    }
    response[bytes_received] = '\0'; // Null-terminate the response
}

void connect_to_imap_server(const char *hostname, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("Unable to create socket");
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &server_address.sin_addr) <= 0) {
        die("Invalid address or address not supported");
    }

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        die("Connection failed");
    }

    printf("Connected to IMAP server at %s\n", hostname);
    close(sockfd);
}

void imap_login(int sockfd, const char *username, const char *password) {
    char command[IMAP_COMMAND_SIZE];
    char response[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A001 LOGIN \"%s\" \"%s\"\r\n", username, password);
    send_imap_command(sockfd, command);
    receive_response(sockfd, response);
    printf("LOGIN Response: %s\n", response);
}

int main() {
    printf("======================================\n");
    printf("     Retro IMAP Client v1.0\n");
    printf("======================================\n");

    const char *hostname = "imap.example.com"; // Placeholder
    const char *username = "user@example.com"; // Placeholder
    const char *password = "secret"; // Placeholder

    // Connect to the IMAP server
    connect_to_imap_server(hostname, SERVER_PORT);

    // IMAP authentication
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        die("Socket creation failed");
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, hostname, &server_address.sin_addr) <= 0) {
        die("Invalid address or address not supported");
    }

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        die("Connection failed");
    }

    imap_login(sockfd, username, password);

    // Sending Command Example: LIST Mailboxes
    char list_command[IMAP_COMMAND_SIZE];
    snprintf(list_command, sizeof(list_command), "A002 LIST \"\" \"*\"\r\n");
    send_imap_command(sockfd, list_command);
    
    char list_response[BUFFER_SIZE];
    receive_response(sockfd, list_response);
    printf("LIST Response: %s\n", list_response);

    // Close the socket
    close(sockfd);
    printf("Disconnected from IMAP server.\n");

    return 0;
}