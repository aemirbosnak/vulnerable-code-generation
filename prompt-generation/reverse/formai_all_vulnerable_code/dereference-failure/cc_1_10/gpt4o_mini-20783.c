//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define IMAP_SERVER "imap.example.com"
#define PORT 993
#define BUFFER_SIZE 1024

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, "\r\n", 2, 0);
}

void read_response(int sockfd, char *buffer) {
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
}

void connect_to_imap(const char *username, const char *password) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    char buffer[BUFFER_SIZE];

    host = gethostbyname(IMAP_SERVER);
    if (!host) {
        fprintf(stderr, "Could not resolve host %s\n", IMAP_SERVER);
        exit(EXIT_FAILURE);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(PORT);

    // Connect to the IMAP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Read initial response from the server
    read_response(sockfd, buffer);
    printf("Server: %s", buffer);

    // Send login command
    char login_command[BUFFER_SIZE];
    snprintf(login_command, sizeof(login_command), "A001 LOGIN \"%s\" \"%s\"", username, password);
    send_command(sockfd, login_command);
    read_response(sockfd, buffer);
    printf("Login Response: %s", buffer);

    // Fetch the list of mailboxes
    send_command(sockfd, "A002 LIST \"\" \"%\"");
    read_response(sockfd, buffer);
    printf("Mailbox List: %s", buffer);

    // Send logout command
    send_command(sockfd, "A003 LOGOUT");
    read_response(sockfd, buffer);
    printf("Logout Response: %s", buffer);

    // Close the socket
    close(sockfd);
    printf("Connection closed. Farewell, dear email client!\n");
}

int main() {
    const char *username = "your_email@example.com";
    const char *password = "your_password";

    printf("Welcome to our love story with the IMAP server!\n");
    printf("As we connect to the digital skies, let’s reach for our love letters...\n");

    connect_to_imap(username, password);

    printf("The journey has come to an end, but the memories shall remain...\n");
    return 0;
}