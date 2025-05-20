//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <netinet/tcp.h>

#define PORT 993

// Function to create and connect to IMAP server
int connect_to_imap(char* hostname, char* username, char* password) {
    int sockfd, n;
    struct hostent* server;
    struct sockaddr_in serv_addr;
    char buffer[1000];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Resolve hostname
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    // Store the address in a sockaddr structure
    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Login to the server
    sprintf(buffer, "LOGIN %s %s\r\n", username, password);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read the response from the server
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    // Check for successful login
    if (strstr(buffer, "OK LOGIN completed") == NULL) {
        printf("Login failed: %s\n", buffer);
        exit(1);
    }

    return sockfd;
}

// Function to check for unread messages
int check_for_unread_messages(int sockfd) {
    char buffer[1000];
    bzero(buffer, sizeof(buffer));
    sprintf(buffer, "LIST UNSEEN\r\n");
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer));
    return (strstr(buffer, "UNSEEN")!= NULL);
}

// Function to fetch an email message
int fetch_message(int sockfd, int message_number) {
    char buffer[1000];
    bzero(buffer, sizeof(buffer));
    sprintf(buffer, "FETCH %d (RFC822.SIZE BODYSTRUCTURE)\r\n", message_number);
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer));
    return (strstr(buffer, "ENVELOPE-FROM")!= NULL);
}

int main() {
    char* hostname = "imap.example.com";
    char* username = "your_username";
    char* password = "your_password";
    int sockfd;

    sockfd = connect_to_imap(hostname, username, password);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR connecting to IMAP server\n");
        exit(1);
    }

    // Check for unread messages
    if (check_for_unread_messages(sockfd)) {
        printf("Unread messages exist\n");
    } else {
        printf("No unread messages\n");
    }

    // Fetch the first unread message
    int message_number = 0;
    while (!fetch_message(sockfd, message_number)) {
        message_number++;
    }

    // Close the socket
    close(sockfd);

    return 0;
}