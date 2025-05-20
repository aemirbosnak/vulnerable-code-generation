//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: Sherlock Holmes
// Consulting Sherlock: The Case of the Swift SMTP Client
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Initiate connection, Watson!
int connect_smtp(const char *host, int port) {
    int sockfd;

    // Establish a socket, my dear Watson
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Elementary, my dear Watson! Failed to create socket.\n");
        exit(EXIT_FAILURE);
    }

    // Resolve address, good show!
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
        perror("Resolve address, Watson! Failed to convert IPv4 address.\n");
        exit(EXIT_FAILURE);
    }

    // Connect to SMTP server, excellent!
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Failed to connect to SMTP server, my dear Watson.\n");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Send command, my dear Holmes!
void send_command(int sockfd, const char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("Elementary, my dear Watson! Failed to send command.\n");
        exit(EXIT_FAILURE);
    }
}

// Retrieve response, Watson!
char *recv_response(int sockfd) {
    char *response = malloc(512);
    memset(response, 0, 512);

    if (recv(sockfd, response, 512, 0) < 0) {
        perror("Failed to retrieve response.\n");
        exit(EXIT_FAILURE);
    }

    return response;
}

// Establish identity, most interesting!
void ehlo(int sockfd, const char *hostname) {
    char command[512];

    sprintf(command, "EHLO %s\r\n", hostname);
    send_command(sockfd, command);

    char *response = recv_response(sockfd);
    printf("Server response: %s\n", response);
}

// Send email, Watson, send email!
void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    char command[512];

    sprintf(command, "MAIL FROM: %s\r\n", from);
    send_command(sockfd, command);
    char *response = recv_response(sockfd);
    printf("Server response: %s\n", response);

    sprintf(command, "RCPT TO: %s\r\n", to);
    send_command(sockfd, command);
    response = recv_response(sockfd);
    printf("Server response: %s\n", response);

    sprintf(command, "DATA\r\n");
    send_command(sockfd, command);
    response = recv_response(sockfd);
    printf("Server response: %s\n", response);

    sprintf(command, "Subject: %s\r\n", subject);
    send_command(sockfd, command);
    sprintf(command, "%s\r\n", body);
    send_command(sockfd, command);

    sprintf(command, ".\r\n");
    send_command(sockfd, command);
    response = recv_response(sockfd);
    printf("Server response: %s\n", response);
}

// End communication, Watson, end communication!
void quit(int sockfd) {
    send_command(sockfd, "QUIT\r\n");

    char *response = recv_response(sockfd);
    printf("Server response: %s\n", response);

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        printf("Insufficient arguments, Watson! Usage: %s <host> <port> <from> <to> <subject>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd = connect_smtp(argv[1], atoi(argv[2]));

    char *hostname = "example.com";

    ehlo(sockfd, hostname);

    char *body = "My dear Watson, the mystery has been solved! The butler did it, of course.";

    send_email(sockfd, argv[3], argv[4], argv[5], body);

    quit(sockfd);

    return 0;
}