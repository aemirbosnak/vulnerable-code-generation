//FormAI DATASET v1.0 Category: Email Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to read user input
char *read_input() {
    char buffer[1000];
    fgets(buffer, 1000, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // removes trailing newline character
    char *input = strdup(buffer);
    return input;
}

// function to send email
void send_email(char *to, char *subject, char *body) {
    printf("Sending email...\n");
    printf("To: %s\n", to);
    printf("Subject: %s\n", subject);
    printf("Body: %s\n", body);
    printf("Email sent successfully!\n");
}

// main function to run email client
int main() {
    printf("Welcome to GratefulMail!\n");
    printf("Please enter the recipient's email address: ");
    char *to = read_input();

    printf("\nThank you! Please enter the subject of your email: ");
    char *subject = read_input();

    printf("\nGreat! Now, please enter the body of your email:\n");
    char *body = read_input();

    // confirm with user before sending email
    printf("\nAre you sure you want to send this email? (y/n): ");
    char *confirmation = read_input();

    if (strcmp(confirmation, "y") == 0 || strcmp(confirmation, "Y") == 0) {
        send_email(to, subject, body);
    } else {
        printf("Email not sent. Please try again.\n");
    }

    // free memory allocated for user inputs
    free(to);
    free(subject);
    free(body);
    free(confirmation);

    return 0;
}