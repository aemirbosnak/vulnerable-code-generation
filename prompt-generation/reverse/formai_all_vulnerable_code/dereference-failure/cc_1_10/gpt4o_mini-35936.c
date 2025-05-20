//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int establish_connection(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    struct hostent *server;

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        close(sockfd);
        error("ERROR connecting");
    }

    return sockfd;
}

void send_command(int sockfd, const char *cmd) {
    write(sockfd, cmd, strlen(cmd));
    printf("C: %s", cmd);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    int n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) error("ERROR reading from socket");
    printf("S: %s", buffer);
}

void login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    snprintf(command, BUFFER_SIZE, "A01 LOGIN %s %s\r\n", username, password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void list_mailboxes(int sockfd) {
    send_command(sockfd, "A02 LIST \"\" *\r\n");
    receive_response(sockfd);
}

void fetch_email(int sockfd, const char *mailbox) {
    char command[BUFFER_SIZE];
    snprintf(command, BUFFER_SIZE, "A03 SELECT %s\r\n", mailbox);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void logout(int sockfd) {
    send_command(sockfd, "A04 LOGOUT\r\n");
    receive_response(sockfd);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    int sockfd = establish_connection(hostname, 143); // IMAP uses port 143 by default

    char buffer[BUFFER_SIZE];
    
    // Read server greeting
    receive_response(sockfd);

    // Log in to the IMAP server
    login(sockfd, username, password);

    // List mailboxes
    list_mailboxes(sockfd);

    // Select the mailbox (INBOX)
    fetch_email(sockfd, "INBOX");

    // Logout from the server
    logout(sockfd);

    return 0;
}