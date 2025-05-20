//FormAI DATASET v1.0 Category: Mailing list manager ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mail_node {
    char *mail_address;
    struct mail_node *next;
};

typedef struct mail_node *MailList;

void add_mail(MailList *head, char *mail) {
    MailList new_node = (MailList)malloc(sizeof(struct mail_node));
    new_node->mail_address = (char *)malloc(strlen(mail) + 1);
    strcpy(new_node->mail_address, mail);
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        MailList current = *head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_list(MailList head) {
    if (head == NULL) {
        printf("The mailing list is empty.\n");
    } else {
        printf("Mailing List:\n");
        while (head != NULL) {
            printf("%s\n", head->mail_address);
            head = head->next;
        }
    }
}

void free_list(MailList head) {
    MailList current = head;
    while (current != NULL) {
        MailList temp = current;
        current = current->next;
        free(temp->mail_address);
        free(temp);
    }
}

int main() {
    MailList mailing_list = NULL;

    add_mail(&mailing_list, "john@gmail.com");
    add_mail(&mailing_list, "jane@yahoo.com");
    add_mail(&mailing_list, "jim@hotmail.com");

    print_list(mailing_list);

    free_list(mailing_list);

    return 0;
}