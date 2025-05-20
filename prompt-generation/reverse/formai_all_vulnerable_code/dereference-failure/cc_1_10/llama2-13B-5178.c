//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global variables
#define MAX_MESSAGE_LENGTH 512
#define MAX_USERNAME_LENGTH 32
#define MAX_PASSWORD_LENGTH 32

// Structure to hold user information
typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} user_info_t;

// Function to print a funny message
void print_funny_message(void) {
    printf("Oh no, it looks like you've accidentally opened an email client! Better call IT support before your boss sees this...\n");
}

// Function to send an email
void send_email(user_info_t *user, char *to, char *subject, char *message) {
    // Generate a random email subject line
    srand(time(NULL));
    subject[0] = 'F';
    subject[1] = 'r';
    subject[2] = 'i';
    subject[3] = 'e';
    subject[4] = 'n';
    subject[5] = 'd';
    subject[6] = 't';
    subject[7] = 'o';
    subject[8] = ' ';
    strcpy(subject + 9, "Email Client Disaster!");

    // Send the email (just kidding, we're not actually sending anything)
    printf("Sending email to %s with subject %s and message %s...\n", to, subject, message);
}

// Function to handle user input
void handle_user_input(user_info_t *user, char *prompt) {
    char input[1024];

    printf("%s: ", prompt);
    fgets(input, 1024, stdin);

    // Trim the input string to remove any whitespace
    char *end = strchr(input, '\n');
    if (end != NULL) {
        *end = '\0';
    }

    // Check if the user entered a valid username and password
    if (strlen(user->username) > 0 && strlen(user->password) > 0) {
        // Print a funny message
        print_funny_message();
    } else {
        printf("Error: Please enter a valid username and password!\n");
    }
}

int main(void) {
    // Create a user structure to hold the user's information
    user_info_t user;

    // Print the email client's splash screen
    printf("Welcome to the funniest email client you'll ever use!\n");
    printf("Please enter your username and password to log in...\n");

    // Handle user input
    handle_user_input(&user, "Username: ");
    handle_user_input(&user, "Password: ");

    // If the user entered a valid username and password, allow them to send an email
    if (strlen(user.username) > 0 && strlen(user.password) > 0) {
        char to[] = "example@example.com";
        char subject[] = "Test email subject";
        char message[] = "This is a test email message";

        send_email(&user, to, subject, message);
    }

    // Print a funny message to wrap things up
    print_funny_message();

    return 0;
}