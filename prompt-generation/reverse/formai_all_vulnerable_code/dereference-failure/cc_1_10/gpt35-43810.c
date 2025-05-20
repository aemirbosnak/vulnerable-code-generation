//FormAI DATASET v1.0 Category: Linked list operations ; Style: Claude Shannon
/* 
 * Claude Shannon-inspired program to implement Linked List operations 
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Define the structure of the linked list node, which contains an integer value 
 * and a pointer to next node
 */
typedef struct node {
    int value;
    struct node *next;
} ListNode;

/*
 * Define the LinkedList struct, which contains head and tail pointer of the list
 */
typedef struct {
    ListNode *head;
    ListNode *tail;
} LinkedList;

/*
 * Function to create a new linked list node with given value and next pointer
 */
ListNode* create_node(int value, ListNode* next) {
  ListNode* new_node = (ListNode*) malloc(sizeof(ListNode)); // allocate memory for the new node
  new_node->value = value;
  new_node->next = next;
  return new_node;
}

/*
 * Function to create new Linked List
 */
LinkedList* create_list() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList)); // allocate memory for the new list
    list->head = NULL;
    list->tail = NULL;
    return list;
}

/*
 * Function to insert new node at the front of the list
 */
void insert_front(LinkedList* list, int value) {
    ListNode* new_node = create_node(value, list->head);
    if (!list->tail) {
        list->tail = new_node;
    }
    list->head = new_node;
}

/*
 * Function to insert new node at the end of the list
 */
void insert_end(LinkedList* list, int value) {
    ListNode* new_node = create_node(value, NULL);
    if (!list->head) {
        list->head = new_node;
    }
    if (list->tail) {
        list->tail->next = new_node;
    }
    list->tail = new_node;
}

/*
 * Function to delete the front node of the list
 */
void delete_front(LinkedList* list) {
    if (!list->head) {
        return;
    }
    ListNode* front = list->head;
    list->head = front->next;
    if (!list->head) {
        list->tail = NULL;
    }
    free(front);
}

/*
 * Function to delete the end node of the list
 */
void delete_end(LinkedList* list) {
    if (!list->head) {
        return;
    }
    ListNode* curr = list->head;
    ListNode* prev = NULL;
    while (curr != list->tail) {
        prev = curr;
        curr = curr->next;
    }
    if (prev) {
        prev->next = NULL;
        list->tail = prev;
    } else {
        list->head = NULL;
        list->tail = NULL;
    }
    free(curr);
}

/*
 * Function to print all the elements in the linked list
 */
void print_list(LinkedList* list) {
    ListNode *curr;
    printf("List elements: ");
    for (curr = list->head; curr != NULL; curr = curr->next) {
        printf("%d ", curr->value);
    }
    printf("\n");
}

/*
 * Program entry point
 */
int main() {
    printf("Creating a Linked List with initial values: 2, 4, 6, 8, 10\n");
    LinkedList* list = create_list();
    insert_end(list, 2);
    insert_end(list, 4);
    insert_end(list, 6);
    insert_end(list, 8);
    insert_end(list, 10);
    print_list(list);

    printf("Deleting the front node\n");
    delete_front(list);
    print_list(list);

    printf("Deleting the end node\n");
    delete_end(list);
    print_list(list);

    printf("Inserting new node at the front with value 20\n");
    insert_front(list, 20);
    print_list(list);

    printf("Inserting new node at the end with value 30\n");
    insert_end(list, 30);
    print_list(list);

    return 0;
}