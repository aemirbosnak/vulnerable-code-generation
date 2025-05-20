//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    struct node* next;
} node;

typedef struct {
    node* head;
    int size;
} linkedlist;

linkedlist* create_linkedlist() {
    linkedlist* newlist = (linkedlist*)malloc(sizeof(linkedlist));
    newlist->head = NULL;
    newlist->size = 0;
    return newlist;
}

void add_node(linkedlist* list, int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if (list->head == NULL) {
        list->head = newnode;
    } else {
        node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    list->size++;
}

void print_linkedlist(linkedlist* list) {
    node* temp = list->head;
    printf("Linked List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete_node(linkedlist* list, int data) {
    node* prev = NULL;
    node* curr = list->head;
    while (curr!= NULL && curr->data!= data) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Node not found.\n");
    } else {
        if (prev == NULL) {
            list->head = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);
        list->size--;
        printf("Node deleted successfully.\n");
    }
}

int main() {
    srand(time(0));
    linkedlist* list = create_linkedlist();

    for (int i = 0; i < 10; i++) {
        int random_data = rand() % MAX_SIZE;
        add_node(list, random_data);
    }

    printf("Initial Linked List:\n");
    print_linkedlist(list);

    int search_data = rand() % MAX_SIZE;
    delete_node(list, search_data);

    printf("Linked List after deleting %d:\n", search_data);
    print_linkedlist(list);

    return 0;
}