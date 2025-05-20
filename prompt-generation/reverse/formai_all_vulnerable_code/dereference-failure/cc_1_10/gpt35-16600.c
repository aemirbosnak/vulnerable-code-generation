//FormAI DATASET v1.0 Category: Mailing list manager ; Style: energetic
/*
  This is a C Mailing list manager program!
  Welcome to the world of efficient emailing.
  
  The program provides features to add new recipients, delete existing ones,
  print mailing lists, and send emails to selected recipients.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* data structure for storing recipient */
struct recipient {
    char name[30];
    char email[50];
    int is_subscribed;
    struct recipient *next;
};

/* function to add a new recipient to the mailing list */
void add_recipient(struct recipient **head_ref) {
    struct recipient *new_recipient = (struct recipient*)malloc(sizeof(struct recipient));
    printf("Enter new recipient's name: ");
    scanf("%s", new_recipient->name);
    printf("Enter new recipient's email: ");
    scanf("%s", new_recipient->email);
    new_recipient->is_subscribed = 1;
    new_recipient->next = NULL;

    /* insert new recipient at the end of the list */
    if (*head_ref == NULL) {
        *head_ref = new_recipient;
    } else {
        struct recipient *temp = *head_ref;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_recipient;
    }

    printf("New recipient added to the mailing list.\n");
}

/* function to delete an existing recipient from the mailing list */
void delete_recipient(struct recipient **head_ref) {
    char email[50];
    printf("Enter email of recipient to delete: ");
    scanf("%s", email);

    /* delete first recipient */
    if (strcmp(email, (*head_ref)->email) == 0) {
        struct recipient *temp = *head_ref;
        *head_ref = (*head_ref)->next;
        free(temp);
        printf("Recipient deleted from mailing list.\n");
        return;
    }

    /* delete other recipients */
    struct recipient *temp1 = *head_ref;
    struct recipient *temp2 = temp1->next;
    while (temp2 != NULL) {
        if (strcmp(email, temp2->email) == 0) {
            temp1->next = temp2->next;
            free(temp2);
            printf("Recipient deleted from mailing list.\n");
            return;
        }
        temp1 = temp2;
        temp2 = temp2->next;
    }

    printf("Recipient not found in mailing list.\n");
}

/* function to print the mailing list */
void print_list(struct recipient *head) {
    if (head == NULL) {
        printf("Mailing list is empty.\n");
        return;
    }
    printf("Mailing list:\n");
    printf("Name\tEmail\tSubscription\n");
    while (head != NULL) {
        printf("%s\t%s\t%d\n", head->name, head->email, head->is_subscribed);
        head = head->next;
    }
}

/* function to send emails to selected recipients */
void send_email(struct recipient *head) {
    int count = 0; /* count selected recipients */
    struct recipient *temp = head;
    while (temp != NULL) {
        if (temp->is_subscribed == 1) {
            count++;
        }
        temp = temp->next;
    }

    if (count == 0) {
        printf("No recipients selected to send email.\n");
        return;
    }

    /* create file for email */
    FILE *fp;
    fp = fopen("email.txt", "w");

    /* print email header */
    fprintf(fp, "To:\n");
    temp = head;
    while (temp != NULL) {
        if (temp->is_subscribed == 1) {
            fprintf(fp, "%s <%s>\n", temp->name, temp->email);
        }
        temp = temp->next;
    }
    fprintf(fp, "Subject: IMPORTANT MESSAGE\n\n");

    /* print email body */
    fprintf(fp, "Dear Recipient,\n\n");
    fprintf(fp, "This is an important message from our organization.\n\n");
    fprintf(fp, "Sincerely,\nManagement\n");

    fclose(fp);

    printf("Email sent to selected recipients.\n");
}

/* main function */
int main() {
    struct recipient *head = NULL;
    int choice;

    while(1) {
        /* display menu */
        printf("\nMenu:\n");
        printf("1. Add recipient to mailing list.\n");
        printf("2. Delete recipient from mailing list.\n");
        printf("3. Print mailing list.\n");
        printf("4. Send email to selected recipients.\n");
        printf("5. Exit program.\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        /* perform selected operation */
        switch(choice) {
            case 1:
                add_recipient(&head);
                break;
            case 2:
                delete_recipient(&head);
                break;
            case 3:
                print_list(head);
                break;
            case 4:
                send_email(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}