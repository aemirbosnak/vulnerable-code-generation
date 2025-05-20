//FormAI DATASET v1.0 Category: Mailing list manager ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000

// Define a struct to represent an email address
struct email {
    char name[50];
    char address[100];
};

// Define a struct to represent a mailing list
struct mailing_list {
    char name[50];
    struct email emails[MAX_EMAILS];
    int num_emails;
};

// Function to add an email to a mailing list
void add_email(struct mailing_list *list) {
    struct email new_email;

    printf("Enter name: ");
    scanf("%s", new_email.name);

    printf("Enter email address: ");
    scanf("%s", new_email.address);

    if (list->num_emails >= MAX_EMAILS) {
        printf("Error: mailing list is full\n");
        return;
    }

    list->emails[list->num_emails] = new_email;
    list->num_emails++;

    printf("Added email to mailing list\n");
}

// Function to print all emails in a mailing list
void print_emails(struct mailing_list list) {
    printf("Mailing List: %s\n", list.name);

    for (int i = 0; i < list.num_emails; i++) {
        printf("%s <%s>\n", list.emails[i].name, list.emails[i].address);
    }
}

int main() {
    struct mailing_list list = {0};

    printf("Enter name of mailing list: ");
    scanf("%s", list.name);

    printf("Enter number of emails to add: ");
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        add_email(&list);
    }

    print_emails(list);

    return 0;
}