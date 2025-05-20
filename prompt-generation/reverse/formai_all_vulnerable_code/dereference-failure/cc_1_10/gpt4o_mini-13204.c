//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 110
#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void pop3_send_command(int socket, const char *command) {
    send(socket, command, strlen(command), 0);
    send(socket, "\r\n", 2, 0);
}

char* pop3_receive_response(int socket) {
    char *buffer = malloc(BUFFER_SIZE);

    if (!buffer) {
        handle_error("Failed to allocate memory");
    }

    memset(buffer, 0, BUFFER_SIZE);
    recv(socket, buffer, BUFFER_SIZE - 1, 0);

    return buffer;
}

void pop3_authenticate(int socket, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s", username);
    pop3_send_command(socket, command);
    char *response = pop3_receive_response(socket);
    printf("Server: %s", response);

    snprintf(command, sizeof(command), "PASS %s", password);
    pop3_send_command(socket, command);
    response = pop3_receive_response(socket);
    printf("Server: %s", response);

    free(response);
}

void list_emails(int socket) {
    char *response;
    pop3_send_command(socket, "LIST");
    response = pop3_receive_response(socket);
    printf("Server: %s", response);
    
    while (strncmp(response, ".\r\n", 4) != 0) {
        // Continue processing list response until termination
        printf("%s", response);
        free(response);
        response = pop3_receive_response(socket);
    }

    free(response);
}

void quit_pop3(int socket) {
    char *response;
    pop3_send_command(socket, "QUIT");
    response = pop3_receive_response(socket);
    printf("Server: %s", response);
    free(response);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int socket_fd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) handle_error("Socket creation failed");

    host = gethostbyname(hostname);
    if (!host) handle_error("No such host");

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to server failed");
    }

    char *response = pop3_receive_response(socket_fd);
    printf("Server: %s", response);
    free(response);

    // Authenticate user
    pop3_authenticate(socket_fd, username, password);

    // List emails
    list_emails(socket_fd);

    // Quit
    quit_pop3(socket_fd);

    close(socket_fd);
    return 0;
}