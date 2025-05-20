//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    int id;
    char name[50];
    float price;
    int quantity;
};

typedef struct medicine Medicine;

void addMedicine(Medicine *medicines, int *count);
void findMedicine(Medicine *medicines, int count);
void displayMedicines(Medicine *medicines, int count);

int main() {
    int choice;
    int count = 0;
    Medicine *medicines = (Medicine *) malloc(sizeof(Medicine));
    
    do {
        printf("\n-- Medical Store Management System --\n");
        printf("\n1. Add Medicine");
        printf("\n2. Find Medicine");
        printf("\n3. Display Medicines ");
        printf("\n4. Quit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                //Add medicine to list
                addMedicine(medicines, &count);
                break;
            case 2:
                //Find medicine in list
                findMedicine(medicines, count);
                break;
            case 3:
                //Display all medicines in list
                displayMedicines(medicines, count);
                break;
            case 4:
                //Quit program
                printf("\nThank you for using Medical Store Management System.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    free(medicines);
    return 0;
}

void addMedicine(Medicine *medicines, int *count) {
    int id;
    char name[50];
    float price;
    int quantity;
    
    printf("\nEnter medicine ID: ");
    scanf("%d", &id);
    fflush(stdin);
    
    for (int i = 0; i < *count; i++) {
        if (medicines[i].id == id) {
            printf("\nMedicine with ID %d already exists. Cannot add duplicate entry.\n", id);
            return;
        }
    }
    
    printf("\nEnter medicine name: ");
    scanf("%[^\n]", name);
    fflush(stdin);
    
    printf("\nEnter medicine price: ");
    scanf("%f", &price);
    fflush(stdin);
    
    printf("\nEnter medicine quantity: ");
    scanf("%d", &quantity);
    fflush(stdin);
    
    Medicine medicine = {id, name, price, quantity};
    
    medicines[*count] = medicine;
    (*count)++;
    
    printf("\nMedicine added successfully.\n");
}

void findMedicine(Medicine *medicines, int count) {
    int id;
    printf("\nEnter medicine ID to search: ");
    scanf("%d", &id);
    fflush(stdin);
    
    for (int i = 0; i < count; i++) {
        if (medicines[i].id == id) {
            printf("\nMedicine Found!\n");
            printf("\nMedicine ID: %d\n", medicines[i].id);
            printf("\nMedicine Name: %s\n", medicines[i].name);
            printf("\nPrice: %.2f\n", medicines[i].price);
            printf("\nQuantity: %d\n", medicines[i].quantity);
            return;
        }
    }
    
    printf("\nMedicine with ID %d not found.\n", id);
}

void displayMedicines(Medicine *medicines, int count) {
    if (count == 0) {
        printf("\nNo medicines found.\n");
        return;
    }
    
    printf("\n----------Medicines List----------\n");
    for (int i = 0; i < count; i++) {
        printf("\nMedicine ID: %d\n", medicines[i].id);
        printf("\nMedicine Name: %s\n", medicines[i].name);
        printf("\nPrice: %.2f\n", medicines[i].price);
        printf("\nQuantity: %d\n", medicines[i].quantity);
        printf("\n---------------------------------\n");
    }
}