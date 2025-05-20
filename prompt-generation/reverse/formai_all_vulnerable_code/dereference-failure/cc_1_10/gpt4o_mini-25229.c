//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int create_socket(const char *server_ip) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);

    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        error("Invalid address or address not supported");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }
    
    return sockfd;
}

void send_command(int sockfd, const char *cmd, char *response) {
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, "\r\n", 2, 0);
    
    int n = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        error("Error reading response");
    }
    
    response[n] = '\0';
}

void login(int sockfd, const char *username, const char *password) {
    char response[BUFFER_SIZE];
    char command[256];

    snprintf(command, sizeof(command), "A001 LOGIN %s %s", username, password);
    send_command(sockfd, command, response);
    printf("Login response: %s\n", response);
}

void fetch_emails(int sockfd) {
    char response[BUFFER_SIZE];
    const char *fetch_cmd = "A002 SELECT INBOX";
    const char *fetch_cmd_2 = "A003 FETCH 1:* (ENVELOPE)";
    
    send_command(sockfd, fetch_cmd, response);
    printf("Select response: %s\n", response);

    send_command(sockfd, fetch_cmd_2, response);
    printf("Fetch response: %s\n", response);
}

void close_connection(int sockfd) {
    char response[BUFFER_SIZE];
    const char *logout_cmd = "A004 LOGOUT";

    send_command(sockfd, logout_cmd, response);
    printf("Logout response: %s\n", response);
}

int main() {
    const char *server_ip = "127.0.0.1"; // Replace with your IMAP server IP
    const char *username = "example_user"; // Replace with your username
    const char *password = "example_pass"; // Replace with your password

    int sockfd = create_socket(server_ip);
    login(sockfd, username, password);
    fetch_emails(sockfd);
    close_connection(sockfd);
    
    close(sockfd);
    return 0;
}