//MISTRAL-7B DATASET v1.0 Category: Email Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 500
#define MAX_MAILBOX_SIZE 10

typedef struct Email {
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
    struct Email *next;
} Email;

Email *mailbox[MAX_MAILBOX_SIZE];
int mailbox_size = 0;

void create_email(char *sender, char *subject, char *body) {
    Email *new_email = (Email *) malloc(sizeof(Email));
    strcpy(new_email->subject, subject);
    strcpy(new_email->body, body);
    new_email->next = NULL;

    if (mailbox_size >= MAX_MAILBOX_SIZE) {
        printf("Mailbox is full. Unable to send email.\n");
        free(new_email);
        return;
    }

    mailbox[mailbox_size] = new_email;
    mailbox_size++;
}

void display_mailbox() {
    int i;
    Email *current;

    printf("\nMailbox:\n");
    for (i = 0; i < mailbox_size; i++) {
        current = mailbox[i];
        printf("\nEmail %d:\nSubject: %s\nBody: %s", i+1, current->subject, current->body);
    }
}

void delete_email(int index) {
    if (index < 1 || index > mailbox_size) {
        printf("Invalid index. Unable to delete email.\n");
        return;
    }

    Email *current = mailbox[index-1];
    Email *next = mailbox[index];

    free(next);
    mailbox[index] = current;
    mailbox_size--;
}

int main() {
    char sender[20], subject[MAX_SUBJECT_LEN], body[MAX_BODY_LEN];
    int choice, index;

    while (1) {
        printf("\n1. Create Email\n2. Display Mailbox\n3. Delete Email\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter sender: ");
                scanf("%s", sender);
                printf("Enter subject: ");
                scanf("%s", subject);
                printf("Enter body: ");
                scanf("%[^\n]", body);
                create_email(sender, subject, body);
                break;
            case 2:
                display_mailbox();
                break;
            case 3:
                printf("Enter index of email to delete: ");
                scanf("%d", &index);
                delete_email(index);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}