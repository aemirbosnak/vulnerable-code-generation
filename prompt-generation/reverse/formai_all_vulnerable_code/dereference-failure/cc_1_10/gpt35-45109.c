//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

void sendMail(int clientSocket, char *senderEmail, char *recipientEmail, char *subject, char *message) {
    char buffer[MAX_BUFFER_SIZE];
    char *endLine = "\r\n";

    // Send HELO command
    sprintf(buffer, "HELO %s%s", "localhost", endLine);
    send(clientSocket, buffer, strlen(buffer), 0);

    // Send MAIL FROM command
    sprintf(buffer, "MAIL FROM:<%s>%s", senderEmail, endLine);
    send(clientSocket, buffer, strlen(buffer), 0);

    // Send RCPT TO command
    sprintf(buffer, "RCPT TO:<%s>%s", recipientEmail, endLine);
    send(clientSocket, buffer, strlen(buffer), 0);

    // Send DATA command
    sprintf(buffer, "DATA%s", endLine);
    send(clientSocket, buffer, strlen(buffer), 0);

    // Send email headers
    sprintf(buffer, "From: %s%s", senderEmail, endLine);
    send(clientSocket, buffer, strlen(buffer), 0);
    sprintf(buffer, "To: %s%s", recipientEmail, endLine);
    send(clientSocket, buffer, strlen(buffer), 0);
    sprintf(buffer, "Subject: %s%s", subject, endLine);
    send(clientSocket, buffer, strlen(buffer), 0);

    // Send email body
    sprintf(buffer, "%s%s", message, endLine);
    send(clientSocket, buffer, strlen(buffer), 0);

    // Send end of email message
    sprintf(buffer, ".%s", endLine);
    send(clientSocket, buffer, strlen(buffer), 0);

    // Send QUIT command
    sprintf(buffer, "QUIT%s", endLine);
    send(clientSocket, buffer, strlen(buffer), 0);
}

int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;
    struct hostent *server;

    char senderEmail[256];
    char recipientEmail[256];
    char subject[256];
    char message[MAX_BUFFER_SIZE];

    // Get user input for email details
    printf("Enter Sender Email: ");
    fgets(senderEmail, 256, stdin);
    printf("Enter Recipient Email: ");
    fgets(recipientEmail, 256, stdin);
    printf("Enter Subject: ");
    fgets(subject, 256, stdin);
    printf("Enter Message: ");
    fgets(message, MAX_BUFFER_SIZE, stdin);

    // Remove end of line character from user input
    senderEmail[strcspn(senderEmail, "\n")] = 0;
    recipientEmail[strcspn(recipientEmail, "\n")] = 0;
    subject[strcspn(subject, "\n")] = 0;
    message[strcspn(message, "\n")] = 0;

    // Create socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        printf("Error creating socket.\n");
        return 1;
    }

    // Get server information
    server = gethostbyname("smtp.gmail.com");
    if (server == NULL) {
        printf("Error getting server address.\n");
        return 1;
    }

    // Set server address information
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(587);
    serverAddr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr *) server->h_addr));

    // Connect to server
    if (connect(clientSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
        printf("Error connecting to server.\n");
        return 1;
    }

    // Receive server welcome message
    char buffer[MAX_BUFFER_SIZE];
    recv(clientSocket, buffer, MAX_BUFFER_SIZE, 0);

    // Send email
    sendMail(clientSocket, senderEmail, recipientEmail, subject, message);

    // Close socket
    close(clientSocket);

    return 0;
}