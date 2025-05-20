//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define IMAP_PORT 143 // default port for IMAP
#define BUFFER_SIZE 1024 // buffer size for messages
#define MSG_SIZE 1024 // buffer size for message contents

typedef struct {
    int sock_fd; // socket file descriptor
    char buffer[BUFFER_SIZE]; // buffer for incoming messages
    bool verbose; // flag for verbose output
} ImapClient;

void check_error(bool condition, const char* error_msg) {
    if (condition) {
        fprintf(stderr, "%s\n", error_msg);
        exit(EXIT_FAILURE);
    }
}

void send_command(ImapClient* client, const char* command) {
    if (client->verbose) {
        printf("> %s\n", command);
    }
    int sent_bytes = send(client->sock_fd, command, strlen(command), 0);
    check_error(sent_bytes < 0, "Error: failed to send command to server");
}

char* receive_response(ImapClient* client) {
    int bytes_received = recv(client->sock_fd, client->buffer, BUFFER_SIZE, 0);
    check_error(bytes_received < 0, "Error: failed to receive message from server");
    client->buffer[bytes_received] = '\0';
    if (client->verbose) {
        printf("< %s\n", client->buffer);
    }
    return client->buffer;
}

void login(ImapClient* client, const char* username, const char* password) {
    char command[MSG_SIZE];
    sprintf(command, "LOGIN %s %s\r\n", username, password);
    send_command(client, command);
    char* response = receive_response(client);
    check_error(strncmp(response, "OK", 2) != 0, "Error: failed to log in");
}

void select_mailbox(ImapClient* client, const char* mailbox) {
    char command[MSG_SIZE];
    sprintf(command, "SELECT %s\r\n", mailbox);
    send_command(client, command);
    char* response = receive_response(client);
    check_error(strncmp(response, "OK", 2) != 0, "Error: failed to select mailbox");
}

void fetch_email(ImapClient* client, int email_id) {
    char command[MSG_SIZE];
    sprintf(command, "FETCH %d BODY[TEXT]\r\n", email_id);
    send_command(client, command);
    char* response = receive_response(client);
    check_error(strncmp(response, "BAD", 3) == 0, "Error: invalid email ID");
    while (strncmp(response, "BODY[TEXT]", 10) != 0) {
        response = receive_response(client); // skip over header lines
    }
    response += 10; // skip over "BODY[TEXT]"
    char* email_body = strdup(response); // duplicate email body string
    printf("%s\n", email_body); // print email body
    free(email_body); // free memory
}

int main(int argc, char* argv[]) {
    // check command-line arguments
    if (argc < 4) {
        printf("Usage: imap_client <server_address> <username> <password> [mailbox]\n");
        exit(EXIT_SUCCESS);
    }
    // create client struct
    ImapClient client = {0};
    client.verbose = true;

    // create socket
    client.sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    check_error(client.sock_fd < 0, "Error: failed to create socket");

    // connect to server
    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    check_error(inet_pton(AF_INET, argv[1], &server_addr.sin_addr) < 1, "Error: invalid server address");
    check_error(connect(client.sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0, "Error: failed to connect to server");

    // authenticate with server
    login(&client, argv[2], argv[3]);

    // select mailbox
    if (argc > 4) {
        select_mailbox(&client, argv[4]);
    } else {
        select_mailbox(&client, "INBOX");
    }

    // fetch first email in mailbox
    fetch_email(&client, 1);

    // close connection
    close(client.sock_fd);

    return 0;
}