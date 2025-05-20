//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 110 // Default POP3 port
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void pop3_connect(int *sockfd, const char *hostname) {
    struct hostent *server;
    struct sockaddr_in serv_addr;

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) {
        error("ERROR opening socket");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(*sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }
}

void pop3_send_command(int sockfd, const char *command) {
    if (write(sockfd, command, strlen(command)) < 0) {
        error("ERROR writing to socket");
    }
}

void pop3_read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    if (read(sockfd, buffer, BUFFER_SIZE - 1) < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);
}

void pop3_login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    
    snprintf(command, BUFFER_SIZE, "USER %s\r\n", username);
    pop3_send_command(sockfd, command);
    pop3_read_response(sockfd);

    snprintf(command, BUFFER_SIZE, "PASS %s\r\n", password);
    pop3_send_command(sockfd, command);
    pop3_read_response(sockfd);
}

void pop3_retrieve_mail(int sockfd) {
    char command[BUFFER_SIZE];

    pop3_send_command(sockfd, "LIST\r\n");
    pop3_read_response(sockfd);

    snprintf(command, BUFFER_SIZE, "RETR 1\r\n"); // Retrieve first email
    pop3_send_command(sockfd, command);
    pop3_read_response(sockfd);
}

void pop3_logout(int sockfd) {
    pop3_send_command(sockfd, "QUIT\r\n");
    pop3_read_response(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd;
    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    pop3_connect(&sockfd, hostname);
    pop3_read_response(sockfd);
    
    pop3_login(sockfd, username, password);
    pop3_retrieve_mail(sockfd);
    pop3_logout(sockfd);

    close(sockfd);
    return EXIT_SUCCESS;
}