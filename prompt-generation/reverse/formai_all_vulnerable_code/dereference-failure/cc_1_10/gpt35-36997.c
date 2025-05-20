//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct medicine {
    char name[50];
    int quantity;
    float price;
} Medicine;

Medicine* createMedicine(const char* name, const int quantity, const float price) {
    Medicine* med = (Medicine*)malloc(sizeof(Medicine));
    strcpy(med->name, name);
    med->quantity = quantity;
    med->price = price;
    return med;
}

void displayMedicines(const Medicine* medicineList, int size) {
    printf("---Medicine List---\n");
    printf("Name\tQuantity\tPrice\n");
    for(int i=0; i<size; i++) {
        printf("%s\t%d\t\t%.2f\n", medicineList[i].name, medicineList[i].quantity, medicineList[i].price);
    }
    printf("\n");
}

void addMedicine(Medicine* medicineList, int size) {
    char name[50];
    int quantity;
    float price;
    printf("Enter medicine name: ");
    scanf("%s", name);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    printf("Enter price: ");
    scanf("%f", &price);
    Medicine* newMedicine = createMedicine(name, quantity, price);
    medicineList[size] = *newMedicine;
    free(newMedicine);
    printf("Medicine added successfully!\n");
}

void removeMedicine(Medicine* medicineList, int size, const char* name) {
    for(int i=0; i<size; i++) {
        if(strcmp(medicineList[i].name, name) == 0) {
            for(int j=i; j<size-1; j++) {
                medicineList[j] = medicineList[j+1];
            }
            printf("Medicine removed successfully!\n");
            return;
        }
    }
    printf("Medicine not found in the list.\n");
}

int main() {
    int choice;
    int size = 0;
    Medicine medicineList[100];
    printf("Welcome to the Medical Store Management System!\n");
    while(1) {
        printf("Enter your choice:\n1) Display Medicines\n2) Add Medicine\n3) Remove Medicine\n4) Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: displayMedicines(medicineList, size); break;
            case 2: addMedicine(medicineList, size); size++; break;
            case 3: {
                char name[50];
                printf("Enter medicine name to remove: ");
                scanf("%s", name);
                removeMedicine(medicineList, size, name); 
                size--; 
                break;
            }
            case 4: printf("Thank you for using the Medical Store Management System!\n"); exit(0);
            default: printf("Invalid choice. Please try again.\n"); break;
        }
    }
    return 0;
}