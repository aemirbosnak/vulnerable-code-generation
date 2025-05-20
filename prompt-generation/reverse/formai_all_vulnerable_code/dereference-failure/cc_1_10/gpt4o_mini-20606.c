//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 1024

void handleError(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int createSocket(const char *hostname) {
    struct sockaddr_in serverAddr;
    struct hostent *host;

    host = gethostbyname(hostname);
    if (host == NULL) {
        handleError("Error getting host");
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handleError("Error creating socket");
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(IMAP_PORT);
    bcopy((char *)host->h_addr, (char *)&serverAddr.sin_addr.s_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        handleError("Error connecting to server");
    }

    return sockfd;
}

void imapSend(int sockfd, const char *command, char *response) {
    char buffer[BUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "%s\r\n", command);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        handleError("Error sending command");
    }

    // Simple read response
    int n = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        handleError("Error receiving response");
    }

    response[n] = '\0';
}

void login(int sockfd, const char *username, const char *password) {
    char response[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];

    snprintf(buffer, sizeof(buffer), "A01 LOGIN %s %s", username, password);
    imapSend(sockfd, buffer, response);
    printf("Login Response: %s\n", response);
    // Handle response for errors/confirmation
}

void listMailboxes(int sockfd) {
    char response[BUFFER_SIZE];
    imapSend(sockfd, "A02 LIST \"\" \"*\"", response);
    printf("Mailboxes Response: %s\n", response);
}

void fetchEmail(int sockfd, const char *mailbox, const char *emailID) {
    char response[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];

    snprintf(buffer, sizeof(buffer), "A03 FETCH %s BODY[]", emailID);
    imapSend(sockfd, buffer, response);
    printf("Fetch Email Response from %s: %s\n", mailbox, response);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = createSocket(hostname);
    char response[BUFFER_SIZE];

    // Read server greeting
    recv(sockfd, response, BUFFER_SIZE - 1, 0);
    printf("Server Greeting: %s\n", response);

    login(sockfd, username, password);

    // List mailboxes
    listMailboxes(sockfd);

    // Fetch an email from the INBOX (example: email ID "1")
    fetchEmail(sockfd, "INBOX", "1");

    // Cleaning up and closing the connection
    close(sockfd);
    return 0;
}