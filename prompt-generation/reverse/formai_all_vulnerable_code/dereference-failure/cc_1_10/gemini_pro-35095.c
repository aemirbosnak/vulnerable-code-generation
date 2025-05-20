//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

// Define the maximum size of the email message
#define MAX_EMAIL_SIZE 1024

// Define the port number for the SMTP server
#define SMTP_PORT 25

// Define the IP address of the SMTP server
#define SMTP_SERVER "smtp.example.com"

// Define the email address of the sender
#define SENDER_EMAIL "sender@example.com"

// Define the email address of the recipient
#define RECIPIENT_EMAIL "recipient@example.com"

// Define the subject of the email
#define EMAIL_SUBJECT "Hello World!"

// Define the body of the email
#define EMAIL_BODY "This is a test email."

// Create a socket
int create_socket(char *hostname, int port) {
    int sockfd;
    struct sockaddr_in servaddr;

    // Get the IP address of the SMTP server
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: gethostbyname() failed.\n");
        exit(EXIT_FAILURE);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error: socket() failed.\n");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr = *((struct in_addr *)host->h_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        fprintf(stderr, "Error: connect() failed.\n");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Send a command to the SMTP server
int send_command(int sockfd, char *command) {
    int bytes_sent;

    // Send the command to the server
    bytes_sent = send(sockfd, command, strlen(command), 0);
    if (bytes_sent == -1) {
        fprintf(stderr, "Error: send() failed.\n");
        return -1;
    }

    return bytes_sent;
}

// Receive a response from the SMTP server
int receive_response(int sockfd, char *buffer, int buffer_size) {
    int bytes_received;

    // Receive the response from the server
    bytes_received = recv(sockfd, buffer, buffer_size, 0);
    if (bytes_received == -1) {
        fprintf(stderr, "Error: recv() failed.\n");
        return -1;
    }

    return bytes_received;
}

// Send the email message to the SMTP server
int send_email(int sockfd, char *email_message) {
    int bytes_sent;

    // Send the email message to the server
    bytes_sent = send(sockfd, email_message, strlen(email_message), 0);
    if (bytes_sent == -1) {
        fprintf(stderr, "Error: send() failed.\n");
        return -1;
    }

    return bytes_sent;
}

// Close the socket
void close_socket(int sockfd) {
    // Close the socket
    close(sockfd);
}

// Main function
int main() {
    int sockfd;
    char buffer[1024];
    int bytes_received;
    char email_message[MAX_EMAIL_SIZE];

    // Create a socket
    sockfd = create_socket(SMTP_SERVER, SMTP_PORT);

    // Receive the welcome message from the SMTP server
    bytes_received = receive_response(sockfd, buffer, sizeof(buffer));
    if (bytes_received == -1) {
        fprintf(stderr, "Error: receive_response() failed.\n");
        exit(EXIT_FAILURE);
    }

    // Send the HELO command to the SMTP server
    send_command(sockfd, "HELO example.com\r\n");

    // Receive the response from the SMTP server
    bytes_received = receive_response(sockfd, buffer, sizeof(buffer));
    if (bytes_received == -1) {
        fprintf(stderr, "Error: receive_response() failed.\n");
        exit(EXIT_FAILURE);
    }

    // Send the MAIL FROM command to the SMTP server
    sprintf(email_message, "MAIL FROM: <%s>\r\n", SENDER_EMAIL);
    send_command(sockfd, email_message);

    // Receive the response from the SMTP server
    bytes_received = receive_response(sockfd, buffer, sizeof(buffer));
    if (bytes_received == -1) {
        fprintf(stderr, "Error: receive_response() failed.\n");
        exit(EXIT_FAILURE);
    }

    // Send the RCPT TO command to the SMTP server
    sprintf(email_message, "RCPT TO: <%s>\r\n", RECIPIENT_EMAIL);
    send_command(sockfd, email_message);

    // Receive the response from the SMTP server
    bytes_received = receive_response(sockfd, buffer, sizeof(buffer));
    if (bytes_received == -1) {
        fprintf(stderr, "Error: receive_response() failed.\n");
        exit(EXIT_FAILURE);
    }

    // Send the DATA command to the SMTP server
    send_command(sockfd, "DATA\r\n");

    // Receive the response from the SMTP server
    bytes_received = receive_response(sockfd, buffer, sizeof(buffer));
    if (bytes_received == -1) {
        fprintf(stderr, "Error: receive_response() failed.\n");
        exit(EXIT_FAILURE);
    }

    // Send the email message to the SMTP server
    sprintf(email_message, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", SENDER_EMAIL, RECIPIENT_EMAIL, EMAIL_SUBJECT, EMAIL_BODY);
    send_email(sockfd, email_message);

    // Receive the response from the SMTP server
    bytes_received = receive_response(sockfd, buffer, sizeof(buffer));
    if (bytes_received == -1) {
        fprintf(stderr, "Error: receive_response() failed.\n");
        exit(EXIT_FAILURE);
    }

    // Send the QUIT command to the SMTP server
    send_command(sockfd, "QUIT\r\n");

    // Receive the response from the SMTP server
    bytes_received = receive_response(sockfd, buffer, sizeof(buffer));
    if (bytes_received == -1) {
        fprintf(stderr, "Error: receive_response() failed.\n");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close_socket(sockfd);

    return 0;
}