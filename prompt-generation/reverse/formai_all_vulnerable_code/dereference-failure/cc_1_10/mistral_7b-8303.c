//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LIST_SIZE 100

typedef struct mailing_list {
    char name[50];
    int size;
    struct mail *head;
} mailing_list;

typedef struct mail {
    char to[100];
    char subject[100];
    char message[200];
    struct mail *next;
} mail;

mailing_list x;

void init_list(mailing_list *list) {
    list->size = 0;
    list->head = NULL;
    strcpy(list->name, "My Mailing List");
}

bool is_full(mailing_list *list) {
    return list->size == MAX_LIST_SIZE;
}

void add_mail(mailing_list *list, mail *new_mail) {
    if (is_full(list)) {
        printf("Error: List is full.\n");
        free(new_mail);
        return;
    }

    new_mail->next = list->head;
    list->head = new_mail;
    list->size++;
}

void print_list(mailing_list *list) {
    mail *current = list->head;

    printf("%s Mailing List:\n", list->name);
    printf("--------------------\n");

    while (current != NULL) {
        printf("To: %s\n", current->to);
        printf("Subject: %s\n", current->subject);
        printf("Message: %s\n", current->message);
        printf("--------------------\n");
        current = current->next;
    }
}

int main() {
    mailing_list x;
    mail *new_mail;

    init_list(&x);

    new_mail = (mail *)malloc(sizeof(mail));
    strcpy(new_mail->to, "John Doe <john.doe@example.com>");
    strcpy(new_mail->subject, "Test Email");
    strcpy(new_mail->message, "This is a test email.");

    add_mail(&x, new_mail);

    new_mail = (mail *)malloc(sizeof(mail));
    strcpy(new_mail->to, "Jane Doe <jane.doe@example.com>");
    strcpy(new_mail->subject, "Another Test Email");
    strcpy(new_mail->message, "This is another test email.");

    add_mail(&x, new_mail);

    print_list(&x);

    return 0;
}