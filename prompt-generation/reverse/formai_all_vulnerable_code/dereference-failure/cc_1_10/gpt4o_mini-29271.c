//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER "imap.example.com"
#define PORT 993
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int create_socket() {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Unable to open socket.");
    }

    struct hostent *server = gethostbyname(SERVER);
    if (server == NULL) {
        error("No such host");
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);  // IMAP protocol requires CRLF
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    while (1) {
        bzero(buffer, BUFFER_SIZE);
        int n = read(sockfd, buffer, BUFFER_SIZE - 1);
        if (n <= 0) break;
        printf("%s", buffer);
        if (strstr(buffer, "OK") != NULL) break; // Break on successful commands
    }
}

void fetch_emails(int sockfd) {
    send_command(sockfd, "A01 LOGIN username password");
    read_response(sockfd);

    send_command(sockfd, "A02 SELECT INBOX");
    read_response(sockfd);

    send_command(sockfd, "A03 FETCH 1:* FLAGS");
    read_response(sockfd);

    send_command(sockfd, "A04 LOGOUT");
    read_response(sockfd);
}

int main() {
    printf("=== Sherlock's IMAP Client ===\n");

    // Establish a connection
    int sockfd = create_socket();
    printf("Connected to the email server...\n");

    // The clever sleuth now fetches emails
    fetch_emails(sockfd);

    // Close the socket; the case is solved
    close(sockfd);
    printf("Client disconnected.\n");   

    return 0;
}