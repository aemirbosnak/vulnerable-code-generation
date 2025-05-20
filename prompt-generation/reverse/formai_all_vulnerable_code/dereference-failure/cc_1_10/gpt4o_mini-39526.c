//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sock, const char *command) {
    send(sock, command, strlen(command), 0);
}

void receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    int bytesRead;

    while ((bytesRead = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytesRead] = '\0';
        printf("%s", buffer);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ftp_server_ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ftp_server_ip = argv[1];
    int ftp_port = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handle_error("Socket creation failed");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(ftp_port);
    inet_pton(AF_INET, ftp_server_ip, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to FTP server failed");
    }

    receive_response(sock); // Initial server response

    // Login credentials
    char username[100], password[100];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Sending USER command
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sock, command);
    receive_response(sock); // Server response to USER command

    // Sending PASS command
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sock, command);
    receive_response(sock); // Server response to PASS command

    // Loop for user commands
    while (1) {
        printf("\nFTP> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline

        // If user wants to quit, break the loop
        if (strcmp(command, "quit") == 0) {
            send_command(sock, "QUIT\r\n");
            receive_response(sock); // Server response to QUIT command
            break;
        }

        // Send the command to the server
        send_command(sock, command);
        receive_response(sock); // Server response to user command
    }

    close(sock);
    return 0;
}