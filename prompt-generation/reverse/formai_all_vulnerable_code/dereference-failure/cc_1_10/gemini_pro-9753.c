//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct medicine {
    char name[50];
    int quantity;
    float price;
    struct medicine *next;
} medicine;

medicine *head = NULL;

void add_medicine(char *name, int quantity, float price) {
    medicine *new_medicine = (medicine *)malloc(sizeof(medicine));
    strcpy(new_medicine->name, name);
    new_medicine->quantity = quantity;
    new_medicine->price = price;
    new_medicine->next = NULL;
    if (head == NULL) {
        head = new_medicine;
    } else {
        medicine *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_medicine;
    }
}

void display_medicine() {
    medicine *current = head;
    while (current != NULL) {
        printf("%s %d %f\n", current->name, current->quantity, current->price);
        current = current->next;
    }
}

void search_medicine(char *name) {
    medicine *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("%s %d %f\n", current->name, current->quantity, current->price);
            return;
        }
        current = current->next;
    }
    printf("Medicine not found.\n");
}

void update_medicine(char *name, int quantity, float price) {
    medicine *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            current->quantity = quantity;
            current->price = price;
            return;
        }
        current = current->next;
    }
    printf("Medicine not found.\n");
}

void delete_medicine(char *name) {
    medicine *current = head;
    medicine *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
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
    printf("Medicine not found.\n");
}

int main() {
    int choice;
    char name[50];
    int quantity;
    float price;
    do {
        printf("1. Add medicine\n");
        printf("2. Display medicine\n");
        printf("3. Search medicine\n");
        printf("4. Update medicine\n");
        printf("5. Delete medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter medicine name: ");
                scanf(" %s", name);
                printf("Enter medicine quantity: ");
                scanf(" %d", &quantity);
                printf("Enter medicine price: ");
                scanf(" %f", &price);
                add_medicine(name, quantity, price);
                break;
            case 2:
                display_medicine();
                break;
            case 3:
                printf("Enter medicine name: ");
                scanf(" %s", name);
                search_medicine(name);
                break;
            case 4:
                printf("Enter medicine name: ");
                scanf(" %s", name);
                printf("Enter medicine quantity: ");
                scanf(" %d", &quantity);
                printf("Enter medicine price: ");
                scanf(" %f", &price);
                update_medicine(name, quantity, price);
                break;
            case 5:
                printf("Enter medicine name: ");
                scanf(" %s", name);
                delete_medicine(name);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);
    return 0;
}