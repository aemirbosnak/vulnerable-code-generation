//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>

#define MAX_LINE 1024

typedef struct email_info {
    char *sender;
    char *recipient;
    char *subject;
    char *body;
} email_info;

typedef struct client_info {
    int sockfd;
    pthread_t thread_id;
    email_info email;
} client_info;

void *handle_client(void *arg);
void send_email(client_info *client);
void error(const char *msg);

int main(int argc, char* argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        error("Usage: email-client <hostname> <port>");
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        error("ERROR, no such host");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    client_info client;
    client.sockfd = sockfd;

    pthread_create(&client.thread_id, NULL, handle_client, (void *) &client);

    pthread_join(client.thread_id, NULL);

    close(sockfd);
    return 0;
}

void *handle_client(void *arg) {
    client_info *client = (client_info *) arg;

    email_info email;

    printf("Enter sender email address: ");
    email.sender = (char *) malloc(MAX_LINE);
    fgets(email.sender, MAX_LINE, stdin);
    email.sender[strlen(email.sender) - 1] = '\0'; // remove newline

    printf("Enter recipient email address: ");
    email.recipient = (char *) malloc(MAX_LINE);
    fgets(email.recipient, MAX_LINE, stdin);
    email.recipient[strlen(email.recipient) - 1] = '\0'; // remove newline

    printf("Enter email subject: ");
    email.subject = (char *) malloc(MAX_LINE);
    fgets(email.subject, MAX_LINE, stdin);
    email.subject[strlen(email.subject) - 1] = '\0'; // remove newline

    printf("Enter email body: ");
    email.body = (char *) malloc(MAX_LINE);
    fgets(email.body, MAX_LINE, stdin);
    email.body[strlen(email.body) - 1] = '\0'; // remove newline

    client->email = email;
    send_email(client);

    return NULL;
}

void send_email(client_info *client) {
    char buffer[MAX_LINE];

    snprintf(buffer, MAX_LINE, "FROM: %s\n", client->email.sender);
    write(client->sockfd, buffer, strlen(buffer));

    snprintf(buffer, MAX_LINE, "TO: %s\n", client->email.recipient);
    write(client->sockfd, buffer, strlen(buffer));

    snprintf(buffer, MAX_LINE, "SUBJECT: %s\n", client->email.subject);
    write(client->sockfd, buffer, strlen(buffer));

    snprintf(buffer, MAX_LINE, "BODY: %s\n", client->email.body);
    write(client->sockfd, buffer, strlen(buffer));

    snprintf(buffer, MAX_LINE, ".\n");
    write(client->sockfd, buffer, strlen(buffer));

    char response[MAX_LINE];
    int n = read(client->sockfd, response, MAX_LINE - 1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    response[n] = '\0';

    if (strcmp(response, "OK") == 0) {
        printf("Email sent successfully.\n");
    } else {
        printf("Error sending email: %s\n", response);
    }
}

void error(const char *msg) {
    perror(msg);
    exit(1);
}