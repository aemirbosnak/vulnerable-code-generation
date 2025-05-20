//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_MEDICINE_NAME_SIZE 50
#define MAX_MEDICINE_BATCH_SIZE 15

typedef struct {
    char name[MAX_MEDICINE_NAME_SIZE];
    char batch[MAX_MEDICINE_BATCH_SIZE];
    float price;
    int quantity;
} Medicine;

typedef struct {
    Medicine* inventory;
    int count;
} Inventory;

void displayMenu() {
    printf("\n--- Medical Store Management System ---\n");
    printf("1. Add medicine to inventory\n");
    printf("2. Remove medicine from inventory\n");
    printf("3. View inventory\n");
    printf("4. Update medicine quantity\n");
    printf("5. Update medicine price\n");
    printf("6. Exit");
    printf("\n---------------------------------------\n");
}

Inventory initializeInventory(int initialCapacity) {
    Inventory inventory = { (Medicine*) malloc(sizeof(Medicine) * initialCapacity), 0 };
    return inventory;
}

void expandInventory(Inventory* inventory) {
    Medicine* newInventory = (Medicine*) malloc(sizeof(Medicine) * (inventory->count * 2));
    for (int i = 0; i < inventory->count; i++) {
        newInventory[i] = inventory->inventory[i];
    }
    free(inventory->inventory);
    inventory->inventory = newInventory;
}

void addMedicineToInventory(Inventory* inventory) {
    if (inventory->count == 0 || inventory->count % 10 == 0) {
        expandInventory(inventory);
    }
    Medicine medicine;
    printf("\nEnter medicine name: ");
    scanf("%s", medicine.name);
    printf("Enter medicine batch: ");
    scanf("%s", medicine.batch);
    printf("Enter medicine price: ");
    scanf("%f", &medicine.price);
    printf("Enter medicine quantity: ");
    scanf("%d", &medicine.quantity);
    inventory->inventory[inventory->count++] = medicine;
    printf("\nMedicine added to inventory successfully!\n");
}

int findMedicineInInventory(Inventory* inventory, char* name, char* batch) {
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->inventory[i].name, name) == 0 && strcmp(inventory->inventory[i].batch, batch) == 0) {
            return i;
        }
    }
    return -1;
}

void removeMedicineFromInventory(Inventory* inventory) {
    char name[MAX_MEDICINE_NAME_SIZE], batch[MAX_MEDICINE_BATCH_SIZE];
    printf("Enter medicine name to be removed: ");
    scanf("%s", name);
    printf("Enter medicine batch to be removed: ");
    scanf("%s", batch);
    int index = findMedicineInInventory(inventory, name, batch);
    if (index == -1) {
        printf("\nMedicine not found in inventory!\n");
    } else {
        for (int i = index; i < inventory->count - 1; i++) {
            inventory->inventory[i] = inventory->inventory[i + 1];
        }
        printf("\nMedicine removed from inventory successfully!\n");
        inventory->count--;
    }
}

void viewInventory(Inventory* inventory) {
    printf("\n--- Inventory ---\n");
    printf("Name\t\tBatch\t\tPrice\tQuantity\n");
    for (int i = 0; i < inventory->count; i++) {
        printf("%s\t%s\t%.2f\t%d\n", inventory->inventory[i].name, inventory->inventory[i].batch, inventory->inventory[i].price, inventory->inventory[i].quantity);
    }
}

void updateMedicineQuantity(Inventory* inventory) {
    char name[MAX_MEDICINE_NAME_SIZE], batch[MAX_MEDICINE_BATCH_SIZE];
    printf("Enter medicine name: ");
    scanf("%s", name);
    printf("Enter medicine batch: ");
    scanf("%s", batch);
    int index = findMedicineInInventory(inventory, name, batch);
    if (index == -1) {
        printf("\nMedicine not found in inventory!\n");
    } else {
        printf("Enter new quantity: ");
        scanf("%d", &inventory->inventory[index].quantity);
        printf("\nMedicine quantity updated successfully!\n");
    }
}

void updateMedicinePrice(Inventory* inventory) {
    char name[MAX_MEDICINE_NAME_SIZE], batch[MAX_MEDICINE_BATCH_SIZE];
    printf("Enter medicine name: ");
    scanf("%s", name);
    printf("Enter medicine batch: ");
    scanf("%s", batch);
    int index = findMedicineInInventory(inventory, name, batch);
    if (index == -1) {
        printf("\nMedicine not found in inventory!\n");
    } else {
        printf("Enter new price: ");
        scanf("%f", &inventory->inventory[index].price);
        printf("\nMedicine price updated successfully!\n");
    }
}

int main() {
    Inventory inventory = initializeInventory(10);
    int choice = 0;
    do {
        displayMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMedicineToInventory(&inventory);
                break;
            case 2:
                removeMedicineFromInventory(&inventory);
                break;
            case 3:
                viewInventory(&inventory);
                break;
            case 4:
                updateMedicineQuantity(&inventory);
                break;
            case 5:
                updateMedicinePrice(&inventory);
                break;
            case 6:
                printf("\nExiting the program...");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);

    free(inventory.inventory);
    return 0;
}