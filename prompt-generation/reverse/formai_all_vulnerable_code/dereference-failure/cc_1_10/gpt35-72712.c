//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define IMAP_PORT 143
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Validate command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [IMAP server IP address]\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Connect to the IMAP server
    struct sockaddr_in imap_addr = {0};
    imap_addr.sin_family = AF_INET;
    imap_addr.sin_port = htons(IMAP_PORT);
    if (inet_pton(AF_INET, argv[1], &imap_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }
    if (connect(sockfd, (struct sockaddr *)&imap_addr, sizeof(imap_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Read the connection greeting from the server
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (bytes_read < 0) {
        perror("read");
        return 1;
    }
    buffer[bytes_read] = '\0';
    fprintf(stdout, "%s", buffer);

    // Send the login credentials to the server
    char *username = "<username>"; // Insert your IMAP username here
    char *password = "<password>"; // Insert your IMAP password here
    char login_command[BUFFER_SIZE];
    snprintf(login_command, BUFFER_SIZE - 1, "LOGIN %s %s\r\n", username, password);
    ssize_t bytes_written = write(sockfd, login_command, strlen(login_command));
    if (bytes_written < 0) {
        perror("write");
        return 1;
    }

    // Read the login response from the server
    bytes_read = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (bytes_read < 0) {
        perror("read");
        return 1;
    }
    buffer[bytes_read] = '\0';
    fprintf(stdout, "%s", buffer);

    // Send the list command to the server to get the list of mailboxes
    char list_command[] = "LIST \"\" *\r\n";
    bytes_written = write(sockfd, list_command, strlen(list_command));
    if (bytes_written < 0) {
        perror("write");
        return 1;
    }
    
    // Read the list response from the server
    bytes_read = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (bytes_read < 0) {
        perror("read");
        return 1;
    }
    buffer[bytes_read] = '\0';
    fprintf(stdout, "%s", buffer);

    // Close the socket and terminate the program
    close(sockfd);
    return 0;
}