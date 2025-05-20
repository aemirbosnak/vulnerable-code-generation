//FormAI DATASET v1.0 Category: Email Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 500

typedef struct Email {
    char sender[50];
    char receiver[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char date[20];
    char time[20];
} Email;

int main() {
    int option;
    Email *inbox = (Email*) malloc(sizeof(Email));
    int num_emails = 0;

    printf("Welcome to C Email Client!\n");

    while(1) {
        printf("\n\n1. Compose Email\n");
        printf("2. Inbox\n");
        printf("3. Exit\n\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1: {
                char receiver[50];
                char subject[MAX_SUBJECT_LENGTH];
                char body[MAX_BODY_LENGTH];
                printf("Enter receiver email address: ");
                scanf("%s", receiver);
                printf("Enter subject: ");
                fflush(stdin); // clear input buffer
                fgets(subject, MAX_SUBJECT_LENGTH, stdin); // gets the whole line
                printf("Enter body: ");
                fgets(body, MAX_BODY_LENGTH, stdin);
                strcpy((inbox + num_emails)->receiver, receiver);
                strcpy((inbox + num_emails)->subject, subject);
                strcpy((inbox + num_emails)->body, body);
                // You can implement code here to find date and time
                num_emails++;
                printf("Email sent successfully!\n");
                break;
            }
            case 2: {
                if(num_emails == 0) {
                    printf("Inbox empty.\n");
                } else {
                    printf("------ Inbox -------\n");
                    for(int i=0; i<num_emails; i++) {
                        printf("From: %s\n", (inbox + i)->sender);
                        printf("Subject: %s\n", (inbox + i)->subject);
                        printf("Date: %s %s\n", (inbox + i)->date, (inbox + i)->time);
                        printf("--------------------\n");
                        printf("%s\n", (inbox + i)->body);
                        printf("--------------------\n\n");
                    }
                }
                break;
            }
            case 3: {
                printf("Thank you for using C Email Client :)\n");
                free(inbox);
                exit(0);
            }
            default: {
                printf("Invalid option. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}