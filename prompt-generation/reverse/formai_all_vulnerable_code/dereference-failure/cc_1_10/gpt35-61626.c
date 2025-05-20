//FormAI DATASET v1.0 Category: Email Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct for an email
typedef struct email {
    char* sender;
    char* recipient;
    char* subject;
    char* message;
} Email;

// Function to create a new email
Email* create_email(char* from, char* to, char* sub, char* msg) {
    Email* email = malloc(sizeof(Email));
    email->sender = strdup(from);
    email->recipient = strdup(to);
    email->subject = strdup(sub);
    email->message = strdup(msg);
    return email;
}

// Function to print an email
void print_email(Email* email) {
    printf("From: %s\nTo: %s\nSubject: %s\nMessage: %s\n", email->sender, email->recipient, email->subject, email->message);
}

// Function to send an email
void send_email(char* from, char* to, char* sub, char* msg) {
    Email* email = create_email(from, to, sub, msg);
    print_email(email);
    printf("Email sent successfully!\n");
}

// Function to check if a string is a valid email address
bool is_valid_email(char* email) {
    int len = strlen(email);
    bool at_found = false;
    for (int i = 0; i < len; i++) {
        if (email[i] == '@' && !at_found) {
            at_found = true;
            continue;
        }
        if (email[i] == '.' && at_found) return true;
    }
    return false;
}

// Function to prompt the user for an email address
char* get_email(char* prompt) {
    char* email = malloc(sizeof(char) * 100);
    char* format = "%[^\n]%*c";
    do {
        printf("%s", prompt);
        scanf(format, email);
        if (!is_valid_email(email)) printf("Invalid email address!\n");
    } while (!is_valid_email(email));
    return email;
}

int main() {
    char* from = get_email("Enter your email address: ");
    char* to = get_email("Enter the recipient's email address: ");
    char* sub = malloc(sizeof(char) * 100);
    char* msg = malloc(sizeof(char) * 1000);
    printf("Enter the subject: ");
    scanf("%[^\n]%*c", sub);
    printf("Enter your message: ");
    scanf("%[^\n]%*c", msg);
    send_email(from, to, sub, msg);
    free(from);
    free(to);
    free(sub);
    free(msg);
    return 0;
}