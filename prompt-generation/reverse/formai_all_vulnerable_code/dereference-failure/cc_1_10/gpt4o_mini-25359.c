//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define BUFFER_SIZE 512
#define MAX_EMAILS 100

typedef struct {
    char *host;
    char *user;
    char *pass;
    int socket;
} POP3Client;

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void connectToServer(POP3Client *client) {
    struct sockaddr_in server_addr;

    client->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client->socket < 0) {
        error("Error opening socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, client->host, &server_addr.sin_addr);

    if (connect(client->socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server");
    }

    char buffer[BUFFER_SIZE];
    read(client->socket, buffer, BUFFER_SIZE);
    printf("%s", buffer);
}

void sendCommand(POP3Client *client, const char *command) {
    char buffer[BUFFER_SIZE];

    write(client->socket, command, strlen(command));
    write(client->socket, "\r\n", 2);

    read(client->socket, buffer, BUFFER_SIZE);
    printf("Server Response: %s\n", buffer);
}

void authenticate(POP3Client *client) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s", client->user);
    sendCommand(client, command);

    snprintf(command, sizeof(command), "PASS %s", client->pass);
    sendCommand(client, command);
}

void listEmails(POP3Client *client) {
    sendCommand(client, "LIST");
}

void retrieveEmail(POP3Client *client, int emailNumber) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %d", emailNumber);
    sendCommand(client, command);
}

void disconnect(POP3Client *client) {
    sendCommand(client, "QUIT");
    close(client->socket);
}

void initClient(POP3Client *client, const char *host, const char *user, const char *pass) {
    client->host = strdup(host);
    client->user = strdup(user);
    client->pass = strdup(pass);
}

void freeClient(POP3Client *client) {
    free(client->host);
    free(client->user);
    free(client->pass);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <username> <password>\n", argv[0]);
        exit(1);
    }

    POP3Client client;
    initClient(&client, argv[1], argv[2], argv[3]);

    connectToServer(&client);
    authenticate(&client);
    listEmails(&client);

    int emailNumber;
    printf("Enter email number to retrieve (1 to %d): ", MAX_EMAILS);
    scanf("%d", &emailNumber);

    if (emailNumber >= 1 && emailNumber <= MAX_EMAILS) {
        retrieveEmail(&client, emailNumber);
    } else {
        fprintf(stderr, "Invalid email number!\n");
    }

    disconnect(&client);
    freeClient(&client);

    return 0;
}