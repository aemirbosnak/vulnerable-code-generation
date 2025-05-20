//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

typedef struct {
    char* email;
} Email;

typedef struct {
    Email* emails;
    int num_emails;
} List;

void add_email(List* list, char* email) {
    if (list->num_emails >= MAX_EMAILS) {
        fprintf(stderr, "List is full. Cannot add more emails.\n");
        return;
    }

    Email new_email = {email};
    list->emails = (Email*)realloc(list->emails, (list->num_emails + 1) * sizeof(Email));
    list->emails[list->num_emails] = new_email;
    list->num_emails++;
}

void remove_email(List* list, char* email) {
    for (int i = 0; i < list->num_emails; i++) {
        if (strcmp(list->emails[i].email, email) == 0) {
            for (int j = i; j < list->num_emails - 1; j++) {
                list->emails[j] = list->emails[j + 1];
            }
            list->num_emails--;
            break;
        }
    }
}

void list_emails(List* list) {
    if (list->num_emails == 0) {
        fprintf(stderr, "List is empty.\n");
        return;
    }

    printf("Emails in the list: ");
    for (int i = 0; i < list->num_emails; i++) {
        printf("%s ", list->emails[i].email);
    }
    printf("\n");
}

int main() {
    List list = {0, 0};

    add_email(&list, "user1@example.com");
    add_email(&list, "user2@example.com");
    add_email(&list, "user3@example.com");

    list_emails(&list);

    remove_email(&list, "user2@example.com");

    list_emails(&list);

    return 0;
}