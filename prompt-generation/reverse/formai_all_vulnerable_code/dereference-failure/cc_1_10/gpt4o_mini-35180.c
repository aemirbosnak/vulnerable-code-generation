//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define SERVER_PORT 993 // Standard IMAPS port
#define BUFFER_SIZE 1024
#define USERNAME "your_email@example.com"
#define PASSWORD "your_password"

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int connect_to_server(const char *server_name) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    host = gethostbyname(server_name);
    if (host == NULL) {
        fprintf(stderr, "Could not resolve host: %s\n", server_name);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("Socket creation failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to server failed");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command, char *response) {
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);
    read(sockfd, response, BUFFER_SIZE - 1);
}

void login(int sockfd) {
    char response[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A001 LOGIN %s %s", USERNAME, PASSWORD);
    send_command(sockfd, command, response);

    printf("Login response: %s\n", response);
}

void fetch_emails(int sockfd) {
    char response[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A002 SELECT INBOX");
    send_command(sockfd, command, response);
    printf("Select response: %s\n", response);

    snprintf(command, sizeof(command), "A003 SEARCH ALL");
    send_command(sockfd, command, response);
    printf("Search response: %s\n", response);

    snprintf(command, sizeof(command), "A004 FETCH 1 BODY[]");
    send_command(sockfd, command, response);
    printf("Fetch response: %s\n", response);
}

void logout(int sockfd) {
    char response[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A005 LOGOUT");
    send_command(sockfd, command, response);
    printf("Logout response: %s\n", response);
}

int main() {
    const char *server_name = "imap.example.com"; // Replace with your IMAP server
    int sockfd = connect_to_server(server_name);

    char response[BUFFER_SIZE];
    
    // Read initial server greeting
    read(sockfd, response, BUFFER_SIZE - 1);
    printf("Server greeting: %s\n", response);

    // Perform login
    login(sockfd);

    // Fetch emails
    fetch_emails(sockfd);

    // Logout
    logout(sockfd);

    close(sockfd);
    return 0;
}