//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 110
#define BUFFER_SIZE 1024
#define SERVER "pop.example.com"

void pop3_connect(int *sockfd, const char *server) {
    struct sockaddr_in server_addr;
    *sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (*sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    if (connect(*sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }
}

void pop3_send_command(int sockfd, const char *command, char *response) {
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);
    read(sockfd, response, BUFFER_SIZE);
}

void authenticate(int sockfd, const char *username, const char *password) {
    char response[BUFFER_SIZE];

    pop3_send_command(sockfd, "USER test_user", response);
    printf("Response: %s", response);
    pop3_send_command(sockfd, "PASS test_password", response);
    printf("Response: %s", response);
}

void list_messages(int sockfd) {
    char response[BUFFER_SIZE];

    pop3_send_command(sockfd, "LIST", response);
    printf("Response: %s", response);
}

void retrieve_message(int sockfd, int msg_number) {
    char command[50];
    char response[BUFFER_SIZE];

    snprintf(command, sizeof(command), "RETR %d", msg_number);
    pop3_send_command(sockfd, command, response);
    printf("Message #%d:\n%s", msg_number, response);
}

void logout(int sockfd) {
    char response[BUFFER_SIZE];

    pop3_send_command(sockfd, "QUIT", response);
    printf("Response: %s\n", response);
}

int main() {
    int sockfd;
    char response[BUFFER_SIZE];

    printf("=== Welcome to the Cosmic POP3 Client ===\n");
    pop3_connect(&sockfd, SERVER);

    read(sockfd, response, BUFFER_SIZE);
    printf("Server: %s", response);

    authenticate(sockfd, "test_user", "test_password");
    list_messages(sockfd);
    retrieve_message(sockfd, 1);  // Retrieve the first message
    logout(sockfd);

    close(sockfd);
    return 0;
}