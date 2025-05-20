//FormAI DATASET v1.0 Category: Email Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJ_LEN 100
#define MAX_BODY_LEN 1000

typedef struct Email {
    char from[50];
    char to[50];
    char subj[MAX_SUBJ_LEN];
    char body[MAX_BODY_LEN];
} Email;

int main() {
    char choice;
    Email *emails = NULL;
    int num_emails = 0;

    do {
        printf("\nC Email Client\n");
        printf("1. Compose Email\n");
        printf("2. View Inbox\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        if (choice == '1') {
            printf("From: ");
            char from[50];
            scanf(" %s", from);

            printf("To: ");
            char to[50];
            scanf(" %s", to);

            Email new_email;
            strcpy(new_email.from, from);
            strcpy(new_email.to, to);

            printf("Subject: ");
            char subj[MAX_SUBJ_LEN];
            scanf(" %[^\n]", subj);
            strcpy(new_email.subj, subj);

            printf("Body: ");
            char body[MAX_BODY_LEN];
            scanf(" %[^\n]", body);
            strcpy(new_email.body, body);

            emails = realloc(emails, (num_emails+1)*sizeof(Email));
            emails[num_emails++] = new_email;

            printf("Email sent!\n");
        }

        else if (choice == '2') {
            if (num_emails == 0) {
                printf("Inbox empty.\n");
                continue;
            }

            printf("Inbox:\n");
            for (int i = 0; i < num_emails; i++) {
                printf("%d. Subject: %s\n", i+1, emails[i].subj);
                printf("   From: %s\n", emails[i].from);
                printf("   To: %s\n", emails[i].to);
                printf("   Body: %s\n", emails[i].body);
            }

            int view_choice;
            printf("Enter email number to view (0 to go back): ");
            scanf(" %d", &view_choice);

            if (view_choice < 1 || view_choice > num_emails) {
                printf("Invalid choice.\n");
                continue;
            }

            printf("Subject: %s\n", emails[view_choice-1].subj);
            printf("From: %s\n", emails[view_choice-1].from);
            printf("To: %s\n", emails[view_choice-1].to);
            printf("Body: %s\n", emails[view_choice-1].body);
        }

        else if (choice != '3') {
            printf("Invalid choice.\n");
        }

    } while (choice != '3');

    printf("Goodbye!\n");
    free(emails);
    return 0;
}