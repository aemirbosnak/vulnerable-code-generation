//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUFFER 1024
#define MAX_USERNAME 100
#define MAX_PASSWORD 100

int login(int sockfd, char *username, char *password);
int select_inbox(int sockfd, char *inbox_name);
int list_emails(int sockfd);
int fetch_email(int sockfd, int email_index);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: imap <server_address> <username> <password>\n");
        return 1;
    }

    char *server_address = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    // Resolve server address
    struct hostent *server = gethostbyname(server_address);
    if (server == NULL) {
        printf("Error: No such host %s\n", server_address);
        return 1;
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Failed to create socket\n");
        return 1;
    }

    // Set up server address struct
    struct sockaddr_in server_addr;
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(993);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Failed to connect to server\n");
        return 1;
    }

    // Log in to server
    if (!login(sockfd, username, password)) {
        printf("Error: Failed to authenticate with server\n");
        return 1;
    }

    // Select inbox
    if (!select_inbox(sockfd, "INBOX")) {
        printf("Error: Failed to select inbox\n");
        return 1;
    }

    // List emails
    if (!list_emails(sockfd)) {
        printf("Error: Failed to list emails\n");
        return 1;
    }

    // Fetch email
    if (!fetch_email(sockfd, 1)) {
        printf("Error: Failed to fetch email\n");
        return 1;
    }

    return 0;
}

int login(int sockfd, char *username, char *password) {
    char buffer[MAX_BUFFER];
    bzero(buffer, MAX_BUFFER);
    sprintf(buffer, ". login %s %s\r\n", username, password);
    send(sockfd, buffer, strlen(buffer), 0);

    bzero(buffer, MAX_BUFFER);
    recv(sockfd, buffer, MAX_BUFFER, 0);

    if (strstr(buffer, "OK") == NULL) {
        return 0;
    }

    return 1;
}

int select_inbox(int sockfd, char *inbox_name) {
    char buffer[MAX_BUFFER];
    bzero(buffer, MAX_BUFFER);
    sprintf(buffer, ". select \"%s\"\r\n", inbox_name);
    send(sockfd, buffer, strlen(buffer), 0);

    bzero(buffer, MAX_BUFFER);
    recv(sockfd, buffer, MAX_BUFFER, 0);

    if (strstr(buffer, "OK") == NULL) {
        return 0;
    }

    return 1;
}

int list_emails(int sockfd) {
    char buffer[MAX_BUFFER];
    bzero(buffer, MAX_BUFFER);
    sprintf(buffer, ". fetch 1:10 all\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    bzero(buffer, MAX_BUFFER);
    recv(sockfd, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    return 1;
}

int fetch_email(int sockfd, int email_index) {
    char buffer[MAX_BUFFER];
    bzero(buffer, MAX_BUFFER);
    sprintf(buffer, ". fetch %d full\r\n", email_index);
    send(sockfd, buffer, strlen(buffer), 0);

    bzero(buffer, MAX_BUFFER);
    recv(sockfd, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    return 1;
}