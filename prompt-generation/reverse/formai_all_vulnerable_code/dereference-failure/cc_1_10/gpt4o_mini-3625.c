//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define POP3_PORT 110
#define BUFFER_SIZE 1024

typedef struct {
    int socket_fd;
    struct sockaddr_in server_addr;
} Pop3Client;

void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

Pop3Client* initialize_pop3_client(const char *server_ip) {
    Pop3Client *client = (Pop3Client *)malloc(sizeof(Pop3Client));
    if (!client) {
        error_exit("Failed to allocate memory for Pop3Client");
    }

    client->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->socket_fd < 0) {
        error_exit("Failed to create socket");
    }

    client->server_addr.sin_family = AF_INET;
    client->server_addr.sin_port = htons(POP3_PORT);
    if (inet_pton(AF_INET, server_ip, &client->server_addr.sin_addr) <= 0) {
        error_exit("Invalid address or Address not supported");
    }

    return client;
}

void connect_to_server(Pop3Client *client) {
    if (connect(client->socket_fd, (struct sockaddr *)&client->server_addr, sizeof(client->server_addr)) < 0) {
        error_exit("Connection failed");
    }

    char buffer[BUFFER_SIZE];
    recv(client->socket_fd, buffer, sizeof(buffer) - 1, 0);
    printf("Server: %s", buffer);
}

void send_command(Pop3Client *client, const char *command) {
    send(client->socket_fd, command, strlen(command), 0);
}

void receive_response(Pop3Client *client) {
    char buffer[BUFFER_SIZE];
    recv(client->socket_fd, buffer, sizeof(buffer) - 1, 0);
    buffer[BUFFER_SIZE - 1] = '\0'; // Null-terminate the string
    printf("Response: %s", buffer);
}

void login(Pop3Client *client, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(client, command);
    receive_response(client);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(client, command);
    receive_response(client);
}

void list_emails(Pop3Client *client) {
    send_command(client, "LIST\r\n");
    receive_response(client);
}

void retrieve_email(Pop3Client *client, int email_number) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %d\r\n", email_number);

    send_command(client, command);
    receive_response(client);
}

void quit(Pop3Client *client) {
    send_command(client, "QUIT\r\n");
    receive_response(client);
}

void clean_up(Pop3Client *client) {
    close(client->socket_fd);
    free(client);
}

int main() {
    const char *server_ip = "127.0.0.1"; // Replace with your POP3 server
    const char *username = "your_username"; // Replace with your username
    const char *password = "your_password"; // Replace with your password

    Pop3Client *client = initialize_pop3_client(server_ip);
    connect_to_server(client);

    login(client, username, password);
    list_emails(client);

    // Retrieve the first email for demonstration
    retrieve_email(client, 1);
    
    quit(client);
    clean_up(client);
    
    return 0;
}