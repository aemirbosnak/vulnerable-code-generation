//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct Product {
    char name[50];
    int stock;
    struct Product* next;
} Product;

Product* head = NULL;

void readProducts(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[100];
    Product* current = NULL;

    while (fgets(line, sizeof(line), file)) {
        Product* newProduct = (Product*)malloc(sizeof(Product));
        strcpy(newProduct->name, strtok(line, ":"));
        newProduct->stock = atoi(strtok(NULL, ":"));
        if (head == NULL) {
            head = newProduct;
        } else {
            current->next = newProduct;
        }
        current = newProduct;
    }

    fclose(file);
}

void displayInventory() {
    Product* current = head;
    printf("\nCurrent Inventory:\n");

    while (current != NULL) {
        printf("%s: %d\n", current->name, current->stock);
        current = current->next;
    }
}

void addProduct() {
    Product* newProduct = (Product*)malloc(sizeof(Product));
    printf("Enter product name: ");
    scanf("%s", newProduct->name);
    printf("Enter product stock: ");
    scanf("%d", &newProduct->stock);

    if (head == NULL) {
        head = newProduct;
    } else {
        Product* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newProduct;
    }
}

int main() {
    readProducts("products.txt");
    displayInventory();

    int choice;
    while (1) {
        printf("\n1. Display Inventory\n2. Add Product\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayInventory();
                break;
            case 2:
                addProduct();
                break;
            case 3:
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice!\n");
        }
    }

    while (head != NULL) {
        Product* temp = head;
        head = head->next;
        free(temp);
    }

    return EXIT_SUCCESS;
}