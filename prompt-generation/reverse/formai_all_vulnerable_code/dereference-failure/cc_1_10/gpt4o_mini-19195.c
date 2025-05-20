//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 25
#define BUFFER_SIZE 1024

void print_prompt() {
    printf("Sherlock Holmes Email Client at your service!\n");
    printf("Please, tell me which action you wish to undertake:\n");
    printf("1. Send Email\n");
    printf("2. Retrieve Emails\n");
    printf("3. Exit\n");
    printf("Your choice: ");
}

void send_email(const char *server, const char *from, const char *to, const char *subject, const char *message) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Alas! I could not create a socket.\n");
        return;
    }

    // Get server info
    struct hostent *host = gethostbyname(server);
    if (!host) {
        printf("The server could not be found, dear Watson.\n");
        close(sockfd);
        return;
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Ah, my dear Watson! The connection has failed!\n");
        close(sockfd);
        return;
    }

    // Send EHLO command
    sprintf(buffer, "EHLO %s\r\n", from);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // Send MAIL FROM command
    sprintf(buffer, "MAIL FROM:<%s>\r\n", from);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // Send RCPT TO command
    sprintf(buffer, "RCPT TO:<%s>\r\n", to);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // Send DATA command
    send(sockfd, "DATA\r\n", 7, 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // Prepare and send the email content
    sprintf(buffer, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", from, to, subject, message);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // End the session
    send(sockfd, "QUIT\r\n", 7, 0);
    close(sockfd);
    printf("The email has been sent successfully, Watson!\n");
}

void retrieve_emails(const char *server, const char *user, const char *pass) {
    // Simplified retrieval simulation
    printf("I shall now connect to %s to fetch your emails...\n\n", server);
    printf("Be patient, my dear Watson...\n");
    
    // Simulating email retrieval
    sleep(2); // Simulate the delay in retrieving emails
    printf("Emails retrieved from %s:\n", server);
    printf("1. Email 1: Subject - A Case of Mistaken Identity\n");
    printf("2. Email 2: Subject - The Adventure of the Sussex Vampire\n");
    printf("3. Email 3: Subject - The Sign of Four\n");
}

int main() {
    char command[10];
    char server[100], from[100], to[100], subject[100], message[500];
    char user[100], pass[100];

    while (1) {
        print_prompt();
        fgets(command, sizeof(command), stdin);
        int choice = atoi(command);

        switch (choice) {
            case 1:
                printf("Enter SMTP server: ");
                fgets(server, sizeof(server), stdin);
                strtok(server, "\n"); // Remove newline
                printf("From: ");
                fgets(from, sizeof(from), stdin);
                strtok(from, "\n"); 
                printf("To: ");
                fgets(to, sizeof(to), stdin);
                strtok(to, "\n"); 
                printf("Subject: ");
                fgets(subject, sizeof(subject), stdin);
                strtok(subject, "\n"); 
                printf("Message: ");
                fgets(message, sizeof(message), stdin);
                strtok(message, "\n"); 
                send_email(server, from, to, subject, message);
                break;
            case 2:
                printf("Enter IMAP server: ");
                fgets(server, sizeof(server), stdin);
                strtok(server, "\n");
                printf("Username: ");
                fgets(user, sizeof(user), stdin);
                strtok(user, "\n");
                printf("Password: ");
                fgets(pass, sizeof(pass), stdin);
                strtok(pass, "\n");
                retrieve_emails(server, user, pass);
                break;
            case 3:
                printf("Exiting, dear Watson. Until next time!\n");
                return 0;
            default:
                printf("A most peculiar choice, dear friend. Please try again.\n");
        }
    }
}