//FormAI DATASET v1.0 Category: Mailing list manager ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a maximum length for the email addresses */
#define MAX_EMAIL_LENGTH 100

/* Define a structure for the mailing list */
typedef struct mailing_list {
    char email[MAX_EMAIL_LENGTH];
    struct mailing_list* next;
} MailingList;

/* Function to add a new email address to the mailing list */
void add_email(MailingList** mailing_list_ptr, char* email) {
    /* Allocate memory for a new node */
    MailingList* new_node = (MailingList*) malloc(sizeof(MailingList));

    /* Copy the email address into the new node */
    strncpy(new_node->email, email, MAX_EMAIL_LENGTH);

    /* Set the next pointer to NULL */
    new_node->next = NULL;

    /* If the mailing list is empty, set the head pointer to point to the new node */
    if (*mailing_list_ptr == NULL) {
        *mailing_list_ptr = new_node;
    }
    /* Otherwise, traverse the list and add the new node to the end */
    else {
        MailingList* current_node = *mailing_list_ptr;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

/* Function to remove an email address from the mailing list */
void remove_email(MailingList** mailing_list_ptr, char* email) {
    /* If the mailing list is empty, there's nothing to remove */
    if (*mailing_list_ptr == NULL) {
        return;
    }

    /* If the email address to remove is at the head of the list */
    if (strncmp((*mailing_list_ptr)->email, email, MAX_EMAIL_LENGTH) == 0) {
        MailingList* old_node = *mailing_list_ptr;
        *mailing_list_ptr = (*mailing_list_ptr)->next;
        free(old_node);
        return;
    }

    /* Otherwise, traverse the list and remove the email address */
    MailingList* current_node = *mailing_list_ptr;
    while (current_node->next != NULL) {
        if (strncmp(current_node->next->email, email, MAX_EMAIL_LENGTH) == 0) {
            MailingList* old_node = current_node->next;
            current_node->next = old_node->next;
            free(old_node);
            return;
        }
        current_node = current_node->next;
    }
}

/* Function to print the email addresses in the mailing list */
void print_mailing_list(MailingList* mailing_list) {
    printf("Mailing List:\n");
    while (mailing_list != NULL) {
        printf("%s\n", mailing_list->email);
        mailing_list = mailing_list->next;
    }
}

/* Main function */
int main() {
    /* Initialize the mailing list to empty */
    MailingList* mailing_list = NULL;

    /* Add some email addresses to the list */
    add_email(&mailing_list, "alice@example.com");
    add_email(&mailing_list, "bob@example.com");
    add_email(&mailing_list, "charlie@example.com");

    /* Print the mailing list */
    print_mailing_list(mailing_list);

    /* Remove an email address from the list */
    remove_email(&mailing_list, "bob@example.com");

    /* Print the updated mailing list */
    print_mailing_list(mailing_list);

    /* Free memory for the mailing list */
    while (mailing_list != NULL) {
        MailingList* old_node = mailing_list;
        mailing_list = mailing_list->next;
        free(old_node);
    }

    return 0;
}