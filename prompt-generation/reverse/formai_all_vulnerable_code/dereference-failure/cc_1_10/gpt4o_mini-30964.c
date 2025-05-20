//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

typedef struct {
    int socket;
    char *server;
    char *username;
    char *password;
} POP3Client;

// Function prototypes
POP3Client* pop3_connect(const char *server);
void pop3_authenticate(POP3Client *client, const char *username, const char *password);
void pop3_list(POP3Client *client);
void pop3_retrieve(POP3Client *client, int msg_num);
void pop3_quit(POP3Client *client);
void pop3_send_command(POP3Client *client, const char *command);
char *pop3_read_response(POP3Client *client);
void pop3_free(POP3Client *client);

int main() {
    char *server = "pop.example.com"; // Replace with your POP3 server
    char *username = "user@example.com"; // Replace with your username
    char *password = "yourpassword"; // Replace with your password

    POP3Client *client = pop3_connect(server);
    pop3_authenticate(client, username, password);
    pop3_list(client);
    pop3_retrieve(client, 1); // Retrieve the first email
    pop3_quit(client);
    pop3_free(client);

    return 0;
}

POP3Client* pop3_connect(const char *server) {
    POP3Client *client = malloc(sizeof(POP3Client));
    struct sockaddr_in server_addr;

    client->server = strdup(server);
    client->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client->socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    if (connect(client->socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(client->socket);
        exit(EXIT_FAILURE);
    }

    printf("Connected to POP3 server: %s\n", server);
    pop3_read_response(client);
    return client;
}

void pop3_authenticate(POP3Client *client, const char *username, const char *password) {
    client->username = strdup(username);
    client->password = strdup(password);

    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", client->username);
    pop3_send_command(client, command);
    pop3_read_response(client);

    snprintf(command, sizeof(command), "PASS %s\r\n", client->password);
    pop3_send_command(client, command);
    pop3_read_response(client);
}

void pop3_list(POP3Client *client) {
    pop3_send_command(client, "LIST\r\n");
    char *response = pop3_read_response(client);

    printf("List of messages:\n%s\n", response);
    free(response);
}

void pop3_retrieve(POP3Client *client, int msg_num) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %d\r\n", msg_num);
    pop3_send_command(client, command);
    
    char *response = pop3_read_response(client);
    printf("Retrieved message %d:\n%s\n", msg_num, response);
    free(response);
}

void pop3_quit(POP3Client *client) {
    pop3_send_command(client, "QUIT\r\n");
    pop3_read_response(client);
    close(client->socket);
    printf("Disconnected from server\n");
}

void pop3_send_command(POP3Client *client, const char *command) {
    send(client->socket, command, strlen(command), 0);
}

char *pop3_read_response(POP3Client *client) {
    char *buffer = malloc(BUFFER_SIZE);
    int bytes_received = recv(client->socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("Receive failed");
        free(buffer);
        exit(EXIT_FAILURE);
    }

    buffer[bytes_received] = '\0'; // NULL-terminate the received data
    printf("Server response: %s", buffer);
    return buffer;
}

void pop3_free(POP3Client *client) {
    free(client->server);
    free(client->username);
    free(client->password);
    free(client);
}