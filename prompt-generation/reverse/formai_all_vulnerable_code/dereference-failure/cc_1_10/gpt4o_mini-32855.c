//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>

#define MAXLINE 1024
#define SERVER_PORT 110

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_server(const char *hostname) {
    struct sockaddr_in server_addr;
    int sockfd;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    memset((char *) &server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy((char *)&server_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    server_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    char buffer[MAXLINE];
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);
    printf("Sent: %s", command);
    
    memset(buffer, 0, MAXLINE);
    read(sockfd, buffer, MAXLINE-1);
    printf("Received: %s\n", buffer);
}

void login(int sockfd, const char *username, const char *password) {
    char command[MAXLINE];
    snprintf(command, sizeof(command), "USER %s", username);
    send_command(sockfd, command);
    snprintf(command, sizeof(command), "PASS %s", password);
    send_command(sockfd, command);
}

void list_emails(int sockfd) {
    send_command(sockfd, "LIST");
}

void retrieve_email(int sockfd, int email_number) {
    char command[MAXLINE];
    snprintf(command, sizeof(command), "RETR %d", email_number);
    send_command(sockfd, command);
}

void quit(int sockfd) {
    send_command(sockfd, "QUIT");
}

void pop3_client(const char *server, const char *username, const char *password) {
    int sockfd = connect_to_server(server);

    // Receive server greeting
    char buffer[MAXLINE];
    memset(buffer, 0, MAXLINE);
    read(sockfd, buffer, MAXLINE-1);
    printf("Connected to server: %s\n", buffer);

    // Log in
    login(sockfd, username, password);

    // List emails
    list_emails(sockfd);

    // Retrieve the first email as an example
    retrieve_email(sockfd, 1);

    // Quit session
    quit(sockfd);

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    pop3_client(server, username, password);

    return EXIT_SUCCESS;
}