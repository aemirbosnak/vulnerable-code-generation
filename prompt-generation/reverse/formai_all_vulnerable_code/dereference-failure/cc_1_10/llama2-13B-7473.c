//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 25
#define MAX_LENGTH 255

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

struct email *parse_email(char *line) {
    struct email *email = malloc(sizeof(struct email));
    char *token;

    // Parse from address
    token = strtok(line, " ");
    email->from = malloc(strlen(token) + 1);
    strcpy(email->from, token);

    // Parse to address
    token = strtok(NULL, " ");
    email->to = malloc(strlen(token) + 1);
    strcpy(email->to, token);

    // Parse subject
    token = strtok(NULL, "\n");
    email->subject = malloc(strlen(token) + 1);
    strcpy(email->subject, token);

    // Parse message
    token = strtok(NULL, "\n");
    email->message = malloc(strlen(token) + 1);
    strcpy(email->message, token);

    return email;
}

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct email *email;

    // Connect to server
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = inet_addr("127.0.0.1")
    };
    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Loop forever
    while (1) {
        // Receive email
        char buffer[MAX_LENGTH];
        recv(sock, buffer, MAX_LENGTH, 0);
        email = parse_email(buffer);

        // Print email
        printf("From: %s\nTo: %s\nSubject: %s\nMessage: %s\n",
            email->from, email->to, email->subject, email->message);

        // Free memory
        free(email->from);
        free(email->to);
        free(email->subject);
        free(email->message);
        free(email);
    }

    return 0;
}