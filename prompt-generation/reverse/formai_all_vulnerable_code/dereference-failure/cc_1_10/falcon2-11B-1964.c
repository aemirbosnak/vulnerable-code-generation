//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_EMAIL_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct list_node *next;
} list_node;

typedef struct {
    list_node *head;
    list_node *tail;
} list;

typedef struct {
    list *list;
    int size;
} mailing_list;

void add_email(mailing_list *list, char *name, char *email) {
    list_node *new_node = (list_node *)malloc(sizeof(list_node));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->next = NULL;

    if (list->list->tail == NULL) {
        list->list->head = new_node;
        list->list->tail = new_node;
    } else {
        list->list->tail->next = new_node;
        list->list->tail = new_node;
    }
    list->size++;
}

void display_emails(mailing_list *list) {
    list_node *current = list->list->head;

    printf("List of emails:\n");
    while (current!= NULL) {
        printf("%s - %s\n", current->name, current->email);
        current = current->next;
    }
}

void free_mailing_list(mailing_list *list) {
    list_node *current = list->list->head;

    while (current!= NULL) {
        list_node *next = current->next;
        free(current);
        current = next;
    }
    list->size = 0;
    free(list->list);
    list->list = NULL;
}

int main() {
    mailing_list list;
    list.list = NULL;
    list.size = 0;

    char name[MAX_EMAIL_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your email: ");
    scanf("%s", email);

    add_email(&list, name, email);

    display_emails(&list);

    free_mailing_list(&list);

    return 0;
}