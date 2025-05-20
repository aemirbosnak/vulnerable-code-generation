//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: happy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EMAIL_LEN 100
#define MAX_LIST_SIZE 100

typedef struct {
    char email[MAX_EMAIL_LEN];
    int position;
} MailingList;

MailingList* createMailingList(void) {
    MailingList* list = (MailingList*)malloc(sizeof(MailingList));
    list->position = 0;
    return list;
}

void addEmailToList(MailingList* list, char* email) {
    if (list->position >= MAX_LIST_SIZE) {
        fprintf(stderr, "List is full\n");
        return;
    }
    strcpy(list->email, email);
    list->position++;
}

void displayMailingList(MailingList* list) {
    if (list->position == 0) {
        fprintf(stderr, "List is empty\n");
        return;
    }
    for (int i = 0; i < list->position; i++) {
        printf("%s\n", list->email);
    }
}

void destroyMailingList(MailingList* list) {
    free(list);
}

int main(void) {
    MailingList* list = createMailingList();
    addEmailToList(list, "john@example.com");
    addEmailToList(list, "jane@example.com");
    addEmailToList(list, "john@example.com");
    displayMailingList(list);
    destroyMailingList(list);
    return 0;
}