//FormAI DATASET v1.0 Category: Email Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_INPUT_LEN 1000
#define MAX_EMAILS 100

typedef struct email {
    char* sender;
    char* recipient;
    char* subject;
    char* body;
} Email;

Email emails[MAX_EMAILS]; // declare email array to store emails
int email_index = 0;

void display_menu(); // function prototype

char* read_input(char* prompt) {
    char* input = malloc(sizeof(char) * MAX_INPUT_LEN);
    printf("%s", prompt);
    fgets(input, MAX_INPUT_LEN, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character
    return input;
}

void send_email() {
    printf("\n=== Send Email ===\n");

    char* sender = read_input("From: ");
    char* recipient = read_input("To: ");
    char* subject = read_input("Subject: ");
    char* body = read_input("Body: ");

    // create new email
    Email email = {
        .sender = sender,
        .recipient = recipient,
        .subject = subject,
        .body = body
    };

    // add email to array
    emails[email_index++] = email;

    printf("\nEmail sent successfully!\n");
    display_menu();
}

void view_emails() {
    printf("\n=== View Emails ===\n");

    if (email_index == 0) {
        printf("\nNo emails found.\n");
    } else {
        for (int i = 0; i < email_index; i++) {
            printf("\nEmail #%d\n", i+1);
            printf("From: %s\n", emails[i].sender);
            printf("To: %s\n", emails[i].recipient);
            printf("Subject: %s\n", emails[i].subject);
            printf("Body: %s\n", emails[i].body);
        }
    }
    
    display_menu();
}

void search_emails() {
    printf("\n=== Search Emails ===\n");

    char* keyword = read_input("Enter keyword to search for: ");

    bool found = false;
    for (int i = 0; i < email_index; i++) {
        if (strstr(emails[i].subject, keyword) || strstr(emails[i].body, keyword)) {
            printf("\nEmail #%d\n", i+1);
            printf("From: %s\n", emails[i].sender);
            printf("To: %s\n", emails[i].recipient);
            printf("Subject: %s\n", emails[i].subject);
            printf("Body: %s\n", emails[i].body);
            found = true;
        }
    }

    if (!found) {
        printf("\nNo emails found with that keyword.\n");
    }

    display_menu();
}

void exit_program() {
    printf("\nExiting program.\n");
    exit(0);
}

void display_menu() {
    printf("\nChoose an option:\n");
    printf("1. Send Email\n");
    printf("2. View Emails\n");
    printf("3. Search Emails\n");
    printf("4. Exit\n");

    char* choice = read_input("Enter choice: ");

    switch(atoi(choice)) {
        case 1: send_email(); break;
        case 2: view_emails(); break;
        case 3: search_emails(); break;
        case 4: exit_program(); break;
        default:
            printf("\nInvalid choice. Try again.\n");
            display_menu();
    }
}

int main() {
    display_menu();

    return 0;
}