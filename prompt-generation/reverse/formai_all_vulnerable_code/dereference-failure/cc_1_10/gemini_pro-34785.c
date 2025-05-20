//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

Medicine *inventory;
int num_medicines;

void add_medicine() {
    Medicine new_medicine;
    printf("Enter the name of the medicine: ");
    scanf("%s", new_medicine.name);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &new_medicine.quantity);
    printf("Enter the price of the medicine: ");
    scanf("%f", &new_medicine.price);

    inventory = realloc(inventory, (num_medicines + 1) * sizeof(Medicine));
    inventory[num_medicines++] = new_medicine;
}

void remove_medicine() {
    char name[50];
    printf("Enter the name of the medicine to remove: ");
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
        return;
    }

    for (int i = index; i < num_medicines - 1; i++) {
        inventory[i] = inventory[i + 1];
    }

    num_medicines--;
    inventory = realloc(inventory, num_medicines * sizeof(Medicine));
}

void update_medicine() {
    char name[50];
    printf("Enter the name of the medicine to update: ");
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
        return;
    }

    printf("Enter the new quantity of the medicine: ");
    scanf("%d", &inventory[index].quantity);
    printf("Enter the new price of the medicine: ");
    scanf("%f", &inventory[index].price);
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
        printf("\n1. Add medicine\n");
        printf("2. Remove medicine\n");
        printf("3. Update medicine\n");
        printf("4. Display inventory\n");
        printf("5. Exit\n");
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