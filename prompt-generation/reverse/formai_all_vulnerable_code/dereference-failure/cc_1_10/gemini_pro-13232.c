//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    int quantity;
    float price;
};

struct node {
    struct medicine med;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void add_medicine(char *name, int quantity, float price) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->med.name, name);
    new_node->med.quantity = quantity;
    new_node->med.price = price;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

void display_medicines() {
    struct node *current = head;
    while (current != NULL) {
        printf("%s %d %.2f\n", current->med.name, current->med.quantity, current->med.price);
        current = current->next;
    }
}

void search_medicine(char *name) {
    struct node *current = head;
    while (current != NULL) {
        if (strcmp(current->med.name, name) == 0) {
            printf("%s %d %.2f\n", current->med.name, current->med.quantity, current->med.price);
            return;
        }
        current = current->next;
    }
    printf("Medicine not found.\n");
}

void delete_medicine(char *name) {
    struct node *current = head;
    struct node *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->med.name, name) == 0) {
            if (current == head) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Medicine not found.\n");
}

int main() {
    add_medicine("Paracetamol", 100, 10.00);
    add_medicine("Ibuprofen", 50, 15.00);
    add_medicine("Aspirin", 75, 7.50);
    display_medicines();
    printf("\n");
    search_medicine("Ibuprofen");
    printf("\n");
    delete_medicine("Aspirin");
    display_medicines();
    return 0;
}