//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER "smtp.example.com"
#define PORT 587
#define BUFFER_SIZE 1024

// Function declarations
void send_email(const char *recipient, const char *subject, const char *body);
void receive_email();
void display_email(const char *email_content);
char *get_input(const char *prompt);

int main() {
    int choice;
    while (1) {
        printf("Email Client Menu:\n");
        printf("1. Send Email\n");
        printf("2. Receive Emails\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline

        switch (choice) {
            case 1: {
                char *recipient = get_input("Enter recipient email: ");
                char *subject = get_input("Enter subject: ");
                char *body = get_input("Enter email body: ");
                send_email(recipient, subject, body);
                free(recipient);
                free(subject);
                free(body);
                break;
            }
            case 2:
                receive_email();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

void send_email(const char *recipient, const char *subject, const char *body) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the server failed");
        close(sock);
        return;
    }

    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    sprintf(buffer, "HELO %s\r\n", SERVER);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    sprintf(buffer, "MAIL FROM:<you@example.com>\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    sprintf(buffer, "RCPT TO:<%s>\r\n", recipient);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    sprintf(buffer, "DATA\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    sprintf(buffer, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    sprintf(buffer, "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);
    close(sock);
}

void receive_email() {
    // Placeholder for receiving emails
    printf("Receiving emails is not implemented yet.\n");
}

void display_email(const char *email_content) {
    // Functionality to display email
    printf("Email content:\n%s\n", email_content);
}

char *get_input(const char *prompt) {
    char *input = malloc(BUFFER_SIZE);
    if (input == NULL) {
        perror("Unable to allocate memory");
        exit(EXIT_FAILURE);
    }
    printf("%s", prompt);
    fgets(input, BUFFER_SIZE, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character
    return input;
}