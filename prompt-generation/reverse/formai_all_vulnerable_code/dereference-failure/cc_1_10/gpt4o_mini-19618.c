//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define POP3_PORT 110
#define BUFFER_SIZE 1024

typedef struct {
    char *server;
    char *username;
    char *password;
} POP3Client;

void print_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

POP3Client* create_pop3_client(const char *server, const char *username, const char *password) {
    POP3Client *client = malloc(sizeof(POP3Client));
    if (!client) {
        print_error("Failed to allocate memory for POP3 Client");
    }
    client->server = strdup(server);
    client->username = strdup(username);
    client->password = strdup(password);
    return client;
}

void free_pop3_client(POP3Client *client) {
    if (client) {
        free(client->server);
        free(client->username);
        free(client->password);
        free(client);
    }
}

int connect_to_server(POP3Client *client) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        print_error("Socket creation failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr(client->server);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(sockfd);
        print_error("Connection to POP3 server failed");
    }

    return sockfd;
}

void send_command(int sockfd, const char *cmd, char *response) {
    write(sockfd, cmd, strlen(cmd));
    write(sockfd, "\r\n", 2);
    read(sockfd, response, BUFFER_SIZE);
}

void login(int sockfd, POP3Client *client) {
    char response[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s", client->username);
    send_command(sockfd, command, response);
    printf("Response: %s", response);

    snprintf(command, sizeof(command), "PASS %s", client->password);
    send_command(sockfd, command, response);
    printf("Response: %s", response);
}

void list_messages(int sockfd) {
    char response[BUFFER_SIZE];
    send_command(sockfd, "LIST", response);
    printf("Messages List:\n%s", response);
}

void retrieve_message(int sockfd, int msg_number) {
    char response[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "RETR %d", msg_number);
    send_command(sockfd, command, response);
    printf("Message Body:\n%s", response);
}

void quit(int sockfd) {
    char response[BUFFER_SIZE];
    send_command(sockfd, "QUIT", response);
    printf("Server Response: %s", response);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <pop3_server> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    POP3Client *client = create_pop3_client(argv[1], argv[2], argv[3]);
    
    int sockfd = connect_to_server(client);
    
    char response[BUFFER_SIZE];
    read(sockfd, response, BUFFER_SIZE);
    printf("Server Greeting: %s", response);

    login(sockfd, client);
    list_messages(sockfd);

    int message_number;
    printf("Enter message number to retrieve: ");
    scanf("%d", &message_number);
    retrieve_message(sockfd, message_number);

    quit(sockfd);
    close(sockfd);
    free_pop3_client(client);

    return 0;
}