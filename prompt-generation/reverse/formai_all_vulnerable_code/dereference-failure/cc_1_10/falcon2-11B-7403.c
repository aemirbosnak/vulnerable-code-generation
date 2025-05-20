//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char subject[50];
    char sender[50];
    char content[1000];
    struct node *next, *prev;
} Email;

typedef struct {
    Email *first, *last;
} EmailList;

EmailList createEmailList() {
    EmailList list;
    list.first = NULL;
    list.last = NULL;
    return list;
}

void addEmail(EmailList *list, char *subject, char *sender, char *content) {
    Email *newEmail = (Email*)malloc(sizeof(Email));
    strcpy(newEmail->subject, subject);
    strcpy(newEmail->sender, sender);
    strcpy(newEmail->content, content);
    newEmail->next = NULL;
    newEmail->prev = NULL;

    if (list->first == NULL) {
        list->first = newEmail;
        list->last = newEmail;
    } else {
        list->last->next = newEmail;
        newEmail->prev = list->last;
        list->last = newEmail;
    }
}

void printEmailList(EmailList *list) {
    Email *current = list->first;
    while (current!= NULL) {
        printf("%s - %s\n", current->subject, current->sender);
        current = current->next;
    }
}

void sendEmail(EmailList *list, char *subject, char *sender, char *content) {
    Email *newEmail = (Email*)malloc(sizeof(Email));
    strcpy(newEmail->subject, subject);
    strcpy(newEmail->sender, sender);
    strcpy(newEmail->content, content);
    newEmail->next = NULL;
    newEmail->prev = NULL;

    addEmail(list, subject, sender, content);
}

void receiveEmail(EmailList *list, char *subject, char *sender, char *content) {
    Email *newEmail = (Email*)malloc(sizeof(Email));
    strcpy(newEmail->subject, subject);
    strcpy(newEmail->sender, sender);
    strcpy(newEmail->content, content);
    newEmail->next = NULL;
    newEmail->prev = NULL;

    addEmail(list, subject, sender, content);
}

int main() {
    EmailList list = createEmailList();
    sendEmail(&list, "Hello", "John Doe", "This is a test email");
    receiveEmail(&list, "Reply", "Jane Doe", "This is a reply to your test email");

    printEmailList(&list);

    return 0;
}