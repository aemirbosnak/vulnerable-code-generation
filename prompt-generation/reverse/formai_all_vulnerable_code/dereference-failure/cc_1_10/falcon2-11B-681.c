//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char email[100];
    char address[100];
} Person;

typedef struct {
    Person* person;
    struct MailingList* next;
} MailingListNode;

typedef struct {
    MailingListNode* head;
    int size;
} MailingList;

void add_person(MailingList* list, const char* name, const char* email, const char* address) {
    Person* new_person = (Person*) malloc(sizeof(Person));
    strcpy(new_person->name, name);
    strcpy(new_person->email, email);
    strcpy(new_person->address, address);
    MailingListNode* new_node = (MailingListNode*) malloc(sizeof(MailingListNode));
    new_node->person = new_person;
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        MailingListNode* current = list->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    list->size++;
}

void remove_person(MailingList* list, const char* name) {
    MailingListNode* current = list->head;
    while (current!= NULL) {
        if (strcmp(current->person->name, name) == 0) {
            if (current == list->head) {
                list->head = current->next;
            } else {
                MailingListNode* previous = list->head;
                while (previous->next!= current) {
                    previous = previous->next;
                }
                previous->next = current->next;
            }
            free(current->person);
            free(current);
            list->size--;
            break;
        }
        current = current->next;
    }
}

void print_list(MailingList* list) {
    MailingListNode* current = list->head;
    while (current!= NULL) {
        printf("%s (%s) - %s\n", current->person->name, current->person->email, current->person->address);
        current = current->next;
    }
}

int main() {
    MailingList* list = (MailingList*) malloc(sizeof(MailingList));
    list->head = NULL;
    list->size = 0;

    add_person(list, "Alice", "alice@example.com", "123 Main St");
    add_person(list, "Bob", "bob@example.com", "456 Oak St");
    add_person(list, "Charlie", "charlie@example.com", "789 Maple St");

    print_list(list);

    remove_person(list, "Alice");

    print_list(list);

    free(list);
    return 0;
}