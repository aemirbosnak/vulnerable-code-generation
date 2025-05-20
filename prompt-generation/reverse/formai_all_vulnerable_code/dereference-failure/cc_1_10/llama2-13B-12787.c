//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: relaxed
// RelaxedEmailClient.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25 // email port
#define HOST "mail.example.com" // email server hostname

// Structure to hold email message data
typedef struct {
    char from[50]; // email address of sender
    char to[50]; // email address of recipient
    char subject[100]; // email subject
    char message[255]; // email message body
} email_message_t;

// Function to send an email message
void send_email(email_message_t *message) {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the email server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, HOST, &server_addr.sin_addr);

    // Connect to the email server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    // Build the email message
    char message_buffer[512];
    snprintf(message_buffer, sizeof(message_buffer),
             "From: %s\r\nTo: %s\r\nSubject: %s\r\n%s",
             message->from, message->to, message->subject, message->message);

    // Send the email message
    send(sock, message_buffer, strlen(message_buffer), 0);

    // Close the socket
    close(sock);
}

int main() {
    // Create a email message structure
    email_message_t message;
    message.from[0] = 'j';
    message.from[1] = 'o';
    message.from[2] = 'e';
    message.from[3] = 'n';
    message.from[4] = 'e';
    message.to[0] = 'm';
    message.to[1] = 'y';
    message.to[2] = 'e';
    message.to[3] = 'n';
    message.subject[0] = 'H';
    message.subject[1] = 'e';
    message.subject[2] = 'l';
    message.subject[3] = 'l';
    message.message[0] = 'H';
    message.message[1] = 'e';
    message.message[2] = 'l';
    message.message[3] = 'l';
    message.message[4] = 'o';
    message.message[5] = '!';

    // Send the email message
    send_email(&message);

    // Relax and enjoy the email sending process
    printf("Email sent successfully! 😎\n");

    return 0;
}