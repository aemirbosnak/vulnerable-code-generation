//FormAI DATASET v1.0 Category: Email Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold email information
struct Email {
    char* sender;
    char** to;
    char* subject;
    char* body;
};

// Function to create and return a new Email
struct Email * createEmail(char* sender, char** to, char* subject, char* body) {
    struct Email *email = (struct Email *)malloc(sizeof(struct Email));
    email->sender = sender;
    email->to = to;
    email->subject = subject;
    email->body = body;
    return email;
}

// Function to print a Email
void printEmail(struct Email * email) {
    printf("Sender: %s\n", email->sender);
    printf("To: ");
    for(int i = 0; email->to[i] != NULL; i++) {
        printf("%s, ", email->to[i]);
    }
    printf("\nSubject: %s\n", email->subject);
    printf("Body: %s\n", email->body);
}

int main() {
    printf("Welcome to our unique C Email Client!\n");

    printf("To send an email, please enter your email information:\n");
    
    char *sender;
    sender = (char *) malloc(255);
    printf("Sender: ");
    fgets(sender, 255, stdin);
    strtok(sender, "\n");

    char *to[10];
    char *toInput;
    toInput = (char *) malloc(255);
    printf("To: ");
    fgets(toInput, 255, stdin);
    if (strstr(toInput, ",") == NULL) {
        to[0] = toInput;
        to[1] = NULL;
    } else {
        char *token = strtok(toInput, ",");
        int i = 0;
        while(token != NULL) {
            to[i] = token;
            token = strtok(NULL, ",");
            i++;
        }
        to[i] = NULL;
    }

    char *subject;
    subject = (char *) malloc(255);
    printf("Subject: ");
    fgets(subject, 255, stdin);
    strtok(subject, "\n");

    char *body;
    body = (char *) malloc(255);
    printf("Body: ");
    fgets(body, 255, stdin);
    strtok(body, "\n");
    
    struct Email *email = createEmail(sender, to, subject, body);
    printf("\nYour email information:\n");
    printEmail(email);
    printf("Email sent successfully!\n");
    return 0;
}