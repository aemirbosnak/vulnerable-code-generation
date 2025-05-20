//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

typedef struct {
    char* username;
    char* password;
    char* server_address;
} POP3Config;

typedef struct {
    int socket_fd;
} POP3Client;

POP3Config* create_pop3_config(char* username, char* password, char* server_address) {
    POP3Config* config = malloc(sizeof(POP3Config));
    config->username = strdup(username);
    config->password = strdup(password);
    config->server_address = strdup(server_address);
    return config;
}

void destroy_pop3_config(POP3Config* config) {
    free(config->username);
    free(config->password);
    free(config->server_address);
    free(config);
}

POP3Client* create_pop3_client() {
    POP3Client* client = malloc(sizeof(POP3Client));
    client->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    return client;
}

void destroy_pop3_client(POP3Client* client) {
    close(client->socket_fd);
    free(client);
}

int pop3_connect(POP3Client* client, char* address, int port) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, address, &server_addr.sin_addr);

    return connect(client->socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
}

int pop3_send_command(POP3Client* client, char* command) {
    int status = send(client->socket_fd, command, strlen(command), 0);
    char response[BUFFER_SIZE];
    int response_len = recv(client->socket_fd, response, BUFFER_SIZE, 0);
    response[response_len] = '\0';
    printf("Server response: %s\n", response);
    return status;
}

int pop3_authenticate(POP3Client* client, POP3Config* config) {
    char command[BUFFER_SIZE];
    sprintf(command, "USER %s\r\n", config->username);
    if (pop3_send_command(client, command) < 0) return -1;

    sprintf(command, "PASS %s\r\n", config->password);
    if (pop3_send_command(client, command) < 0) return -1;

    return 0;
}

int pop3_list_messages(POP3Client* client) {
    if (pop3_send_command(client, "LIST\r\n") < 0) return -1;
    return 0;
}

int pop3_retrieve_message(POP3Client* client, int message_number) {
    char command[BUFFER_SIZE];
    sprintf(command, "RETR %d\r\n", message_number);
    if (pop3_send_command(client, command) < 0) return -1;
    return 0;
}

int main() {
    POP3Config* config = create_pop3_config("username", "password", "mail.example.com");
    POP3Client* client = create_pop3_client();

    if (pop3_connect(client, config->server_address, 110) < 0) {
        printf("Failed to connect to POP3 server\n");
        return -1;
    }

    if (pop3_authenticate(client, config) < 0) {
        printf("Failed to authenticate with POP3 server\n");
        return -1;
    }

    if (pop3_list_messages(client) < 0) {
        printf("Failed to request message list from POP3 server\n");
        return -1;
    }

    if (pop3_retrieve_message(client, 1) < 0) {
        printf("Failed to retrieve message 1 from POP3 server\n");
        return -1;
    }

    destroy_pop3_config(config);
    destroy_pop3_client(client);

    return 0;
}