//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Product {
    char name[50];
    int stock;
    struct Product *next;
} Product;

void generateRandomProduct(Product **head, char *name) {
    Product *newProduct = (Product *) malloc(sizeof(Product));
    strcpy(newProduct->name, name);
    newProduct->stock = rand() % 100 + 1;
    newProduct->next = *head;
    *head = newProduct;
}

void displayInventory(Product *head) {
    Product *current = head;
    printf("\nProduct Inventory:\n");
    while (current != NULL) {
        printf("%s: %d\n", current->name, current->stock);
        current = current->next;
    }
}

void removeProduct(Product **head, char *name) {
    Product *current = *head;
    Product *previous = NULL;

    if (current != NULL && strcmp(current->name, name) == 0) {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Product not found.\n");
        return;
    }

    previous->next = current->next;
    free(current);
}

int main() {
    srand(time(NULL));
    Product *head = NULL;

    generateRandomProduct(&head, "Apple");
    generateRandomProduct(&head, "Banana");
    generateRandomProduct(&head, "Orange");

    displayInventory(head);

    char name[50];
    int choice;

    while (1) {
        printf("\n1. Add product\n2. Remove product\n3. Display inventory\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                generateRandomProduct(&head, name);
                break;
            case 2:
                printf("Enter product name to remove: ");
                scanf("%s", name);
                removeProduct(&head, name);
                break;
            case 3:
                displayInventory(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}