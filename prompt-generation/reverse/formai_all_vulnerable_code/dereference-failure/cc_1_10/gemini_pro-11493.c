//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: relaxed
// A laid-back C inventory system
// Complete with comments and style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A product struct to hold all our juicy details
typedef struct product {
    int id;
    char* name;
    int quantity;
    float price;
} product;

// A linked list to store our precious products
typedef struct node {
    product data;
    struct node *next;
} node;

// The head of our linked list, the gatekeeper of our inventory
node *head = NULL;

// A friendly function to welcome our users
void welcome() {
    printf("Welcome to the most chill inventory system ever!\n");
    printf("Here, you can add, remove, and check your products at your own pace.\n");
}

// A function to add a new product to our inventory
void add_product() {
    // Create a new product
    product new_product;

    // Get the product details from the user
    printf("Enter product name: ");
    scanf(" %s", new_product.name);  // Use fgets() for strings with spaces
    printf("Enter product quantity: ");
    scanf(" %d", &new_product.quantity);
    printf("Enter product price: ");
    scanf(" %f", &new_product.price);

    // Allocate memory for the product name
    new_product.name = (char*)malloc(strlen(new_product.name) + 1);
    strcpy(new_product.name, new_product.name);

    // Generate a unique ID for the product
    if (head == NULL) {
        new_product.id = 1;
    } else {
        new_product.id = head->data.id + 1;
    }

    // Create a new node for the linked list
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = new_product;
    new_node->next = NULL;

    // Insert the new node at the beginning of the linked list
    if (head == NULL) {
        head = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }

    // Let the user know we've added their product
    printf("Product added successfully!\n");
}

// A function to remove a product from our inventory
void remove_product() {
    // Get the product ID from the user
    int id;
    printf("Enter product ID: ");
    scanf(" %d", &id);

    // Find the product in the linked list
    node *current = head;
    while (current != NULL) {
        if (current->data.id == id) {
            break;
        }
        current = current->next;
    }

    // Check if the product was found
    if (current == NULL) {
        printf("Product not found.\n");
        return;
    }

    // Remove the product from the linked list
    if (current == head) {
        head = head->next;
    } else {
        node *prev = head;
        while (prev->next != current) {
            prev = prev->next;
        }
        prev->next = current->next;
    }

    // Free the memory allocated for the product name
    free(current->data.name);

    // Free the memory allocated for the node
    free(current);

    // Let the user know we've removed their product
    printf("Product removed successfully!\n");
}

// A function to check the quantity of a product in our inventory
void check_quantity() {
    // Get the product ID from the user
    int id;
    printf("Enter product ID: ");
    scanf(" %d", &id);

    // Find the product in the linked list
    node *current = head;
    while (current != NULL) {
        if (current->data.id == id) {
            break;
        }
        current = current->next;
    }

    // Check if the product was found
    if (current == NULL) {
        printf("Product not found.\n");
        return;
    }

    // Display the product quantity
    printf("Product quantity: %d\n", current->data.quantity);
}

// A function to display all the products in our inventory
void display_products() {
    // Check if the inventory is empty
    if (head == NULL) {
        printf("Inventory is empty.\n");
        return;
    }

    // Traverse the linked list and display each product
    node *current = head;
    while (current != NULL) {
        printf("Product ID: %d\n", current->data.id);
        printf("Product Name: %s\n", current->data.name);
        printf("Product Quantity: %d\n", current->data.quantity);
        printf("Product Price: %.2f\n", current->data.price);
        printf("\n");
        current = current->next;
    }
}

// A function to free the memory allocated for the linked list
void free_list() {
    // Traverse the linked list and free each node
    node *current = head;
    while (current != NULL) {
        node *next = current->next;
        free(current->data.name);
        free(current);
        current = next;
    }
}

// The main function where the magic happens
int main() {
    // Welcome the user
    welcome();

    // Main menu loop
    int choice;
    do {
        // Display the menu options
        printf("\nWhat would you like to do?\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Check product quantity\n");
        printf("4. Display all products\n");
        printf("5. Exit\n");

        // Get the user's choice
        scanf(" %d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                check_quantity();
                break;
            case 4:
                display_products();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    // Free the memory allocated for the linked list
    free_list();

    return 0;
}