//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define IMAP_PORT 143
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int connect_to_imap_server(const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *host;

    host = gethostbyname(hostname);
    if (host == NULL) {
        error("Error in getting host");
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to server failed");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "%s\r\n", command);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        error("Error sending command");
    }
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;

    n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (n < 0) {
        error("Error receiving response");
    }

    buffer[n] = '\0';
    printf("Response: %s", buffer);
}

void login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A001 LOGIN %s %s", username, password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void list_mailboxes(int sockfd) {
    send_command(sockfd, "A002 LIST \"\" \"*\"");
    receive_response(sockfd);
}

int main() {
    const char *hostname = "imap.example.com";
    const char *username = "your_email@example.com";
    const char *password = "your_password";

    int sockfd = connect_to_imap_server(hostname);
    receive_response(sockfd); // Initial server greeting

    login(sockfd, username, password);
    list_mailboxes(sockfd);

    // Cleanup - close the socket
    close(sockfd);
    return 0;
}