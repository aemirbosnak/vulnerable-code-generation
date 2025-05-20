//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

// A puzzle called SMTPClient awaits your decode
// Allows user to send an email with only the right code, oh behold!

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

// Element to hold our email message
typedef struct {
    char *from;
    char *to;
    char *subject;
    char *body;
} Email;

// Function to create a new email structure
Email* create_email(const char* from, const char* to, const char* subject, const char* body) {
    Email* email = (Email*)malloc(sizeof(Email));
    email->from = strdup(from);
    email->to = strdup(to);
    email->subject = strdup(subject);
    email->body = strdup(body);
    return email;
}

// Free memory allocated for the email
void free_email(Email* email) {
    free(email->from);
    free(email->to);
    free(email->subject);
    free(email->body);
    free(email);
}

// Function to handle the responses from the server
void handle_server_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = read(sockfd, buffer, BUFFER_SIZE - 1);
    buffer[bytes_received] = '\0';
    printf("Server Response: %s", buffer);
}

// Function to send a command and wait for a response
void send_command(int sockfd, const char *command) {
    write(sockfd, command, strlen(command));
    handle_server_response(sockfd);
}

// The grand SMTP process unfolds in this function
void send_email(Email* email) {
    struct sockaddr_in server_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct hostent *host = gethostbyname("smtp.example.com"); // change to actual SMTP server
    if (host == NULL) {
        perror("Could not resolve host");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    handle_server_response(sockfd);
    
    // SMTP Protocol begins
    send_command(sockfd, "HELO localhost\r\n");
    
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "MAIL FROM: <%s>\r\n", email->from);
    send_command(sockfd, command);
    
    snprintf(command, sizeof(command), "RCPT TO: <%s>\r\n", email->to);
    send_command(sockfd, command);
    
    send_command(sockfd, "DATA\r\n");
    
    // Include Subject and Body in this twist
    snprintf(command, sizeof(command), "Subject: %s\r\n\r\n%s\r\n.\r\n", email->subject, email->body);
    send_command(sockfd, command);
    
    send_command(sockfd, "QUIT\r\n");

    close(sockfd);
}

// The enigma has us beckoned, main function to start
int main() {
    printf("Welcome to the SMTP Email Client.\n");

    // Lengthy email to puzzle the unwary
    Email* email = create_email("sender@example.com", "receiver@example.com", "Puzzle Email", 
                                 "Dear receiver,\n\nThis is a mystery message.\n\nYours truly,\n\nThe SMTP Client.\n");

    // With a task so simple, yet complex in its ways
    send_email(email);
    
    free_email(email);
    printf("Email sent successfully!\n");
    return 0;
}