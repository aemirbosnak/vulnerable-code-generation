//FormAI DATASET v1.0 Category: Email Client ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MESSAGES 100
#define MAX_SUBJECT_LEN 50
#define MAX_BODY_LEN 500
#define MAX_EMAIL_LEN 30

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
    char email_to[MAX_EMAIL_LEN];
    char email_from[MAX_EMAIL_LEN];
} Email;

Email *inbox[MAX_MESSAGES];
int num_msgs = 0;

void display_menu() {
    printf("1. Compose Email\n");
    printf("2. View Inbox\n");
    printf("3. Exit\n");
}

void compose_email() {
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
    char email_to[MAX_EMAIL_LEN];
    char email_from[MAX_EMAIL_LEN];

    printf("Enter recipient email address: ");
    scanf("%s", email_to);
    printf("Enter your email address: ");
    scanf("%s", email_from);

    printf("Enter email subject: ");
    scanf("%s", subject);

    printf("Enter email body (max 500 characters):\n");
    getchar();
    fgets(body, MAX_BODY_LEN, stdin);

    Email *new_email = (Email *) malloc(sizeof(Email));
    strcpy(new_email->email_to, email_to);
    strcpy(new_email->email_from, email_from);
    strcpy(new_email->subject, subject);
    strcpy(new_email->body, body);

    inbox[num_msgs++] = new_email;

    printf("\nEmail sent successfully.\n");
}

void print_email(Email *email) {
    printf("From: %s\n", email->email_from);
    printf("To: %s\n", email->email_to);
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n\n", email->body);
}

void view_inbox() {
    if (num_msgs == 0) {
        printf("\nNo messages in inbox.\n");
        return;
    }

    for (int i = 0; i < num_msgs; i++) {
        print_email(inbox[i]);
    }
}

int main() {
    int choice = 0;

    while(choice != 3) {
        display_menu();

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                compose_email();
                break;
            case 2:
                view_inbox();
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid input.\n");
                break;
        }
    }

    return 0;
}