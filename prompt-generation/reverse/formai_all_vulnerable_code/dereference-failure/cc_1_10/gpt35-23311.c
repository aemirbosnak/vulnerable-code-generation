//FormAI DATASET v1.0 Category: Email Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 4096

struct email {
    char* from;
    char* to;
    char* subject;
    char* body;
};

void send_email(char* server, struct email email) {
    printf("Connecting to %s...\n", server);
    printf("From: %s\n", email.from);
    printf("To: %s\n", email.to);
    printf("Subject: %s\n", email.subject);
    printf("Body: %s\n", email.body);
    printf("Sending email...\n");
    printf("Email sent!\n");
}

void receive_email(char* server) {
    printf("Connecting to %s...\n", server);
    printf("Checking for new emails...\n");
    printf("No new emails found.\n");
}

void print_help() {
    printf("Available commands:\n");
    printf("  send <recipient> <subject> <body> - send an email\n");
    printf("  receive - check for new emails\n");
    printf("  help - show this help message\n");
    printf("  exit - exit the email client\n");
}

int main(int argc, char** argv) {
    char input[MAX_INPUT];
    struct email current_email = { NULL, NULL, NULL, NULL };

    printf("Welcome to the Linus Torvalds Email Client!\n");
    printf("Type 'help' for a list of available commands.\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_INPUT, stdin);
        input[strcspn(input, "\n")] = '\0'; // remove trailing newline
        char* token = strtok(input, " ");

        if (strcmp(token, "send") == 0) {
            char* recipient = strtok(NULL, " ");
            char* subject = strtok(NULL, " ");
            char* body = strtok(NULL, "");
            if (recipient == NULL || subject == NULL || body == NULL) {
                printf("Usage: send <recipient> <subject> <body>\n");
            } else {
                if (current_email.from != NULL) {
                    free(current_email.from);
                }
                if (current_email.to != NULL) {
                    free(current_email.to);
                }
                if (current_email.subject != NULL) {
                    free(current_email.subject);
                }
                if (current_email.body != NULL) {
                    free(current_email.body);
                }
                current_email.from = strdup("linus@torvalds.com");
                current_email.to = strdup(recipient);
                current_email.subject = strdup(subject);
                current_email.body = strdup(body);
                send_email("smtp.example.com", current_email);
            }
        } else if (strcmp(token, "receive") == 0) {
            receive_email("imap.example.com");
        } else if (strcmp(token, "help") == 0) {
            print_help();
        } else if (strcmp(token, "exit") == 0) {
            if (current_email.from != NULL) {
                free(current_email.from);
            }
            if (current_email.to != NULL) {
                free(current_email.to);
            }
            if (current_email.subject != NULL) {
                free(current_email.subject);
            }
            if (current_email.body != NULL) {
                free(current_email.body);
            }
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Unknown command. Type 'help' for a list of available commands.\n");
        }
    }
    
    return 0;
}