//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} medicine;

medicine *inventory = NULL;
int num_medicines = 0;

void add_medicine() {
    medicine *new_medicine = malloc(sizeof(medicine));
    printf("Enter medicine name: ");
    scanf("%s", new_medicine->name);
    printf("Enter quantity: ");
    scanf("%d", &new_medicine->quantity);
    printf("Enter price: ");
    scanf("%f", &new_medicine->price);

    inventory = realloc(inventory, (num_medicines + 1) * sizeof(medicine));
    inventory[num_medicines++] = *new_medicine;
    free(new_medicine);
}

void remove_medicine() {
    char name[50];
    printf("Enter medicine name to remove: ");
    scanf("%s", name);

    int index = -1;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine not found.\n");
    } else {
        for (int i = index; i < num_medicines - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        num_medicines--;
        inventory = realloc(inventory, num_medicines * sizeof(medicine));
    }
}

void update_medicine() {
    char name[50];
    printf("Enter medicine name to update: ");
    scanf("%s", name);

    int index = -1;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine not found.\n");
    } else {
        printf("Enter new quantity: ");
        scanf("%d", &inventory[index].quantity);
        printf("Enter new price: ");
        scanf("%f", &inventory[index].price);
    }
}

void display_inventory() {
    printf("Inventory:\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("%s\t%d\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Medicine\n2. Remove Medicine\n3. Update Medicine\n4. Display Inventory\n5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                remove_medicine();
                break;
            case 3:
                update_medicine();
                break;
            case 4:
                display_inventory();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}