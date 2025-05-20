//FormAI DATASET v1.0 Category: Email Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct email {
    char from[50];
    char to[50];
    char subject[100];
    char body[500];
};

// Function to read user input
char *read_input(char *prompt) {
    char *input = malloc(255 * sizeof(char));
    printf("%s", prompt);
    scanf("%s", input);
    return input;
}

// Function to create a new email
struct email *create_email() {
    struct email *e = malloc(sizeof(struct email));
    strcpy(e->from, read_input("From: "));
    strcpy(e->to, read_input("To: "));
    strcpy(e->subject, read_input("Subject: "));
    strcpy(e->body, read_input("Body: "));
    return e;
}

// Function to display an email
void display_email(struct email *e) {
    printf("From: %s\n", e->from);
    printf("To: %s\n", e->to);
    printf("Subject: %s\n", e->subject);
    printf("Body: %s\n", e->body);
}

int main() {
    printf("Retro Email Client\n");
    printf("------------------\n");

    // Ask user if they want to create a new email or view an existing one
    char *choice = read_input("Enter 'c' to create a new email or 'v' to view an existing email: ");

    if (strcmp(choice, "c") == 0) {
        // Create a new email
        struct email *new_email = create_email();
        printf("New email created!\n\n");
        display_email(new_email);
    } else if (strcmp(choice, "v") == 0) {
        // View an existing email
        struct email *existing_email = malloc(sizeof(struct email));
        strcpy(existing_email->from, "johndoe@example.com");
        strcpy(existing_email->to, "janedoe@example.com");
        strcpy(existing_email->subject, "Hello from John");
        strcpy(existing_email->body, "Hi Jane, I hope you are doing well!");
        display_email(existing_email);
    } else {
        printf("Unknown option selected.\n");
    }

    return 0;
}