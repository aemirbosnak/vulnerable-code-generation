//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 50

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Item;

typedef struct Node {
    Item data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *current = NULL;
Node *temp = NULL;

void initialize() {
    head = NULL;
}

void addItem(char *name, int quantity) {
    if (head == NULL) {
        head = (Node *) malloc(sizeof(Node));
        strcpy(head->data.name, name);
        head->data.quantity = quantity;
        head->next = NULL;
        current = head;
    } else {
        temp = (Node *) malloc(sizeof(Node));
        strcpy(temp->data.name, name);
        temp->data.quantity = quantity;
        temp->next = head;
        current->next = temp;
        current = temp;
    }
}

void display() {
    if (head == NULL) {
        printf("Warehouse is empty!\n");
    } else {
        printf("\nName\tQuantity\n");
        current = head;
        while (current != NULL) {
            printf("%s\t%d\n", current->data.name, current->data.quantity);
            current = current->next;
        }
    }
}

void searchItem(char *name) {
    int found = 0;
    current = head;
    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            found = 1;
            printf("Item '%s' found with quantity %d.\n", name, current->data.quantity);
            break;
        }
        current = current->next;
    }
    if (found == 0) {
        printf("Item '%s' not found!\n", name);
    }
}

void removeItem(char *name) {
    if (head == NULL) {
        printf("Warehouse is empty!\n");
        return;
    }
    if (strcmp(head->data.name, name) == 0) {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }
    current = head;
    while (current->next != NULL && strcmp(current->next->data.name, name) != 0) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Item '%s' not found!\n", name);
        return;
    }
    temp = current->next;
    current->next = current->next->next;
    free(temp);
}

int main() {
    char name[MAX_NAME_LEN];
    int choice, quantity;
    int exit = 0;

    initialize();

    while (exit == 0) {
        printf("\n1. Add Item\n2. Display Items\n3. Search Item\n4. Remove Item\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Item Name: ");
                scanf("%s", name);
                printf("Enter Quantity: ");
                scanf("%d", &quantity);
                addItem(name, quantity);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter Item Name to search: ");
                scanf("%s", name);
                searchItem(name);
                break;
            case 4:
                printf("Enter Item Name to remove: ");
                scanf("%s", name);
                removeItem(name);
                break;
            case 5:
                exit = 1;
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}