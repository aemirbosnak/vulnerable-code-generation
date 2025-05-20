//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SMTP_PORT 25
#define MAX_BUFFER_SIZE 1024

// Function to send a command to the SMTP server
int send_command(int sockfd, char *command) {
    int n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("Error writing to socket");
        return -1;
    }
    return 0;
}

// Function to receive a response from the SMTP server
int receive_response(int sockfd, char *buffer) {
    int n = read(sockfd, buffer, MAX_BUFFER_SIZE);
    if (n < 0) {
        perror("Error reading from socket");
        return -1;
    }
    return 0;
}

// Function to send an email message
int send_email(char *sender, char *recipient, char *subject, char *body) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return -1;
    }

    // Get the IP address of the SMTP server
    struct hostent *server = gethostbyname("smtp-server.com");
    if (server == NULL) {
        perror("Error getting host by name");
        close(sockfd);
        return -1;
    }

    // Connect to the SMTP server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SMTP_PORT);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        close(sockfd);
        return -1;
    }

    // Receive the welcome message from the SMTP server
    char buffer[MAX_BUFFER_SIZE];
    if (receive_response(sockfd, buffer) < 0) {
        close(sockfd);
        return -1;
    }

    // Send the HELO command
    if (send_command(sockfd, "HELO smtp-client.com\r\n") < 0) {
        close(sockfd);
        return -1;
    }

    // Receive the response to the HELO command
    if (receive_response(sockfd, buffer) < 0) {
        close(sockfd);
        return -1;
    }

    // Send the MAIL FROM command
    char mail_from[MAX_BUFFER_SIZE];
    sprintf(mail_from, "MAIL FROM: <%s>\r\n", sender);
    if (send_command(sockfd, mail_from) < 0) {
        close(sockfd);
        return -1;
    }

    // Receive the response to the MAIL FROM command
    if (receive_response(sockfd, buffer) < 0) {
        close(sockfd);
        return -1;
    }

    // Send the RCPT TO command
    char rcpt_to[MAX_BUFFER_SIZE];
    sprintf(rcpt_to, "RCPT TO: <%s>\r\n", recipient);
    if (send_command(sockfd, rcpt_to) < 0) {
        close(sockfd);
        return -1;
    }

    // Receive the response to the RCPT TO command
    if (receive_response(sockfd, buffer) < 0) {
        close(sockfd);
        return -1;
    }

    // Send the DATA command
    if (send_command(sockfd, "DATA\r\n") < 0) {
        close(sockfd);
        return -1;
    }

    // Receive the response to the DATA command
    if (receive_response(sockfd, buffer) < 0) {
        close(sockfd);
        return -1;
    }

    // Send the email message
    char email_message[MAX_BUFFER_SIZE];
    sprintf(email_message, "From: %s\nTo: %s\nSubject: %s\n\n%s\n.\r\n", sender, recipient, subject, body);
    if (send_command(sockfd, email_message) < 0) {
        close(sockfd);
        return -1;
    }

    // Receive the response to the email message
    if (receive_response(sockfd, buffer) < 0) {
        close(sockfd);
        return -1;
    }

    // Send the QUIT command
    if (send_command(sockfd, "QUIT\r\n") < 0) {
        close(sockfd);
        return -1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}

// Main function
int main() {
    // Send an email
    if (send_email("sender@example.com", "recipient@example.com", "Test Email", "This is a test email.") < 0) {
        perror("Error sending email");
        return -1;
    }

    return 0;
}