//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: all-encompassing
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Data structure to represent a spam filter
typedef struct SpamFilter {
    char *sender_address;
    char *recipient_address;
    char *subject;
    char *body;
    int is_spam;
} SpamFilter;

// Create a new spam filter
SpamFilter* create_spam_filter(char *sender_address, char *recipient_address, char *subject, char *body, int is_spam) {
    SpamFilter *filter = malloc(sizeof(SpamFilter));
    filter->sender_address = strdup(sender_address);
    filter->recipient_address = strdup(recipient_address);
    filter->subject = strdup(subject);
    filter->body = strdup(body);
    filter->is_spam = is_spam;
    return filter;
}

// Free the resources associated with a spam filter
void free_spam_filter(SpamFilter *filter) {
    free(filter->sender_address);
    free(filter->recipient_address);
    free(filter->subject);
    free(filter->body);
    free(filter);
}

// Train the spam filter on a set of emails
void train_spam_filter(SpamFilter *filter, int num_emails, char **emails) {
    for (int i = 0; i < num_emails; i++) {
        char *email = emails[i];
        char *sender_address = strtok(email, " ");
        char *recipient_address = strtok(NULL, " ");
        char *subject = strtok(NULL, " ");
        char *body = strtok(NULL, "");
        int is_spam = (strcmp(body, "SPAM") == 0);
        SpamFilter *new_filter = create_spam_filter(sender_address, recipient_address, subject, body, is_spam);
        filter->is_spam |= new_filter->is_spam;
        free_spam_filter(new_filter);
    }
}

// Test the spam filter on a set of emails
void test_spam_filter(SpamFilter *filter, int num_emails, char **emails) {
    for (int i = 0; i < num_emails; i++) {
        char *email = emails[i];
        char *sender_address = strtok(email, " ");
        char *recipient_address = strtok(NULL, " ");
        char *subject = strtok(NULL, " ");
        char *body = strtok(NULL, "");
        int is_spam = (strcmp(body, "SPAM") == 0);
        SpamFilter *new_filter = create_spam_filter(sender_address, recipient_address, subject, body, is_spam);
        int prediction = filter->is_spam & new_filter->is_spam;
        printf("Email %d: %s\n", i, prediction ? "SPAM" : "NOT SPAM");
        free_spam_filter(new_filter);
    }
}

// Main function
int main() {
    // Create a new spam filter
    SpamFilter *filter = create_spam_filter("", "", "", "", 0);

    // Train the spam filter on a set of emails
    int num_emails = 1000;
    char **emails = malloc(sizeof(char *) * num_emails);
    for (int i = 0; i < num_emails; i++) {
        emails[i] = malloc(1024);
        sprintf(emails[i], "sender%d@example.com recipient%d@example.com subject%d body%d", i, i, i, i);
        if (i % 2 == 0) {
            strcat(emails[i], " SPAM");
        }
    }
    train_spam_filter(filter, num_emails, emails);

    // Test the spam filter on a set of emails
    num_emails = 100;
    emails = malloc(sizeof(char *) * num_emails);
    for (int i = 0; i < num_emails; i++) {
        emails[i] = malloc(1024);
        sprintf(emails[i], "sender%d@example.com recipient%d@example.com subject%d body%d", i, i, i, i);
        if (i % 2 == 0) {
            strcat(emails[i], " SPAM");
        }
    }
    test_spam_filter(filter, num_emails, emails);

    // Free the resources associated with the spam filter
    free_spam_filter(filter);

    // Free the resources associated with the emails
    for (int i = 0; i < num_emails; i++) {
        free(emails[i]);
    }
    free(emails);

    return 0;
}