//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: modular
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Spam filter module
int is_spam(char *message) {
    // Spam detection rules
    if (strstr(message, "free") != NULL) return 1;
    if (strstr(message, "win") != NULL) return 1;
    if (strstr(message, "prize") != NULL) return 1;
    if (strstr(message, "click") != NULL) return 1;
    if (strstr(message, "urgent") != NULL) return 1;

    // Not spam
    return 0;
}

// Mailbox module
struct mailbox {
    char **messages;
    int num_messages;
};

void add_message(struct mailbox *mailbox, char *message) {
    // Allocate memory for the new message
    char **new_messages = realloc(mailbox->messages, (mailbox->num_messages + 1) * sizeof(char *));
    if (new_messages == NULL) {
        perror("realloc");
        exit(1);
    }
    mailbox->messages = new_messages;

    // Copy the message into the mailbox
    mailbox->messages[mailbox->num_messages] = strdup(message);
    mailbox->num_messages++;
}

// Display mailbox contents
void print_mailbox(struct mailbox *mailbox) {
    for (int i = 0; i < mailbox->num_messages; i++) {
        printf("%d: %s\n", i + 1, mailbox->messages[i]);
    }
}

// Main program
int main() {
    // Create a mailbox
    struct mailbox mailbox;
    mailbox.messages = NULL;
    mailbox.num_messages = 0;

    // Add some messages to the mailbox
    add_message(&mailbox, "This is a normal message.");
    add_message(&mailbox, "This is a spam message. Click here to win a free prize!");
    add_message(&mailbox, "This is another normal message.");

    // Print the mailbox contents
    print_mailbox(&mailbox);

    // Check for spam in the mailbox
    for (int i = 0; i < mailbox.num_messages; i++) {
        if (is_spam(mailbox.messages[i])) {
            printf("Message %d is spam.\n", i + 1);
        }
    }

    // Free the mailbox memory
    for (int i = 0; i < mailbox.num_messages; i++) {
        free(mailbox.messages[i]);
    }
    free(mailbox.messages);

    return 0;
}