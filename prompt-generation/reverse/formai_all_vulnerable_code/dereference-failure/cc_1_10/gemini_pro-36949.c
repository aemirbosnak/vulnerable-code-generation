//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: curious
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct linked_list {
    struct node *head;
    struct node *tail;
};

// create a new linked list
struct linked_list *create_linked_list() {
    struct linked_list *list = (struct linked_list *)malloc(sizeof(struct linked_list));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// insert a node at the beginning of a linked list
void insert_at_beginning(struct linked_list *list, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }
}

// insert a node at the end of a linked list
void insert_at_end(struct linked_list *list, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (list->tail == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

// insert a node after a given node in a linked list
void insert_after(struct linked_list *list, struct node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    if (prev_node == list->tail) {
        list->tail = new_node;
    }
}

// delete a node from the beginning of a linked list
void delete_at_beginning(struct linked_list *list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = list->head;
    list->head = list->head->next;
    if (list->head == NULL) {
        list->tail = NULL;
    }
    free(temp);
}

// delete a node from the end of a linked list
void delete_at_end(struct linked_list *list) {
    if (list->tail == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = list->head;
    while (temp->next != list->tail) {
        temp = temp->next;
    }
    list->tail = temp;
    temp->next = NULL;
    if (list->head == NULL) {
        list->tail = NULL;
    }
}

// delete a node from a linked list
void delete(struct linked_list *list, struct node *node) {
    if (node == NULL) {
        printf("Node cannot be NULL\n");
        return;
    }
    if (node == list->head) {
        delete_at_beginning(list);
    } else if (node == list->tail) {
        delete_at_end(list);
    } else {
        struct node *temp = list->head;
        while (temp->next != node) {
            temp = temp->next;
        }
        temp->next = node->next;
        free(node);
    }
}

// search for a node in a linked list
struct node *search(struct linked_list *list, int data) {
    struct node *temp = list->head;
    while (temp != NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// print a linked list
void print_linked_list(struct linked_list *list) {
    struct node *temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// free a linked list
void free_linked_list(struct linked_list *list) {
    struct node *temp;
    while (list->head != NULL) {
        temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    free(list);
}

int main() {
    struct linked_list *list = create_linked_list();
    insert_at_beginning(list, 1);
    insert_at_end(list, 2);
    insert_at_end(list, 3);
    insert_at_end(list, 4);
    insert_after(list, list->head->next, 5);
    print_linked_list(list);
    delete_at_beginning(list);
    delete_at_end(list);
    delete(list, list->head->next);
    print_linked_list(list);
    struct node *node = search(list, 3);
    if (node != NULL) {
        printf("Node found: %d\n", node->data);
    } else {
        printf("Node not found\n");
    }
    free_linked_list(list);
    return 0;
}