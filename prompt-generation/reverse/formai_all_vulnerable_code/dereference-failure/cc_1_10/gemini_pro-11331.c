//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    float price;
    int quantity;
};

struct node {
    struct medicine med;
    struct node *next;
};

struct node *head = NULL;

void add_medicine(char *name, float price, int quantity) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->med.name, name);
    new_node->med.price = price;
    new_node->med.quantity = quantity;
    new_node->next = head;
    head = new_node;
}

void display_medicines() {
    struct node *current = head;
    while (current != NULL) {
        printf("%s\t%.2f\t%d\n", current->med.name, current->med.price, current->med.quantity);
        current = current->next;
    }
}

void search_medicine(char *name) {
    struct node *current = head;
    while (current != NULL) {
        if (strcmp(current->med.name, name) == 0) {
            printf("%s\t%.2f\t%d\n", current->med.name, current->med.price, current->med.quantity);
            return;
        }
        current = current->next;
    }
    printf("Medicine not found!\n");
}

void update_medicine(char *name, float price, int quantity) {
    struct node *current = head;
    while (current != NULL) {
        if (strcmp(current->med.name, name) == 0) {
            current->med.price = price;
            current->med.quantity = quantity;
            return;
        }
        current = current->next;
    }
    printf("Medicine not found!\n");
}

void delete_medicine(char *name) {
    struct node *current = head;
    struct node *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->med.name, name) == 0) {
            if (previous == NULL) {
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
    printf("Medicine not found!\n");
}

int main() {
    int choice;
    char name[50];
    float price;
    int quantity;

    while (1) {
        printf("1. Add medicine\n");
        printf("2. Display medicines\n");
        printf("3. Search medicine\n");
        printf("4. Update medicine\n");
        printf("5. Delete medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter medicine name: ");
                scanf(" %[^\n]%*c", name);
                printf("Enter medicine price: ");
                scanf("%f", &price);
                printf("Enter medicine quantity: ");
                scanf("%d", &quantity);
                add_medicine(name, price, quantity);
                break;
            case 2:
                display_medicines();
                break;
            case 3:
                printf("Enter medicine name: ");
                scanf(" %[^\n]%*c", name);
                search_medicine(name);
                break;
            case 4:
                printf("Enter medicine name: ");
                scanf(" %[^\n]%*c", name);
                printf("Enter new medicine price: ");
                scanf("%f", &price);
                printf("Enter new medicine quantity: ");
                scanf("%d", &quantity);
                update_medicine(name, price, quantity);
                break;
            case 5:
                printf("Enter medicine name: ");
                scanf(" %[^\n]%*c", name);
                delete_medicine(name);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}