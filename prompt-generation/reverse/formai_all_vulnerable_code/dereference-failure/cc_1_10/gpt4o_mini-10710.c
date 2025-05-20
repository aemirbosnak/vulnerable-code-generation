//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 1024
#define USERNAME "your_username"
#define PASSWORD "your_password"

// Structure for storing message details
typedef struct {
    int id;
    char subject[255];
} Email;

int connect_to_imap(const char* hostname) {
    struct sockaddr_in server_addr;
    struct hostent *host;
    int sockfd;

    if ((host = gethostbyname(hostname)) == NULL) {
        fprintf(stderr, "Error: Cannot resolve hostname %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

void send_command(int sockfd, const char* command) {
    if (write(sockfd, command, strlen(command)) < 0) {
        perror("Error sending command");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(sockfd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    if (bytes_read < 0) {
        perror("Error reading response");
    }
}

void login_to_imap(int sockfd) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A001 LOGIN %s %s\r\n", USERNAME, PASSWORD);
    send_command(sockfd, command);
    read_response(sockfd);
}

void fetch_emails(int sockfd) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A002 SELECT INBOX\r\n");
    send_command(sockfd, command);
    read_response(sockfd);
    
    snprintf(command, sizeof(command), "A003 SEARCH ALL\r\n");
    send_command(sockfd, command);
    read_response(sockfd);
}

void logout_from_imap(int sockfd) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A004 LOGOUT\r\n");
    send_command(sockfd, command);
    read_response(sockfd);
    close(sockfd);
}

int main() {
    const char *hostname = "imap.example.com"; // Replace with your IMAP server hostname
    int sockfd = connect_to_imap(hostname);

    login_to_imap(sockfd);
    fetch_emails(sockfd);
    logout_from_imap(sockfd);

    return 0;
}