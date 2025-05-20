//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
} Medicine;

Medicine* medicines;
int medicineCount = 0;

void addMedicine();
void viewMedicines();
void purchaseMedicine();
void deleteMedicine();
void saveToFile();
void loadFromFile();
void displayMenu();

int main() {
    loadFromFile();
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addMedicine(); break;
            case 2: viewMedicines(); break;
            case 3: purchaseMedicine(); break;
            case 4: deleteMedicine(); break;
            case 5: saveToFile(); break; 
            case 6: printf("Exiting the program. Goodbye!\n"); break; 
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    free(medicines);
    return 0;
}

void displayMenu() {
    printf("\n===== Medical Store Management System =====\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicines\n");
    printf("3. Purchase Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Save Medicines to File\n");
    printf("6. Exit\n");
    printf("============================================\n");
}

void addMedicine() {
    medicines = realloc(medicines, (medicineCount + 1) * sizeof(Medicine));
    if (medicines == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    Medicine newMed;
    newMed.id = medicineCount + 1; // Assign a new ID
    printf("Enter medicine name: ");
    scanf("%s", newMed.name);
    printf("Enter manufacturer: ");
    scanf("%s", newMed.manufacturer);
    printf("Enter price: ");
    scanf("%f", &newMed.price);
    printf("Enter quantity: ");
    scanf("%d", &newMed.quantity);

    medicines[medicineCount] = newMed;
    medicineCount++;
    printf("Medicine added successfully!\n");
}

void viewMedicines() {
    if (medicineCount == 0) {
        printf("No medicines available.\n");
        return;
    }
    printf("\nAvailable Medicines:\n");
    printf("ID\tName\t\tManufacturer\tPrice\tQuantity\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("%d\t%s\t\t%s\t%.2f\t%d\n", 
            medicines[i].id, medicines[i].name, medicines[i].manufacturer, 
            medicines[i].price, medicines[i].quantity);
    }
}

void purchaseMedicine() {
    int id;
    printf("Enter medicine ID to purchase: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > medicineCount) {
        printf("Invalid medicine ID.\n");
        return;
    }

    Medicine *med = &medicines[id - 1];
    printf("You are purchasing: %s\n", med->name);
    int quantity;
    printf("Enter quantity to purchase: ");
    scanf("%d", &quantity);

    if (quantity > med->quantity) {
        printf("Insufficient quantity available!\n");
        return;
    }

    med->quantity -= quantity;
    printf("Purchase successful! You bought %d of %s.\n", quantity, med->name);
}

void deleteMedicine() {
    int id;
    printf("Enter medicine ID to delete: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > medicineCount) {
        printf("Invalid medicine ID.\n");
        return;
    }

    for (int i = id - 1; i < medicineCount - 1; i++) {
        medicines[i] = medicines[i + 1];
    }
    medicineCount--;
    medicines = realloc(medicines, medicineCount * sizeof(Medicine));
    printf("Medicine deleted successfully!\n");
}

void saveToFile() {
    FILE *file = fopen("medicines.txt", "w");
    if (file == NULL) {
        printf("Could not open file for writing!\n");
        return;
    }
    for (int i = 0; i < medicineCount; i++) {
        fprintf(file, "%d %s %s %.2f %d\n", medicines[i].id, medicines[i].name,
                medicines[i].manufacturer, medicines[i].price, medicines[i].quantity);
    }
    fclose(file);
    printf("Medicines saved successfully to file.\n");
}

void loadFromFile() {
    FILE *file = fopen("medicines.txt", "r");
    if (file == NULL) {
        return; // No file means first run, we'll create it later
    }

    while (!feof(file)) {
        Medicine med;
        if (fscanf(file, "%d %s %s %f %d", &med.id, med.name, med.manufacturer,
                   &med.price, &med.quantity) != 5) {
            break; // Using break to leave the loop upon EOF or any issue
        }
        medicines = realloc(medicines, (medicineCount + 1) * sizeof(Medicine));
        medicines[medicineCount++] = med;
    }
    fclose(file);
    printf("Medicines loaded successfully from file.\n");
}