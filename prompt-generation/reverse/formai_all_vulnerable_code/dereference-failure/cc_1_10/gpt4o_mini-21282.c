//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Medicine {
    int id;
    char name[50];
    float price;
    int quantity;
} Medicine;

Medicine* medicines = NULL;
int count = 0;

void addMedicine() {
    count++;
    medicines = realloc(medicines, count * sizeof(Medicine));
    if (medicines == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    Medicine *m = &medicines[count - 1];
    m->id = count;
    printf("Enter medicine name: ");
    scanf("%s", m->name);
    printf("Enter medicine price: ");
    scanf("%f", &m->price);
    printf("Enter medicine quantity: ");
    scanf("%d", &m->quantity);
    printf("Medicine added successfully!\n");
}

void viewMedicines() {
    if (count == 0) {
        printf("No medicines available.\n");
        return;
    }
    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < count; i++) {
        Medicine m = medicines[i];
        printf("%d\t%s\t%.2f\t%d\n", m.id, m.name, m.price, m.quantity);
    }
}

void deleteMedicine() {
    if (count == 0) {
        printf("No medicines to delete.\n");
        return;
    }

    int id;
    printf("Enter medicine ID to delete: ");
    scanf("%d", &id);
    if (id < 1 || id > count) {
        printf("Invalid ID.\n");
        return;
    }
    
    for (int i = id - 1; i < count - 1; i++) {
        medicines[i] = medicines[i + 1];
    }
    
    count--;
    medicines = realloc(medicines, count * sizeof(Medicine));
    if (medicines == NULL && count > 0) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Medicine deleted successfully!\n");
}

void searchMedicine() {
    if (count == 0) {
        printf("No medicines available to search.\n");
        return;
    }

    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    
    int found = 0;
    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            Medicine m = medicines[i];
            printf("%d\t%s\t%.2f\t%d\n", m.id, m.name, m.price, m.quantity);
            found = 1;
        }
    }
    if (!found) {
        printf("Medicine not found.\n");
    }
}

void freeMemory() {
    free(medicines);
}

int main() {
    int choice;
    do {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. View Medicines\n");
        printf("3. Delete Medicine\n");
        printf("4. Search Medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                viewMedicines();
                break;
            case 3:
                deleteMedicine();
                break;
            case 4:
                searchMedicine();
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    freeMemory();
    return 0;
}