//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Medicine;

Medicine *medicine_list;
int num_medicines = 0;

void add_medicine() {
    Medicine medicine;

    printf("Enter medicine ID: ");
    scanf("%d", &medicine.id);

    printf("Enter medicine name: ");
    scanf("%s", medicine.name);

    printf("Enter medicine quantity: ");
    scanf("%d", &medicine.quantity);

    printf("Enter medicine price: ");
    scanf("%f", &medicine.price);

    medicine_list = realloc(medicine_list, (num_medicines + 1) * sizeof(Medicine));
    medicine_list[num_medicines++] = medicine;
}

void display_medicines() {
    int i;

    printf("ID\tName\tQuantity\tPrice\n");
    for (i = 0; i < num_medicines; i++) {
        printf("%d\t%s\t%d\t%.2f\n", medicine_list[i].id, medicine_list[i].name, medicine_list[i].quantity, medicine_list[i].price);
    }
}

void search_medicine() {
    int i;
    int id;

    printf("Enter medicine ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < num_medicines; i++) {
        if (medicine_list[i].id == id) {
            printf("Medicine found!\n");
            printf("ID: %d\n", medicine_list[i].id);
            printf("Name: %s\n", medicine_list[i].name);
            printf("Quantity: %d\n", medicine_list[i].quantity);
            printf("Price: %.2f\n", medicine_list[i].price);
            return;
        }
    }

    printf("Medicine not found!\n");
}

void update_medicine() {
    int i;
    int id;
    Medicine medicine;

    printf("Enter medicine ID to update: ");
    scanf("%d", &id);

    for (i = 0; i < num_medicines; i++) {
        if (medicine_list[i].id == id) {
            printf("Enter new medicine name: ");
            scanf("%s", medicine.name);

            printf("Enter new medicine quantity: ");
            scanf("%d", &medicine.quantity);

            printf("Enter new medicine price: ");
            scanf("%f", &medicine.price);

            medicine_list[i] = medicine;
            printf("Medicine updated!\n");
            return;
        }
    }

    printf("Medicine not found!\n");
}

void delete_medicine() {
    int i;
    int id;

    printf("Enter medicine ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < num_medicines; i++) {
        if (medicine_list[i].id == id) {
            medicine_list[i] = medicine_list[num_medicines - 1];
            num_medicines--;
            printf("Medicine deleted!\n");
            return;
        }
    }

    printf("Medicine not found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add medicine\n");
        printf("2. Display medicines\n");
        printf("3. Search medicine\n");
        printf("4. Update medicine\n");
        printf("5. Delete medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                display_medicines();
                break;
            case 3:
                search_medicine();
                break;
            case 4:
                update_medicine();
                break;
            case 5:
                delete_medicine();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}