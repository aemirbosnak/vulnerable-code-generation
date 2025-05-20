//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL 100
#define MAX_LIST 100

typedef struct {
    char name[MAX_EMAIL];
    char email[MAX_EMAIL];
    struct ListNode *next;
} ListNode;

typedef struct {
    ListNode *head;
    ListNode *tail;
} List;

List* createList() {
    List* list = malloc(sizeof(List));
    if (list == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for list\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void addEmail(List* list, char* email) {
    ListNode* node = malloc(sizeof(ListNode));
    if (node == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for node\n");
        exit(EXIT_FAILURE);
    }
    strcpy(node->name, "Unknown");
    strcpy(node->email, email);
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

void displayList(List* list) {
    ListNode* current = list->head;
    while (current!= NULL) {
        printf("%s - %s\n", current->name, current->email);
        current = current->next;
    }
}

int main() {
    List* list = createList();
    addEmail(list, "john.doe@example.com");
    addEmail(list, "jane.doe@example.com");
    addEmail(list, "jake.doe@example.com");
    displayList(list);
    return 0;
}