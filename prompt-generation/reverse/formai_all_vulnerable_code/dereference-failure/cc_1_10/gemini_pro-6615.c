//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: single-threaded
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Declare a struct to represent an email message
struct email_message {
    char *sender;
    char *subject;
    char *body;
};

// Create a new email message
struct email_message *new_email_message(char *sender, char *subject, char *body) {
    struct email_message *msg = malloc(sizeof(struct email_message));
    msg->sender = strdup(sender);
    msg->subject = strdup(subject);
    msg->body = strdup(body);
    return msg;
}

// Free an email message
void free_email_message(struct email_message *msg) {
    free(msg->sender);
    free(msg->subject);
    free(msg->body);
    free(msg);
}

// Check if an email message is spam
int is_spam(struct email_message *msg) {
    // Check the sender's email address
    if (strstr(msg->sender, "@spam.com") != NULL) {
        return 1;
    }

    // Check the subject line for spammy keywords
    if (strstr(msg->subject, "Free") != NULL ||
        strstr(msg->subject, "Viagra") != NULL ||
        strstr(msg->subject, "Lottery") != NULL) {
        return 1;
    }

    // Check the body of the message for spammy keywords
    if (strstr(msg->body, "Click here") != NULL ||
        strstr(msg->body, "Unsubscribe") != NULL ||
        strstr(msg->body, "Nigerian prince") != NULL) {
        return 1;
    }

    // If none of the above checks are met, the message is not spam
    return 0;
}

// Main function
int main() {
    // Create an email message
    struct email_message *msg = new_email_message("spammer@spam.com", "Get rich quick!", "Click here to claim your free money!");

    // Check if the message is spam
    int is_spam_result = is_spam(msg);

    // Print the result
    if (is_spam_result) {
        printf("The message is spam.\n");
    } else {
        printf("The message is not spam.\n");
    }

    // Free the email message
    free_email_message(msg);

    return 0;
}