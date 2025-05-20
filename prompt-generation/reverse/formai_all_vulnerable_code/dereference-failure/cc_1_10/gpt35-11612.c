//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Node {
    struct Product data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(struct Product product) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = product;
    new_node->next = head;
    head = new_node;
}

void display() {
    struct Node* ptr = head;
    printf("\nID\tName\t\tQuantity\tPrice\n");
    while (ptr != NULL) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", ptr->data.id, ptr->data.name, ptr->data.quantity, ptr->data.price);
        ptr = ptr->next;
    }
}

struct Node* search(int id) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        if (ptr->data.id == id) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

void remove_product(int id) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp != NULL && temp->data.id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nProduct not found.\n");
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("\nProduct removed successfully.\n");
}

void update(int id, char name[50], int quantity, float price) {
    struct Node* node = search(id);
    if (node == NULL) {
        printf("\nProduct not found.\n");
        return;
    }
    strncpy(node->data.name, name, sizeof(node->data.name));
    node->data.quantity = quantity;
    node->data.price = price;
    printf("\nProduct updated successfully.\n");
}

void sell(int id, int quantity) {
    struct Node* node = search(id);
    if (node == NULL) {
        printf("\nProduct not found.\n");
        return;
    }
    if (node->data.quantity < quantity) {
        printf("\nNot enough stock available.\n");
        return;
    }
    node->data.quantity -= quantity;
    printf("\nSale complete. Total price: %.2f\n", quantity * node->data.price);
}

int main() {
    int choice, id, quantity;
    char name[50];
    float price;

    do {
        printf("\n\n1. Insert product");
        printf("\n2. Display all products");
        printf("\n3. Search product by ID");
        printf("\n4. Remove product by ID");
        printf("\n5. Update product");
        printf("\n6. Sell product");
        printf("\n7. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter product ID: ");
                scanf("%d", &id);
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                printf("Enter product price: ");
                scanf("%f", &price);
                insert((struct Product) {id, name, quantity, price});
                printf("\nProduct inserted successfully.\n");
                break;
            case 2:
                display();
                break;
            case 3:
                printf("\nEnter product ID: ");
                scanf("%d", &id);
                struct Node* node = search(id);
                if (node == NULL) {
                    printf("\nProduct not found.\n");
                } else {
                    printf("\nID\tName\t\tQuantity\tPrice\n");
                    printf("%d\t%s\t\t%d\t\t%.2f\n", node->data.id, node->data.name, node->data.quantity, node->data.price);
                }
                break;
            case 4:
                printf("\nEnter product ID: ");
                scanf("%d", &id);
                remove_product(id);
                break;
            case 5:
                printf("\nEnter product ID: ");
                scanf("%d", &id);
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                printf("Enter product price: ");
                scanf("%f", &price);
                update(id, name, quantity, price);
                break;
            case 6:
                printf("\nEnter product ID: ");
                scanf("%d", &id);
                printf("Enter quantity to sell: ");
                scanf("%d", &quantity);
                sell(id, quantity);
                break;
            case 7:
                printf("\nExiting program.");
                break;
            default:
                printf("\nInvalid choice. Please try again.");
        }
    } while (choice != 7);

    return 0;
}