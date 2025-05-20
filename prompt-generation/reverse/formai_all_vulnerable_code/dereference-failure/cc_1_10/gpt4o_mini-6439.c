//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 25 // SMTP port
#define BUFFER_SIZE 1024

void send_command(int sockfd, const char *cmd, char *response) {
    memset(response, 0, BUFFER_SIZE); // Clear response buffer
    send(sockfd, cmd, strlen(cmd), 0); // Send command to server
    recv(sockfd, response, BUFFER_SIZE - 1, 0); // Receive response from server
    printf("Server: %s", response); // Print server response
}

int main() {
    struct sockaddr_in server_addr;
    int sockfd;
    char response[BUFFER_SIZE];
    char email[BUFFER_SIZE], recipient[BUFFER_SIZE], subject[BUFFER_SIZE], body[BUFFER_SIZE];
    
    printf("Welcome to the Visionary Email Client!\n");
    
    // Step 1: Get email details from user
    printf("Enter your email address: ");
    fgets(email, BUFFER_SIZE, stdin);
    strtok(email, "\n"); // Remove newline

    printf("Enter recipient's email address: ");
    fgets(recipient, BUFFER_SIZE, stdin);
    strtok(recipient, "\n"); // Remove newline

    printf("Enter email subject: ");
    fgets(subject, BUFFER_SIZE, stdin);
    strtok(subject, "\n"); // Remove newline

    printf("Enter email body (end with a dot on a new line):\n");
    char temp_line[BUFFER_SIZE];
    body[0] = '\0'; // Initialize body
    while(1) {
        fgets(temp_line, BUFFER_SIZE, stdin);
        if (strcmp(temp_line, ".\n") == 0) break; // Stop reading on dot
        strcat(body, temp_line); // Append line to body
    }

    // Step 2: Create socket and connect to the SMTP server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }
    
    struct hostent *host = gethostbyname("smtp.example.com"); // Change to your SMTP server
    if (host == NULL) {
        perror("No such host");
        return 1;
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return 1;
    }
    
    // Step 3: Communicate with the SMTP server
    send_command(sockfd, "EHLO localhost\r\n", response); // Greet the server

    send_command(sockfd, "MAIL FROM: <your_email@example.com>\r\n", response); // Replace with input email
    send_command(sockfd, "RCPT TO: <recipient@example.com>\r\n", response); // Replace with recipient email
    send_command(sockfd, "DATA\r\n", response);
    
    // Prepare the email header
    char email_message[BUFFER_SIZE * 5];
    snprintf(email_message, sizeof(email_message), "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n",
             email, recipient, subject, body);
    
    send_command(sockfd, email_message, response); // Send the email
    send_command(sockfd, "QUIT\r\n", response); // Quit session

    // Step 4: Close the socket
    close(sockfd);
    
    printf("Email successfully sent!\n");
    return 0;
}