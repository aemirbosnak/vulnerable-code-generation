//Gemma-7B DATASET v1.0 Category: Building a POP3 Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

#define POP3_PORT 110

#define MAX_BUFFER_SIZE 1024

typedef struct POP3_Client {
    int sockfd;
    char *hostname;
    char *username;
    char *password;
    char *mailbox;
    char **messages;
    int num_messages;
} POP3_Client;

POP3_Client *pop3_client_init(char *hostname, char *username, char *password, char *mailbox) {
    POP3_Client *client = malloc(sizeof(POP3_Client));
    client->sockfd = -1;
    client->hostname = strdup(hostname);
    client->username = strdup(username);
    client->password = strdup(password);
    client->mailbox = strdup(mailbox);
    client->messages = NULL;
    client->num_messages = 0;

    return client;
}

void pop3_client_connect(POP3_Client *client) {
    struct sockaddr_in server_addr;
    client->sockfd = socket(AF_INET, SOCK_STREAM, htons(POP3_PORT));

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr(client->hostname);

    connect(client->sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
}

void pop3_client_login(POP3_Client *client) {
    char buffer[MAX_BUFFER_SIZE];
    sprintf(buffer, "USER %s\r\n", client->username);
    write(client->sockfd, buffer, strlen(buffer));

    sprintf(buffer, "PASS %s\r\n", client->password);
    write(client->sockfd, buffer, strlen(buffer));

    sprintf(buffer, "STAT\r\n");
    write(client->sockfd, buffer, strlen(buffer));

    read(client->sockfd, buffer, MAX_BUFFER_SIZE);
    client->num_messages = atoi(buffer);

    if (client->num_messages > 0) {
        client->messages = malloc(client->num_messages * sizeof(char *));
        for (int i = 0; i < client->num_messages; i++) {
            client->messages[i] = malloc(MAX_BUFFER_SIZE);
        }
    }
}

void pop3_client_get_messages(POP3_Client *client) {
    char buffer[MAX_BUFFER_SIZE];
    for (int i = 0; i < client->num_messages; i++) {
        sprintf(buffer, "RETR %d\r\n", i + 1);
        write(client->sockfd, buffer, strlen(buffer));

        read(client->sockfd, client->messages[i], MAX_BUFFER_SIZE);
    }
}

void pop3_client_quit(POP3_Client *client) {
    char buffer[MAX_BUFFER_SIZE];
    sprintf(buffer, "QUIT\r\n");
    write(client->sockfd, buffer, strlen(buffer));

    close(client->sockfd);
    free(client->hostname);
    free(client->username);
    free(client->password);
    free(client->mailbox);
    for (int i = 0; i < client->num_messages; i++) {
        free(client->messages[i]);
    }
    free(client->messages);
    free(client);
}

int main() {
    POP3_Client *client = pop3_client_init("pop.gmail.com", "your_username", "your_password", "your_mailbox");
    pop3_client_connect(client);
    pop3_client_login(client);
    pop3_client_get_messages(client);
    pop3_client_quit(client);

    return 0;
}