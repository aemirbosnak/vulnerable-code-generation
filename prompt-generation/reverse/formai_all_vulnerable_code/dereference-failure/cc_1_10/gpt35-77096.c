//FormAI DATASET v1.0 Category: Email Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char from[MAX_BUFFER_SIZE], to[MAX_BUFFER_SIZE], subject[MAX_BUFFER_SIZE], message[MAX_BUFFER_SIZE];
    // Initialize buffers with null terminators
    memset(from, '\0', sizeof(from));
    memset(to, '\0', sizeof(to));
    memset(subject, '\0', sizeof(subject));
    memset(message, '\0', sizeof(message));

    printf("Welcome to my Grateful Email Client Program!\n");

    // Prompt the user for input
    printf("Please enter the sender's email address: ");
    fgets(from, MAX_BUFFER_SIZE, stdin);
    from[strcspn(from, "\n")] = '\0'; // Remove trailing newline

    printf("Please enter the recipient's email address: ");
    fgets(to, MAX_BUFFER_SIZE, stdin);
    to[strcspn(to, "\n")] = '\0'; // Remove trailing newline

    printf("Please enter the email subject: ");
    fgets(subject, MAX_BUFFER_SIZE, stdin);
    subject[strcspn(subject, "\n")] = '\0'; // Remove trailing newline

    printf("Please enter the email message: ");
    fgets(message, MAX_BUFFER_SIZE, stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove trailing newline

    // Construct the email content
    char *email = malloc(MAX_BUFFER_SIZE * sizeof(char));
    strcat(email, "From: ");
    strcat(email, from);
    strcat(email, "\n");
    strcat(email, "To: ");
    strcat(email, to);
    strcat(email, "\n");
    strcat(email, "Subject: ");
    strcat(email, subject);
    strcat(email, "\n");
    strcat(email, "\n");
    strcat(email, message);
    strcat(email, "\n");

    // Email simulation
    printf("\nEmail sent successfully!\n");
    printf("---Email Content---\n");
    printf("%s", email);

    free(email); // Release dynamically allocated memory

    return 0;
}