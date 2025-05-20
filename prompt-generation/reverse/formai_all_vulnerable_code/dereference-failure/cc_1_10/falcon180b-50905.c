//Falcon-180B DATASET v1.0 Category: Email Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char from[MAX_EMAILS][MAX_EMAILS];
    char subject[MAX_EMAILS][MAX_SUBJECT_LENGTH];
    char body[MAX_EMAILS][MAX_BODY_LENGTH];
    int num_emails;
} EmailBox;

EmailBox* createEmailBox() {
    EmailBox* box = (EmailBox*)malloc(sizeof(EmailBox));
    box->num_emails = 0;
    return box;
}

void addEmail(EmailBox* box, char* from, char* subject, char* body) {
    strcpy(box->from[box->num_emails], from);
    strcpy(box->subject[box->num_emails], subject);
    strcpy(box->body[box->num_emails], body);
    box->num_emails++;
}

void printEmail(EmailBox* box, int index) {
    printf("From: %s\n", box->from[index]);
    printf("Subject: %s\n", box->subject[index]);
    printf("Body:\n%s\n", box->body[index]);
}

int main() {
    EmailBox* box = createEmailBox();
    int choice;
    char from[MAX_EMAILS];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];

    do {
        printf("1. Add email\n");
        printf("2. Print email\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the sender's email address: ");
                scanf("%s", from);
                printf("Enter the subject: ");
                scanf("%s", subject);
                printf("Enter the body of the email:\n");
                fgets(body, MAX_BODY_LENGTH, stdin);
                body[strcspn(body, "\n")] = '\0'; // remove newline character
                addEmail(box, from, subject, body);
                break;
            case 2:
                printf("Enter the index of the email you want to print (0-9): ");
                scanf("%d", &choice);
                if(choice >= 0 && choice < box->num_emails) {
                    printEmail(box, choice);
                }
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 3);

    return 0;
}