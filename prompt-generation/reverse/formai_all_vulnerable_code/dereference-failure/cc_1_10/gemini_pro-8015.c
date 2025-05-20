//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

Medicine *inventory;
int num_medicines = 0;

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

void sell_medicine() {
    char name[50];
    int quantity;
    printf("Enter the name of the medicine: ");
    scanf("%s", name);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &quantity);

    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            if (inventory[i].quantity < quantity) {
                printf("Insufficient quantity of the medicine.\n");
            } else {
                inventory[i].quantity -= quantity;
                printf("Sold %d units of %s.\n", quantity, name);
            }
            break;
        }
    }
}

void print_inventory() {
    printf("Inventory:\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("%s\t%d\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add medicine\n2. Sell medicine\n3. Print inventory\n4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                sell_medicine();
                break;
            case 3:
                print_inventory();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}