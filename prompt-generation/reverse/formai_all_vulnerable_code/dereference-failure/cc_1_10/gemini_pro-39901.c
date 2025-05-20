//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    char company[50];
    float price;
    int quantity;
};

struct node {
    struct medicine data;
    struct node *next;
};

struct linkedList {
    struct node *head;
};

struct linkedList *createLinkedList() {
    struct linkedList *list = (struct linkedList *)malloc(sizeof(struct linkedList));
    list->head = NULL;
    return list;
}

void insertNode(struct linkedList *list, struct medicine data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        struct node *current_node = list->head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

void deleteNode(struct linkedList *list, char *name) {
    struct node *current_node = list->head;
    struct node *previous_node = NULL;

    while (current_node != NULL) {
        if (strcmp(current_node->data.name, name) == 0) {
            if (previous_node == NULL) {
                list->head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            free(current_node);
            break;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
}

void printLinkedList(struct linkedList *list) {
    struct node *current_node = list->head;
    while (current_node != NULL) {
        printf("%s %s %.2f %d\n", current_node->data.name, current_node->data.company, current_node->data.price, current_node->data.quantity);
        current_node = current_node->next;
    }
}

int main() {
    struct linkedList *list = createLinkedList();

    struct medicine medicine1 = {"Paracetamol", "Cipla", 10.00, 100};
    insertNode(list, medicine1);

    struct medicine medicine2 = {"Ibuprofen", "Advil", 15.00, 50};
    insertNode(list, medicine2);

    struct medicine medicine3 = {"Amoxicillin", "GlaxoSmithKline", 20.00, 25};
    insertNode(list, medicine3);

    printLinkedList(list);

    deleteNode(list, "Ibuprofen");

    printLinkedList(list);

    return 0;
}