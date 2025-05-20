//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define SMTP_SERVER "smtp.example.com"
#define SMTP_PORT 587
#define USER "your_email@example.com"
#define PASSWORD "your_password"

void *send_email(void *arg) {
    char *recipient = (char *)arg;
    char buffer[BUFFER_SIZE];
    
    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    // Resolve SMTP server address
    struct hostent *host = gethostbyname(SMTP_SERVER);
    if (host == NULL) {
        perror("No such host");
        close(sockfd);
        return NULL;
    }

    // Setup server address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        return NULL;
    }

    // Read server response
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Start SMTP communication
    snprintf(buffer, sizeof(buffer), "EHLO localhost\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // AUTH LOGIN
    snprintf(buffer, sizeof(buffer), "AUTH LOGIN\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send the username
    char encoded_user[BUFFER_SIZE];
    snprintf(encoded_user, sizeof(encoded_user), "%s\r\n", USER);
    send(sockfd, encoded_user, strlen(encoded_user), 0);
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send the password
    char encoded_pass[BUFFER_SIZE];
    snprintf(encoded_pass, sizeof(encoded_pass), "%s\r\n", PASSWORD);
    send(sockfd, encoded_pass, strlen(encoded_pass), 0);
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Set MAIL FROM
    snprintf(buffer, sizeof(buffer), "MAIL FROM:<%s>\r\n", USER);
    send(sockfd, buffer, strlen(buffer), 0);
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Set RCPT TO
    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", recipient);
    send(sockfd, buffer, strlen(buffer), 0);
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // DATA
    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Email content
    snprintf(buffer, sizeof(buffer), "Subject: Test Email\r\n\r\nHello, this is a test email.\r\n.\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Quit
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Close the socket
    close(sockfd);
    free(recipient); // Free the dynamic memory for recipient
    return NULL;
}

int main() {
    pthread_t thread;

    // Get recipient email address from user
    char *recipient = malloc(BUFFER_SIZE);
    if (!recipient) {
        perror("Memory allocation failed");
        return EXIT_FAILURE;
    }
    printf("Enter recipient email address: ");
    fgets(recipient, BUFFER_SIZE, stdin);
    recipient[strcspn(recipient, "\n")] = 0; // Remove newline character

    // Create and run the email sending thread
    if (pthread_create(&thread, NULL, send_email, (void *)recipient) != 0) {
        perror("Thread creation failed");
        free(recipient);
        return EXIT_FAILURE;
    }

    // Wait for the thread to finish
    pthread_join(thread, NULL);
    printf("Email sent successfully!\n");

    return EXIT_SUCCESS;
}