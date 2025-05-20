//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[100];
    int id;
    float price;
    int quantity;
};

void addMedicine(struct medicine *medicines, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details of medicine %d:", i+1);
        printf("\nName: ");
        scanf("%s", &medicines[i].name);
        printf("ID: ");
        scanf("%d", &medicines[i].id);
        printf("Price: ");
        scanf("%f", &medicines[i].price);
        printf("Quantity: ");
        scanf("%d", &medicines[i].quantity);
    }
}

void displayMedicines(struct medicine *medicines, int n) {
    printf("\nMedicine Details: ");
    for (int i = 0; i < n; i++) {
        printf("\nMedicine %d:\n", i+1);
        printf("Name: %s\n", medicines[i].name);
        printf("ID: %d\n", medicines[i].id);
        printf("Price: %.2f\n", medicines[i].price);
        printf("Quantity: %d\n", medicines[i].quantity);
    }
}

void searchMedicine(struct medicine *medicines, int n, int id) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (medicines[i].id == id) {
            printf("\nMedicine Found!");
            printf("\nName: %s\n", medicines[i].name);
            printf("ID: %d\n", medicines[i].id);
            printf("Price: %.2f\n", medicines[i].price);
            printf("Quantity: %d\n", medicines[i].quantity);
            found = 1;
            break;
        }
    }
    if (found == 0)
        printf("\nMedicine Not Found!");
}

void updateMedicine(struct medicine *medicines, int n, int id) {
    int index;
    for (int i = 0; i < n; i++) {
        if (medicines[i].id == id) {
            index = i;
            printf("\nEnter New Details of medicine %d:", index+1);
            printf("\nName: ");
            scanf("%s", &medicines[index].name);
            printf("ID: ");
            scanf("%d", &medicines[index].id);
            printf("Price: ");
            scanf("%f", &medicines[index].price);
            printf("Quantity: ");
            scanf("%d", &medicines[index].quantity);
            printf("\nMedicine Details Updated!");
            break;
        }
    }
}

void deleteMedicine(struct medicine *medicines, int n, int id) {
    int index, found = 0;
    for (int i = 0; i < n; i++) {
        if (medicines[i].id == id) {
            index = i;
            found = 1;
            break;
        }
    }
    if (found == 1) {
        for (int i = index; i < n-1; i++)
            medicines[i] = medicines[i+1];
        printf("\nMedicine Deleted Successfully!");
    }
    else
        printf("\nMedicine Not Found!");
}

int main() {
    int choice, n, id;
    printf("\nEnter No. of Medicines: ");
    scanf("%d", &n);
    struct medicine *medicines = (struct medicine*) malloc(n*sizeof(struct medicine));
    do {
        printf("\nMenu:\n1. Add a Medicine\n2. Display All Medicines\n3. Search a Medicine\n4. Update a Medicine\n5. Delete a Medicine\n6. Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addMedicine(medicines, n);
                    break;
            case 2: displayMedicines(medicines, n);
                    break;
            case 3: printf("\nEnter ID of Medicine to Search: ");
                    scanf("%d", &id);
                    searchMedicine(medicines, n, id);
                    break;
            case 4: printf("\nEnter ID of Medicine to Update: ");
                    scanf("%d", &id);
                    updateMedicine(medicines, n, id);
                    break;
            case 5: printf("\nEnter ID of Medicine to Delete: ");
                    scanf("%d", &id);
                    deleteMedicine(medicines, n, id);
                    n--;
                    medicines = (struct medicine*) realloc(medicines, n*sizeof(struct medicine));
                    break;
            case 6: break;
            default: printf("\nInvalid Choice!");
        }
    } while (choice != 6);
    free(medicines);
    return 0;
}