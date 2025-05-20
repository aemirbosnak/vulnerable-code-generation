//FormAI DATASET v1.0 Category: Email Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENDS 1000
#define MAX_SIZE 100

struct Email {
    char sender[MAX_SIZE];
    char recipient[MAX_SIZE];
    char subject[MAX_SIZE];
    char message[MAX_SIZE];
};

int main() {
    struct Email sent[MAX_SENDS];
    int numSent = 0;
    char command[MAX_SIZE];
    printf("Welcome to Baker Street Email Client. How can I assist you? \n");

    while (1) {
        printf(">");
        fgets(command, MAX_SIZE, stdin);

        char* tokens = strtok(command, " \n");

        if (strcmp(tokens, "send") == 0) {
            struct Email e;
            printf("To: ");
            fgets(e.recipient, MAX_SIZE, stdin);
            printf("From: ");
            fgets(e.sender, MAX_SIZE, stdin);
            printf("Subject: ");
            fgets(e.subject, MAX_SIZE, stdin);
            printf("Message: ");
            fgets(e.message, MAX_SIZE, stdin);

            sent[numSent++] = e;
            printf("Your email has successfully been sent from %s to %s. \n", e.sender, e.recipient);
        } else if (strcmp(tokens, "list") == 0) {
            for (int i = 0; i < numSent; i++) {
                printf("Sender: %s, Recipient: %s, Subject: %s\n", sent[i].sender, sent[i].recipient, sent[i].subject);
            }
            printf("You have %d email(s) in your sent folder. \n", numSent);
        } else if (strcmp(tokens, "exit") == 0) {
            printf("Goodbye! \n");
            exit(0);
        } else {
            printf("I'm sorry, I do not understand your command. Please try again. \n");
        }
    }
    
    return 0;
}