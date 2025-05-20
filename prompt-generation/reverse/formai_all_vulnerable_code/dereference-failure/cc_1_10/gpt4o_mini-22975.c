//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER "pop.your-email-provider.com"  // Change this according to your mail server
#define PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *cmd, char *response) {
    write(sockfd, cmd, strlen(cmd));
    write(sockfd, "\r\n", 2);
    read(sockfd, response, BUFFER_SIZE);
}

void pop3_login(int sockfd, const char *username, const char *password) {
    char response[BUFFER_SIZE];

    send_command(sockfd, "USER ", response);
    strcat(response, username);
    send_command(sockfd, response, response);

    send_command(sockfd, "PASS ", response);
    strcat(response, password);
    send_command(sockfd, response, response);

    if (strstr(response, "+OK") == NULL) {
        fprintf(stderr, "Login failed: %s\n", response);
        exit(1);
    } else {
        printf("Login successful!\n");
    }
}

void list_emails(int sockfd) {
    char response[BUFFER_SIZE];

    send_command(sockfd, "LIST", response);
    printf("%s\n", response);
}

void retrieve_email(int sockfd, int email_number) {
    char command[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    snprintf(command, sizeof(command), "RETR %d", email_number);
    send_command(sockfd, command, response);
    printf("Email #%d:\n%s\n", email_number, response);
}

void delete_email(int sockfd, int email_number) {
    char command[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    snprintf(command, sizeof(command), "DELE %d", email_number);
    send_command(sockfd, command, response);
    printf("Delete response: %s\n", response);
}

void quit_pop3(int sockfd) {
    char response[BUFFER_SIZE];
    send_command(sockfd, "QUIT", response);
    printf("Session closed: %s\n", response);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <username> <password> <email number to retrieve>\n", argv[0]);
        exit(1);
    }

    const char *username = argv[1];
    const char *password = argv[2];
    int email_number = atoi(argv[3]);

    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    char buffer[BUFFER_SIZE];
    read(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    pop3_login(sockfd, username, password);
    list_emails(sockfd);
    retrieve_email(sockfd, email_number);
    delete_email(sockfd, email_number);
    quit_pop3(sockfd);

    close(sockfd);
    return 0;
}