//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

// Define constants
#define SERVER "mail.example.com"
#define PORT 993 // IMAP secure port
#define USER "email@example.com"
#define PASS "password"

// Function to receive data from the server
int receive_data(int sockfd, char* buffer, int buffer_size) {
    int nbytes = 0;
    int total_bytes = 0;
    do {
        nbytes = recv(sockfd, buffer + total_bytes, buffer_size - total_bytes, 0);
        if (nbytes < 0) {
            perror("Error receiving data from server");
            exit(EXIT_FAILURE);
        }
        total_bytes += nbytes;
    } while (buffer[total_bytes-1] != '\n');

    buffer[total_bytes] = '\0';
    return total_bytes;
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent* server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Retrieve server IP address
    server = gethostbyname(SERVER);
    if (server == NULL) {
        perror("Error retrieving server IP address");
        exit(EXIT_FAILURE);
    }

    // Set server address and port
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = *((unsigned long*) server->h_addr);
    servaddr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    int nbytes;

    // Receive server greeting
    nbytes = receive_data(sockfd, buffer, sizeof(buffer));
    printf("%.*s\n", nbytes, buffer);

    // Send login information
    sprintf(buffer, "LOGIN %s %s\r\n", USER, PASS);
    write(sockfd, buffer, strlen(buffer));
    nbytes = receive_data(sockfd, buffer, sizeof(buffer));
    printf("%.*s\n", nbytes, buffer);

    // Select inbox
    write(sockfd, "SELECT INBOX\r\n", 14);
    nbytes = receive_data(sockfd, buffer, sizeof(buffer));
    printf("%.*s\n", nbytes, buffer);

    // Fetch mailbox status
    write(sockfd, "STATUS INBOX (MESSAGES UNSEEN)\r\n", 33);
    nbytes = receive_data(sockfd, buffer, sizeof(buffer));
    printf("%.*s\n", nbytes, buffer);

    // Logout
    write(sockfd, "LOGOUT\r\n", 8);
    nbytes = receive_data(sockfd, buffer, sizeof(buffer));
    printf("%.*s\n", nbytes, buffer);

    // Close socket
    close(sockfd);

    return 0;
}