//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXLINE 1024
#define MAXEMAIL 256

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void to_lower_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int connect_to_server(const char *hostname, const char *port) {
    int sockfd;
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC; // Don't care IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM; // TCP stream sockets

    if (getaddrinfo(hostname, port, &hints, &res) != 0) {
        error("getaddrinfo failed");
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) != 0) {
        error("Error connecting to server");
    }

    freeaddrinfo(res); // Free the linked list
    return sockfd;
}

void send_message(int sockfd, const char *message) {
    if (send(sockfd, message, strlen(message), 0) < 0) {
        error("Error sending message");
    }
}

void receive_response(int sockfd) {
    char buffer[MAXLINE];
    int n;
    bzero(buffer, MAXLINE);
    if ((n = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) < 0) {
        error("Error receiving response");
    }
    buffer[n] = '\0';
    printf("Response: %s", buffer);
}

void login(int sockfd, const char *username, const char *password) {
    char command[MAXLINE];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_message(sockfd, command);
    receive_response(sockfd);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_message(sockfd, command);
    receive_response(sockfd);
}

void list_emails(int sockfd) {
    send_message(sockfd, "LIST\r\n");
    receive_response(sockfd);
}

void read_email(int sockfd, int email_number) {
    char command[MAXLINE];

    snprintf(command, sizeof(command), "RETR %d\r\n", email_number);
    send_message(sockfd, command);
    receive_response(sockfd);
}

void fetch_emails(const char *hostname, const char *username, const char *password) {
    int sockfd;
    sockfd = connect_to_server(hostname, "110"); // POP3 default port 110

    receive_response(sockfd); // Server greeting

    login(sockfd, username, password);
    list_emails(sockfd);

    int email_num;
    printf("Enter email number to read (0 to exit): ");
    while (scanf("%d", &email_num) && email_num != 0) {
        read_email(sockfd, email_num);
        printf("Enter email number to read (0 to exit): ");
    }

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

    fetch_emails(hostname, username, password);
    return 0;
}