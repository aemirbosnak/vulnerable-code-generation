//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: careful
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

void add_medicine() {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter medicine name: ");
    scanf("%s", new_node->med.name);
    printf("Enter medicine quantity: ");
    scanf("%d", &new_node->med.quantity);
    printf("Enter medicine price: ");
    scanf("%f", &new_node->med.price);
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void display_medicines() {
    struct node *temp = head;
    printf("Medicine Name\tQuantity\tPrice\n");
    while (temp != NULL) {
        printf("%s\t\t%d\t\t%.2f\n", temp->med.name, temp->med.quantity, temp->med.price);
        temp = temp->next;
    }
}

void search_medicine() {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    struct node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->med.name, name) == 0) {
            printf("Medicine found:\n");
            printf("Medicine Name: %s\n", temp->med.name);
            printf("Medicine Quantity: %d\n", temp->med.quantity);
            printf("Medicine Price: %.2f\n", temp->med.price);
            return;
        }
        temp = temp->next;
    }
    printf("Medicine not found.\n");
}

void update_medicine() {
    char name[50];
    printf("Enter medicine name to update: ");
    scanf("%s", name);
    struct node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->med.name, name) == 0) {
            printf("Enter new medicine quantity: ");
            scanf("%d", &temp->med.quantity);
            printf("Enter new medicine price: ");
            scanf("%f", &temp->med.price);
            printf("Medicine updated successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Medicine not found.\n");
}

void delete_medicine() {
    char name[50];
    printf("Enter medicine name to delete: ");
    scanf("%s", name);
    struct node *temp = head;
    struct node *prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->med.name, name) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Medicine deleted successfully.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Medicine not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                display_medicines();
                break;
            case 3:
                search_medicine();
                break;
            case 4:
                update_medicine();
                break;
            case 5:
                delete_medicine();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}