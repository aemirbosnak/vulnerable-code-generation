//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAILING_LIST_SIZE 100
#define MAX_NAME_LENGTH 50

typedef struct mailing_list {
    char name[MAX_NAME_LENGTH];
    struct mailing_list *next;
} mailing_list_t;

mailing_list_t *head = NULL;

void add_mailing_list(char name[]) {
    mailing_list_t *new_list = (mailing_list_t *)malloc(sizeof(mailing_list_t));
    if (new_list == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(new_list->name, name);
    new_list->next = NULL;
    
    if (head == NULL) {
        head = new_list;
    } else {
        mailing_list_t *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_list;
    }
}

void display_mailing_list() {
    if (head == NULL) {
        printf("Mailing list is empty\n");
        return;
    }
    mailing_list_t *temp = head;
    while (temp!= NULL) {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}

int main() {
    add_mailing_list("John Doe");
    add_mailing_list("Jane Smith");
    add_mailing_list("Mike Johnson");
    display_mailing_list();

    return 0;
}