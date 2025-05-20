//FormAI DATASET v1.0 Category: Data structures visualization ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    int size;
} LinkedList;

void insert_beg(LinkedList *list, int data);
void insert_end(LinkedList *list, int data);
void insert_pos(LinkedList *list, int data, int pos);
void delete_beg(LinkedList *list);
void delete_end(LinkedList *list);
void delete_pos(LinkedList *list, int pos);
void print_list(LinkedList *list);

int main() {
    LinkedList list;
    list.head = NULL;
    list.size = 0;

    insert_beg(&list, 2);
    printf("List after inserting 2 at the beginning: ");
    print_list(&list);

    insert_end(&list, 5);
    printf("List after inserting 5 at the end: ");
    print_list(&list);

    insert_pos(&list, 3, 1);
    printf("List after inserting 3 at position 1: ");
    print_list(&list);

    delete_beg(&list);
    printf("List after deleting the first element: ");
    print_list(&list);

    delete_end(&list);
    printf("List after deleting the last element: ");
    print_list(&list);

    delete_pos(&list, 1);
    printf("List after deleting the element at position 1: ");
    print_list(&list);

    return 0;
}

void insert_beg(LinkedList *list, int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void insert_end(LinkedList *list, int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node *curr = list->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
    list->size++;
}

void insert_pos(LinkedList *list, int data, int pos) {
    if (pos < 0 || pos > list->size) {
        printf("Invalid position");
        return;
    }
    if (pos == 0) {
        insert_beg(list, data);
    } else if (pos == list->size) {
        insert_end(list, data);
    } else {
        Node *new_node = (Node *) malloc(sizeof(Node));
        new_node->data = data;
        Node *curr = list->head;
        for (int i = 0; i < pos-1; i++) {
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next = new_node;
        list->size++;
    }
}

void delete_beg(LinkedList *list) {
    if (list->head == NULL) {
        printf("List is empty");
        return;
    }
    Node *to_delete = list->head;
    list->head = list->head->next;
    free(to_delete);
    list->size--;
}

void delete_end(LinkedList *list) {
    if (list->head == NULL) {
        printf("List is empty");
        return;
    }
    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        list->size--;
        return;
    }
    Node *curr = list->head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
    list->size--;
}

void delete_pos(LinkedList *list, int pos) {
    if (pos < 0 || pos >= list->size) {
        printf("Invalid position");
        return;
    }
    if (pos == 0) {
        delete_beg(list);
    } else if (pos == list->size-1) {
        delete_end(list);
    } else {
        Node *to_delete = list->head;
        for (int i = 0; i < pos-1; i++) {
            to_delete = to_delete->next;
        }
        Node *temp = to_delete->next;
        to_delete->next = temp->next;
        free(temp);
        list->size--;
    }
}

void print_list(LinkedList *list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *curr = list->head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}