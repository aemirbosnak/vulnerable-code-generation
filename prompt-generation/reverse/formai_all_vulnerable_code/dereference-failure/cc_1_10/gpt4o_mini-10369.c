//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define SERVER "imap.example.com"
#define PORT 993
#define BUFFER_SIZE 1024

// Function to create a secure socket connection for IMAP over SSL
int create_socket() {
    struct sockaddr_in server_addr;
    int sockfd;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    struct hostent *host = gethostbyname(SERVER);
    if (host == NULL) {
        herror("Error resolving host");
        exit(EXIT_FAILURE);
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to communicate using IMAP commands
void send_imap_command(int sockfd, const char* command, char* response) {
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);
    
    int n = read(sockfd, response, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }

    response[n] = '\0'; // Null-terminate the response
}

// Function to authenticate the user
void authenticate(int sockfd, const char* username, const char* password) {
    char command[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A001 LOGIN \"%s\" \"%s\"", username, password);
    send_imap_command(sockfd, command, response);
    printf("Server Response: %s\n", response);
}

// Function to fetch the mail count
void fetch_mail_count(int sockfd) {
    char command[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A002 SELECT INBOX");
    send_imap_command(sockfd, command, response);
    printf("Server Response: %s\n", response);

    snprintf(command, sizeof(command), "A003 STATUS INBOX (MESSAGES)");
    send_imap_command(sockfd, command, response);
    printf("Mail count: %s\n", response);
}

// Main function to run the IMAP client
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *username = argv[1];
    const char *password = argv[2];

    int sockfd = create_socket();
    authenticate(sockfd, username, password);
    fetch_mail_count(sockfd);

    // Gracefully exit
    close(sockfd);
    return 0;
}