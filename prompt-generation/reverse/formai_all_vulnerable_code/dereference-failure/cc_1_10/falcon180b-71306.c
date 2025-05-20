//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAILS_PER_RECIPIENT 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    int num_emails;
    struct email_list *emails;
} recipient_t;

typedef struct email_list {
    char email[MAX_NAME_LENGTH];
    struct email_list *next;
} email_list_t;

void add_email(recipient_t *recipient) {
    email_list_t *new_email = malloc(sizeof(email_list_t));

    if (new_email == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    strcpy(new_email->email, recipient->email);
    new_email->next = recipient->emails;
    recipient->emails = new_email;
    recipient->num_emails++;
}

void print_recipient(recipient_t *recipient) {
    printf("Name: %s\n", recipient->name);
    printf("Email: %s\n", recipient->email);
    printf("Number of emails: %d\n", recipient->num_emails);

    email_list_t *current_email = recipient->emails;
    while (current_email!= NULL) {
        printf("  Email: %s\n", current_email->email);
        current_email = current_email->next;
    }
}

int main() {
    recipient_t *recipient_list = malloc(sizeof(recipient_t));

    if (recipient_list == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    strcpy(recipient_list->name, "John Doe");
    strcpy(recipient_list->email, "johndoe@example.com");
    recipient_list->num_emails = 0;
    recipient_list->emails = NULL;

    add_email(recipient_list);
    add_email(recipient_list);
    add_email(recipient_list);

    print_recipient(recipient_list);

    return 0;
}