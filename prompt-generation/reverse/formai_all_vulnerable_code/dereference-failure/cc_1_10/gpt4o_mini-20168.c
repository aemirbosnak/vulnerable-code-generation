//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50

// Define the Product structure
typedef struct Product {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
    struct Product* next; // Pointer to the next product
} Product;

// Function prototypes
Product* createProduct(int id, const char* name, int quantity, float price);
void addProduct(Product** head, int id, const char* name, int quantity, float price);
void removeProduct(Product** head, int id);
void viewInventory(Product* head);
void freeInventory(Product* head);

int main() {
    Product* inventory = NULL;
    int choice, id, quantity;
    float price;
    char name[NAME_LENGTH];

    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. View Inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter product ID: ");
                scanf("%d", &id);
                printf("Enter product name: ");
                scanf(" %[^\n]s", name); // Read a string with spaces
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                addProduct(&inventory, id, name, quantity, price);
                break;

            case 2:
                printf("Enter product ID to remove: ");
                scanf("%d", &id);
                removeProduct(&inventory, id);
                break;

            case 3:
                viewInventory(inventory);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);

    // Free the allocated memory before exit
    freeInventory(inventory);
    return 0;
}

// Function to create a new product
Product* createProduct(int id, const char* name, int quantity, float price) {
    Product* newProduct = (Product*)malloc(sizeof(Product));
    newProduct->id = id;
    strcpy(newProduct->name, name);
    newProduct->quantity = quantity;
    newProduct->price = price;
    newProduct->next = NULL;
    return newProduct;
}

// Function to add product to the inventory
void addProduct(Product** head, int id, const char* name, int quantity, float price) {
    Product* newProduct = createProduct(id, name, quantity, price);
    newProduct->next = *head; // Insert at the beginning
    *head = newProduct;
    printf("Product '%s' added successfully!\n", name);
}

// Function to remove a product from the inventory
void removeProduct(Product** head, int id) {
    Product* current = *head;
    Product* previous = NULL;

    while(current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }

    if(current == NULL) {
        printf("Product with ID %d not found.\n", id);
        return;
    }

    if(previous == NULL) {
        *head = current->next; // Remove from the beginning
    } else {
        previous->next = current->next; // Remove from the middle or end
    }
    free(current); // Free allocated memory
    printf("Product with ID %d removed successfully!\n", id);
}

// Function to view current inventory
void viewInventory(Product* head) {
    Product* current = head;
    printf("\nCurrent Inventory:\n");
    printf("%-8s %-30s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("---------------------------------------------------------\n");
    while(current != NULL) {
        printf("%-8d %-30s %-10d $%-9.2f\n", current->id, current->name, current->quantity, current->price);
        current = current->next;
    }
}

// Function to free the allocated memory for the inventory
void freeInventory(Product* head) {
    Product* current = head;
    Product* nextProduct;

    while(current != NULL) {
        nextProduct = current->next;
        free(current);
        current = nextProduct;
    }
}