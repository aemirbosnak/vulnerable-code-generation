//Gemma-7B DATASET v1.0 Category: Email Client ; Style: modular
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
    int socketfd;
    struct sockaddr_in server_addr;
} EmailClient;

EmailClient *createEmailClient(char *hostname, char *username, char *password) {
    EmailClient *client = malloc(sizeof(EmailClient));
    client->hostname = strdup(hostname);
    client->username = strdup(username);
    client->password = strdup(password);

    client->socketfd = socket(AF_INET, SOCK_STREAM, htons(587));
    client->server_addr.sin_family = AF_INET;
    client->server_addr.sin_port = htons(587);
    client->server_addr.sin_addr.s_addr = inet_addr(client->hostname);

    return client;
}

void sendEmail(EmailClient *client, char *to, char *subject, char *message) {
    char buffer[MAX_BUFFER_SIZE];
    char *ptr = buffer;

    sprintf(ptr, "EHLO %s\r\n", client->hostname);
    ptr += strlen("EHLO %s\r\n") + 1;

    sprintf(ptr, "MAIL FROM: %s\r\n", client->username);
    ptr += strlen("MAIL FROM: %s\r\n") + 1;

    sprintf(ptr, "RCPT TO: %s\r\n", to);
    ptr += strlen("RCPT TO: %s\r\n") + 1;

    sprintf(ptr, "SUBJECT: %s\r\n", subject);
    ptr += strlen("SUBJECT: %s\r\n") + 1;

    sprintf(ptr, "DATA\r\n");
    ptr += strlen("DATA\r\n") + 1;

    sprintf(ptr, "%s\r\n", message);
    ptr += strlen(message) + 1;

    sprintf(ptr, ". \r\n");
    ptr += strlen(". \r\n") + 1;

    send(client->socketfd, buffer, ptr - buffer, 0);
}

int main() {
    EmailClient *client = createEmailClient("localhost", "john.doe@gmail.com", "secret");
    sendEmail(client, "jane.doe@gmail.com", "Test Email", "This is a test email.");

    return 0;
}