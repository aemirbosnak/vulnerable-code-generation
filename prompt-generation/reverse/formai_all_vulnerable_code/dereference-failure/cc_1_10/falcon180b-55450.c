//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>

#define MAX_LINE_LENGTH 1024
#define IMAP_PORT 143
#define USERNAME "example_user"
#define PASSWORD "example_password"
#define SERVER_ADDRESS "localhost"

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[100] = USERNAME;
    char password[100] = PASSWORD;
    char server_address[100] = SERVER_ADDRESS;
    char response[MAX_LINE_LENGTH];
    char* token;

    printf("Connecting to server...\n");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    inet_pton(AF_INET, server_address, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    printf("Logging in...\n");

    send(sockfd, "LOGIN ", strlen("LOGIN "), 0);
    recv(sockfd, response, MAX_LINE_LENGTH, 0);

    token = strtok(response, " ");
    if (strcmp(token, "OK")!= 0) {
        printf("Error logging in\n");
        exit(1);
    }

    send(sockfd, "SELECT INBOX", strlen("SELECT INBOX"), 0);
    recv(sockfd, response, MAX_LINE_LENGTH, 0);

    token = strtok(response, " ");
    if (strcmp(token, "OK")!= 0) {
        printf("Error selecting mailbox\n");
        exit(1);
    }

    printf("Successfully logged in\n");

    while (1) {
        printf("Enter command: ");
        fgets(response, MAX_LINE_LENGTH, stdin);

        send(sockfd, response, strlen(response), 0);
        recv(sockfd, response, MAX_LINE_LENGTH, 0);

        printf("Server response: %s\n", response);
    }

    close(sockfd);
    return 0;
}