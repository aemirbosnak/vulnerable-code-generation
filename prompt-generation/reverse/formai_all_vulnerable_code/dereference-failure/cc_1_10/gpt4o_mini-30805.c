//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
}

void receive_response(int sockfd, char *response) {
    int n = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    if (n < 0) error("ERROR reading from socket");
    response[n] = '\0';
}

void login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);
    char response[BUFFER_SIZE];
    receive_response(sockfd, response);
    printf("%s", response);
    
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);
    receive_response(sockfd, response);
    printf("%s", response);
}

void list_emails(int sockfd) {
    char command[] = "LIST\r\n";
    send_command(sockfd, command);
    char response[BUFFER_SIZE];
    receive_response(sockfd, response);
    printf("%s", response);
}

void fetch_email(int sockfd, int email_number) {
    char command[BUFFER_SIZE];
    
    snprintf(command, sizeof(command), "RETR %d\r\n", email_number);
    send_command(sockfd, command);
    char response[BUFFER_SIZE];
    receive_response(sockfd, response);
    printf("%s", response);
}

void disconnect(int sockfd) {
    char command[] = "QUIT\r\n";
    send_command(sockfd, command);
    char response[BUFFER_SIZE];
    receive_response(sockfd, response);
    printf("%s", response);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <username> <password>\n", argv[0]);
        exit(1);
    }
    
    const char *host = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    if (inet_pton(AF_INET, host, &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address or Address not supported\n");
        exit(1);
    }
    
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Connection Failed");
    }

    char response[BUFFER_SIZE];
    receive_response(sockfd, response);
    printf("%s", response); // Server Greeting

    login(sockfd, username, password);
    list_emails(sockfd);
    
    // Fetch the first email for demonstration
    fetch_email(sockfd, 1);
    
    disconnect(sockfd);

    return 0;
}