//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25  //SMTP port number
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *he;
    char buffer[BUFFER_SIZE+1];
    char hostname[BUFFER_SIZE];
    char msg[BUFFER_SIZE];

    // Get the hostname of the local machine
    gethostname(hostname, BUFFER_SIZE);

    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: ./smtp_client hostname\n");
        exit(1);
    }

    // Get IP address associated with the given hostname
    if ((he = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "Error: %s is invalid hostname.\n", argv[1]);
        exit(1);
    }

    // Create the socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket.\n");
        exit(1);
    }

    // Fill in the server address structure
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr = *((struct in_addr*)he->h_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error connecting to server.\n");
        exit(1);
    }

    // Receive the greeting message from the server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error receiving greeting message.\n");
        exit(1);
    }
    printf("\n%s", buffer);

    // Send HELO message to the server
    snprintf(msg, sizeof(msg), "HELO %s\r\n", hostname);
    if (send(sockfd, msg, strlen(msg), 0) == -1) {
        perror("Error sending HELO message.\n");
        exit(1);
    }

    // Receive response from the server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error receiving response from server.\n");
        exit(1);
    }
    printf("\n%s", buffer);

    // Send MAIL FROM message to the server
    snprintf(msg, sizeof(msg), "MAIL FROM:<user@%s>\r\n", hostname);
    if (send(sockfd, msg, strlen(msg), 0) == -1) {
        perror("Error sending MAIL FROM message.\n");
        exit(1);
    }

    // Receive response from the server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error receiving response from server.\n");
        exit(1);
    }
    printf("\n%s", buffer);

    // Send RCPT TO message to the server
    snprintf(msg, sizeof(msg), "RCPT TO:<destination_email_address>\r\n");
    if (send(sockfd, msg, strlen(msg), 0) == -1) {
        perror("Error sending RCPT TO message.\n");
        exit(1);
    }

    // Receive response from the server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error receiving response from server.\n");
        exit(1);
    }
    printf("\n%s", buffer);

    // Send DATA message to the server
    snprintf(msg, sizeof(msg), "DATA\r\n");
    if (send(sockfd, msg, strlen(msg), 0) == -1) {
        perror("Error sending DATA message.\n");
        exit(1);
    }

    // Receive response from the server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error receiving response from server.\n");
        exit(1);
    }
    printf("\n%s", buffer);

    // Send message body to the server
    snprintf(msg, sizeof(msg), "From: <user@%s>\r\n", hostname);
    if (send(sockfd, msg, strlen(msg), 0) == -1) {
        perror("Error sending message header.\n");
        exit(1);
    }

    snprintf(msg, sizeof(msg), "To: <destination_email_address>\r\n");
    if (send(sockfd, msg, strlen(msg), 0) == -1) {
        perror("Error sending message header.\n");
        exit(1);
    }

    snprintf(msg, sizeof(msg), "Subject: Test email\r\n\r\n");
    if (send(sockfd, msg, strlen(msg), 0) == -1) {
        perror("Error sending message header.\n");
        exit(1);
    }

    snprintf(msg, sizeof(msg), "This is a test message. Please ignore.\r\n.\r\n");
    if (send(sockfd, msg, strlen(msg), 0) == -1) {
        perror("Error sending message body.\n");
        exit(1);
    }

    // Receive response from the server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error receiving response from server.\n");
        exit(1);
    }
    printf("\n%s\n\n", buffer);

    // Send QUIT message to the server
    snprintf(msg, sizeof(msg), "QUIT\r\n");
    if (send(sockfd, msg, strlen(msg), 0) == -1) {
        perror("Error sending QUIT message.\n");
        exit(1);
    }

    // Receive response from the server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error receiving response from server.\n");
        exit(1);
    }
    printf("\n%s", buffer);

    // Close the socket
    close(sockfd);
    return 0;
}