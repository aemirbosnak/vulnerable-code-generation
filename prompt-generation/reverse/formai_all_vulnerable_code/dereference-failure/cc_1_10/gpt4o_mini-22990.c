//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void connect_to_pop3_server(const char *server_ip, int *sockfd) {
    struct sockaddr_in server_addr;

    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) {
        handle_error("Socket creation failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid address or address not supported");
    }

    if (connect(*sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to POP3 server failed");
    }
}

void send_command(int sockfd, const char *command, char *response) {
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2); // POP3 requires CRLF

    read(sockfd, response, BUFFER_SIZE);
    printf("POP3 Server Response: %s", response);
}

void login_to_pop3(int sockfd, const char *username, const char *password) {
    char response[BUFFER_SIZE];

    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s", username);
    send_command(sockfd, command, response);

    snprintf(command, sizeof(command), "PASS %s", password);
    send_command(sockfd, command, response);
}

void list_emails(int sockfd) {
    char response[BUFFER_SIZE];

    printf("Listing emails:\n");
    send_command(sockfd, "LIST", response);
}

void retrieve_email(int sockfd, int email_number) {
    char response[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "RETR %d", email_number);
    send_command(sockfd, command, response);
}

void disconnect_from_server(int sockfd) {
    char response[BUFFER_SIZE];

    send_command(sockfd, "QUIT", response);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <POP3 server IP> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *pop3_server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd;
    connect_to_pop3_server(pop3_server, &sockfd);

    char response[BUFFER_SIZE];

    // Read server greeting
    read(sockfd, response, BUFFER_SIZE);
    printf("POP3 Server Greeting: %s", response);

    // Login
    login_to_pop3(sockfd, username, password);

    // List emails
    list_emails(sockfd);

    int email_number;
    printf("Enter email number to retrieve (1 to N): ");
    scanf("%d", &email_number);
    retrieve_email(sockfd, email_number);

    // Disconnect from the server
    disconnect_from_server(sockfd);

    return 0;
}