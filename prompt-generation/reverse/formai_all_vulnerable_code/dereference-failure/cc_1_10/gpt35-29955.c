//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicament {
    char name[50];
    char manufacturer[50];
    int quantity;
    float price;
    struct medicament *next;
};

typedef struct medicament Medicament;
Medicament *head = NULL;

void addMedicament(char *name, char *manufacturer, int quantity, float price) {
    Medicament *newMedicament = (Medicament*)malloc(sizeof(Medicament));
    strcpy(newMedicament->name, name);
    strcpy(newMedicament->manufacturer, manufacturer);
    newMedicament->quantity = quantity;
    newMedicament->price = price;
    newMedicament->next = NULL;

    if(head == NULL) {
        head = newMedicament;
        return;
    }

    Medicament *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    
    temp->next = newMedicament;
}

void purchaseMedicament(char *name, int quantityToPurchase) {
    Medicament *temp = head;
    while(temp != NULL) {
        if(strcmp(temp->name, name) == 0) {
            if(temp->quantity >= quantityToPurchase) {
                temp->quantity -= quantityToPurchase;
                printf("%s purchased successfully.\n", name);
                return;
            } else {
                printf("Insufficient quantity to purchase.\n");
                return;
            }
        }
        temp = temp->next;
    }

    printf("%s not found.\n", name);
}

void displayMedicaments() {
    if(head == NULL) {
        printf("No medicaments to display.\n");
        return;
    }

    Medicament *temp = head;
    printf("Name\tManufacturer\tQuantity\tPrice\n");
    while(temp != NULL) {
        printf("%s\t%s\t%d\t%f\n", temp->name, temp->manufacturer, temp->quantity, temp->price);
        temp = temp->next;
    }
}

int main() {
    int choice, quantityToPurchase;
    char name[50], manufacturer[50];
    float price;

    printf("Welcome to Medical Store Management System.\n");

    while(1) {
        printf("\n1. Add Medicament\n2. Purchase Medicament\n3. Display Medicaments\n4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:     
                printf("Enter medicament details - name, manufacturer, quantity, price: ");
                scanf("%s %s %d %f", name, manufacturer, &quantityToPurchase, &price);
                addMedicament(name, manufacturer, quantityToPurchase, price);
                printf("Medicament added successfully.\n");
                break;

            case 2:     
                printf("Enter medicament name and quantity to purchase: ");
                scanf("%s %d", name, &quantityToPurchase);
                purchaseMedicament(name, quantityToPurchase);
                break;

            case 3:     
                displayMedicaments();
                break;

            case 4:     
                printf("Thank you for using Medical Store Management System.\n");
                exit(0);

            default:    
                printf("Invalid choice.\n");
        }
    }

    return 0;
}