//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_RESPONSE_LENGTH 4096
#define MAX_EMAIL_LENGTH 256
#define AUTHENTICATE "AUTHENTICATE"
#define LOGIN "LOGIN"
#define LOGOUT "LOGOUT"
#define SELECT_COMMAND "SELECT"

typedef struct {
    int socket;
    char *hostname;
    char *username;
    char *password;
} IMAPClient;

IMAPClient *create_client(const char *hostname, const char *username, const char *password);
void connect_to_server(IMAPClient *client);
void authenticate_client(IMAPClient *client);
void fetch_folders(IMAPClient *client);
void close_connection(IMAPClient *client);
void send_command(IMAPClient *client, const char *command, char *response);
void handle_response(char *response);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    IMAPClient *client = create_client(argv[1], argv[2], argv[3]);
    connect_to_server(client);
    authenticate_client(client);
    fetch_folders(client);
    close_connection(client);

    free(client);
    return 0;
}

IMAPClient *create_client(const char *hostname, const char *username, const char *password) {
    IMAPClient *client = malloc(sizeof(IMAPClient));
    client->hostname = strdup(hostname);
    client->username = strdup(username);
    client->password = strdup(password);
    return client;
}

void connect_to_server(IMAPClient *client) {
    struct sockaddr_in server_address;
    struct hostent *host = gethostbyname(client->hostname);
    
    if (!host) {
        perror("Failed to resolve hostname");
        exit(EXIT_FAILURE);
    }

    client->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client->socket < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    memcpy(&server_address.sin_addr.s_addr, host->h_addr, host->h_length);
    server_address.sin_port = htons(993);

    if (connect(client->socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection to server failed");
        close(client->socket);
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s\n", client->hostname);
}

void authenticate_client(IMAPClient *client) {
    char command[MAX_COMMAND_LENGTH];
    char response[MAX_RESPONSE_LENGTH];

    snprintf(command, sizeof(command), "%s %s %s", LOGIN, client->username, client->password);
    send_command(client, command, response);
    handle_response(response);
}

void fetch_folders(IMAPClient *client) {
    char command[MAX_COMMAND_LENGTH];
    char response[MAX_RESPONSE_LENGTH];

    snprintf(command, "%s \"INBOX\"", SELECT_COMMAND);
    send_command(client, command, response);
    handle_response(response);
}

void close_connection(IMAPClient *client) {
    char command[MAX_COMMAND_LENGTH];
    char response[MAX_RESPONSE_LENGTH];

    snprintf(command, "%s", LOGOUT);
    send_command(client, command, response);
    handle_response(response);

    close(client->socket);
    printf("Disconnected from server\n");
}

void send_command(IMAPClient *client, const char *command, char *response) {
    send(client->socket, command, strlen(command), 0);
    send(client->socket, "\r\n", 2, 0);

    recv(client->socket, response, MAX_RESPONSE_LENGTH, 0);
    response[MAX_RESPONSE_LENGTH - 1] = '\0';  // Null-terminate
}

void handle_response(char *response) {
    printf("Server Response: %s\n", response);
}