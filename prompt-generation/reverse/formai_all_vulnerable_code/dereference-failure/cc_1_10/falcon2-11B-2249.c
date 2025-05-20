//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Function to send an email
void sendEmail(const char* emailAddress, const char* message) {
    int serverSocketFD, connectSocketFD, numBytesRead;
    struct sockaddr_in serverAddress;
    struct hostent* serverHostInfo;

    // Create a socket
    serverSocketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocketFD == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // Set up address and connect to server
    serverHostInfo = gethostbyname("smtp.gmail.com");
    if (serverHostInfo == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    memset((char*) &serverAddress, '\0', sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(25);
    serverAddress.sin_addr = *((struct in_addr*) serverHostInfo->h_addr);
    if (connect(serverSocketFD, (struct sockaddr*) &serverAddress, sizeof(serverAddress)) == -1) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send HELO command
    if (send(serverSocketFD, "EHLO [127.0.0.1]\r\n", 19, 0) < 0) {
        perror("Error sending HELO command");
        exit(1);
    }

    // Send AUTH command
    if (send(serverSocketFD, "AUTH LOGIN\r\n", 15, 0) < 0) {
        perror("Error sending AUTH command");
        exit(1);
    }

    // Send username and password
    if (send(serverSocketFD, "User: <your_email_address>\r\n", 23, 0) < 0) {
        perror("Error sending username");
        exit(1);
    }

    if (send(serverSocketFD, "Pass: <your_password>\r\n", 17, 0) < 0) {
        perror("Error sending password");
        exit(1);
    }

    // Send MAIL FROM command
    if (send(serverSocketFD, "MAIL FROM:<your_email_address>\r\n", 27, 0) < 0) {
        perror("Error sending MAIL FROM command");
        exit(1);
    }

    // Send RCPT TO command
    if (send(serverSocketFD, "RCPT TO:<recipient_email_address>\r\n", 26, 0) < 0) {
        perror("Error sending RCPT TO command");
        exit(1);
    }

    // Send DATA command
    if (send(serverSocketFD, "DATA\r\n", 6, 0) < 0) {
        perror("Error sending DATA command");
        exit(1);
    }

    // Send message
    if (send(serverSocketFD, message, strlen(message), 0) < 0) {
        perror("Error sending message");
        exit(1);
    }

    // Send QUIT command
    if (send(serverSocketFD, "QUIT\r\n", 7, 0) < 0) {
        perror("Error sending QUIT command");
        exit(1);
    }

    // Close socket
    close(serverSocketFD);
    exit(0);
}

int main() {
    char emailAddress[256], message[1024];

    // Get email address and message from user
    printf("Enter email address: ");
    fgets(emailAddress, sizeof(emailAddress), stdin);
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    // Trim newline characters from message
    message[strcspn(message, "\n")] = '\0';

    // Send email
    sendEmail(emailAddress, message);

    return 0;
}