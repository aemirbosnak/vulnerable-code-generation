//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global variables
#define MAX_MESSAGE_LENGTH 512
#define MAX_USERNAME_LENGTH 32
#define MAX_PASSWORD_LENGTH 32

// Struct to hold user information
typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} user_info;

// Function to print a funny message
void print_message(char *message) {
    printf("🐰👋 %s\n", message);
}

// Function to prompt the user for input
void prompt_user(char *prompt) {
    printf("💬 %s: ", prompt);
    fgets(stdin, 1024, stdin);
}

// Function to send an email
void send_email(char *to, char *subject, char *message) {
    // Generate a random email subject line
    char *subject_rand = "🎉 Random email subject! 🎉";
    if (strcmp(subject, "") == 0) {
        subject = subject_rand;
    }

    // Generate a random email message
    char *message_rand = "🐰💬 Random email message! 🐰💬";
    if (strcmp(message, "") == 0) {
        message = message_rand;
    }

    // Send the email (just pretend, of course)
    printf("📧 Sent email to %s with subject %s and message %s\n", to, subject, message);
}

int main() {
    // Initialize the email client
    printf("📧 Welcome to the funny email client! 📧\n");

    // Prompt the user for their username
    prompt_user("Enter your username: ");

    // Get the user's username
    char username[MAX_USERNAME_LENGTH];
    fgets(username, MAX_USERNAME_LENGTH, stdin);

    // Prompt the user for their password
    prompt_user("Enter your password: ");

    // Get the user's password
    char password[MAX_PASSWORD_LENGTH];
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    // Check if the username and password are valid
    if (strcmp(username, "bunny") == 0 && strcmp(password, "carrots") == 0) {
        // Print a funny message
        print_message("🐰👍 You have entered the correct credentials! 🐰👍");
    } else {
        // Print an error message
        print_message("🐰😶 Incorrect credentials! 🐰😶");
    }

    // Prompt the user to send an email
    prompt_user("Enter the recipient's email address: ");

    // Get the recipient's email address
    char to[MAX_USERNAME_LENGTH];
    fgets(to, MAX_USERNAME_LENGTH, stdin);

    // Prompt the user for the email subject and message
    prompt_user("Enter the email subject: ");
    char subject[MAX_USERNAME_LENGTH];
    fgets(subject, MAX_USERNAME_LENGTH, stdin);

    prompt_user("Enter the email message: ");
    char message[MAX_MESSAGE_LENGTH];
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Send the email
    send_email(to, subject, message);

    // Print a final message
    print_message("📧 Email sent! 📧");

    return 0;
}