//FormAI DATASET v1.0 Category: Mailing list manager ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LEN 20
#define MAX_EMAIL_LEN 50

struct contact {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    struct contact *next;
};

void add_contact(struct contact **head_ref, char *name, char *email) {
    struct contact *new_contact = (struct contact *) malloc(sizeof(struct contact));

    if (*head_ref == NULL) { // list is empty
        *head_ref = new_contact;
    } else { // traverse to end of list and insert
        struct contact *temp = *head_ref;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_contact;
    }

    // set the name and email fields
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
}

void print_list(struct contact *head) {
    printf("\nLIST OF CONTACTS:\n");
    while (head != NULL) {
        printf("Name: %s\nEmail: %s\n", head->name, head->email);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct contact *head = NULL;

    // add sample contacts
    add_contact(&head, "Alice", "alice@gmail.com");
    add_contact(&head, "Bob", "bob@yahoo.com");

    // print list of contacts
    print_list(head);

    // add contacts from user input
    char name[MAX_NAME_LEN], email[MAX_EMAIL_LEN];
    printf("Enter name and email (separated by a space), or type 'done' to exit:\n");
    while (1) {
        scanf("%s", name);
        if (strcmp(name, "done") == 0) {
            break;
        }
        scanf("%s", email);
        add_contact(&head, name, email);
    }

    // print updated list of contacts
    print_list(head);

    return 0;
}