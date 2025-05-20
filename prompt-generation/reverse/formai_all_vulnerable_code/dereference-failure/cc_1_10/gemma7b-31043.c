//Gemma-7B DATASET v1.0 Category: Email Client ; Style: genius
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

typedef struct EmailClient {
    char *hostname;
    char *username;
    char *password;
    int sockfd;
    struct sockaddr_in server_addr;
    char *inbox_dir;
    char *sent_dir;
    char *draft_dir;
    char *cur_folder;
} EmailClient;

EmailClient *email_client_init(char *hostname, char *username, char *password) {
    EmailClient *client = malloc(sizeof(EmailClient));

    client->hostname = strdup(hostname);
    client->username = strdup(username);
    client->password = strdup(password);

    client->sockfd = socket(AF_INET, SOCK_STREAM, htons(25));

    client->server_addr.sin_family = AF_INET;
    client->server_addr.sin_port = htons(143);
    client->server_addr.sin_addr.s_addr = inet_addr(client->hostname);

    client->inbox_dir = strdup("/home/user/inbox");
    client->sent_dir = strdup("/home/user/sent");
    client->draft_dir = strdup("/home/user/draft");
    client->cur_folder = strdup("/home/user/inbox");

    return client;
}

void email_client_send(EmailClient *client, char *to, char *subject, char *message) {
    char buffer[MAX_BUFFER_SIZE];
    char *msg_body = malloc(MAX_BUFFER_SIZE);

    sprintf(buffer, "EHLO %s\r\n", client->hostname);
    send(client->sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "AUTH PLAIN %s %s\r\n", client->username, client->password);
    send(client->sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "MAIL FROM %s\r\n", client->username);
    send(client->sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "RCPT TO %s\r\n", to);
    send(client->sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "Subject: %s\r\n", subject);
    send(client->sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "BODY %s\r\n", message);
    send(client->sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "QUIT\r\n");
    send(client->sockfd, buffer, strlen(buffer), 0);

    free(msg_body);
}

int main() {
    EmailClient *client = email_client_init("localhost", "user@localhost", "password");

    email_client_send(client, "recipient@localhost", "Test Subject", "This is a test message");

    return 0;
}