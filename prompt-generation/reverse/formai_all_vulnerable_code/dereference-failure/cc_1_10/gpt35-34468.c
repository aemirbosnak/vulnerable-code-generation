//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 2048

void handle_error(char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server_ip_address> <server_port_number> <username>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_socket < 0) {
        handle_error("Error: Socket creation failed");
    }

    // Connect to the server
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));

    if (connect(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        handle_error("Error: Connection to server failed");
    }

    // Read welcome message from server
    char welcome_message[MAX_BUFFER_SIZE];
    memset(welcome_message, 0, MAX_BUFFER_SIZE);

    if (read(server_socket, welcome_message, MAX_BUFFER_SIZE - 1) < 0) {
        handle_error("Error: Reading message from server failed");
    }

    printf("%s\n", welcome_message);

    // Send username to server
    char username[MAX_BUFFER_SIZE - 10];
    memset(username, 0, MAX_BUFFER_SIZE - 10);
    memcpy(username, argv[3], strlen(argv[3]));
    strcat(username, "\r\n");

    if (send(server_socket, username, strlen(username), 0) < 0) {
        handle_error("Error: Sending message to server failed");
    }

    memset(welcome_message, 0, MAX_BUFFER_SIZE);

    if (read(server_socket, welcome_message, MAX_BUFFER_SIZE - 1) < 0) {
        handle_error("Error: Reading message from server failed");
    }

    printf("%s\n", welcome_message);

    // Send password to server
    char password_prompt[MAX_BUFFER_SIZE];
    memset(password_prompt, 0, MAX_BUFFER_SIZE);

    printf("Password: ");
    fgets(password_prompt, MAX_BUFFER_SIZE, stdin);

    fflush(stdout);

    char password[MAX_BUFFER_SIZE];
    memset(password, 0, MAX_BUFFER_SIZE);
    memcpy(password, password_prompt, strlen(password_prompt) - 1);
    strcat(password, "\r\n");

    if (send(server_socket, password, strlen(password), 0) < 0) {
        handle_error("Error: Sending message to server failed");
    }

    memset(welcome_message, 0, MAX_BUFFER_SIZE);

    if (read(server_socket, welcome_message, MAX_BUFFER_SIZE - 1) < 0) {
        handle_error("Error: Reading message from server failed");
    }

    printf("%s\n", welcome_message);

    // List emails
    char list_command[MAX_BUFFER_SIZE];
    memset(list_command, 0, MAX_BUFFER_SIZE);

    sprintf(list_command, "LIST\r\n");

    if (send(server_socket, list_command, strlen(list_command), 0) < 0) {
        handle_error("Error: Sending message to server failed");
    }

    char email_list[MAX_BUFFER_SIZE];
    memset(email_list, 0, MAX_BUFFER_SIZE);

    if (read(server_socket, email_list, MAX_BUFFER_SIZE - 1) < 0) {
        handle_error("Error: Reading message from server failed");
    }

    printf("%s\n", email_list);

    close(server_socket);
    exit(EXIT_SUCCESS);
}