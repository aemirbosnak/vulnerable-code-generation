//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct medicine {
    char name[50];
    float price;
    int quantity;
} medicine_t;

medicine_t *medicines;
int num_medicines = 0;

void add_medicine() {
    medicine_t new_medicine;
    printf("Enter medicine name: ");
    scanf("%s", new_medicine.name);
    printf("Enter medicine price: ");
    scanf("%f", &new_medicine.price);
    printf("Enter medicine quantity: ");
    scanf("%d", &new_medicine.quantity);

    medicines = realloc(medicines, sizeof(medicine_t) * (num_medicines + 1));
    medicines[num_medicines++] = new_medicine;
}

void remove_medicine() {
    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);

    int index = -1;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine not found!\n");
        return;
    }

    for (int i = index + 1; i < num_medicines; i++) {
        medicines[i - 1] = medicines[i];
    }

    num_medicines--;
    medicines = realloc(medicines, sizeof(medicine_t) * num_medicines);
}

void update_medicine() {
    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);

    int index = -1;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine not found!\n");
        return;
    }

    printf("Enter new medicine price: ");
    scanf("%f", &medicines[index].price);
    printf("Enter new medicine quantity: ");
    scanf("%d", &medicines[index].quantity);
}

void list_medicines() {
    for (int i = 0; i < num_medicines; i++) {
        printf("%s %.2f %d\n", medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
}

void search_medicine() {
    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);

    int index = -1;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine not found!\n");
        return;
    }

    printf("Medicine found!\n");
    printf("Name: %s\n", medicines[index].name);
    printf("Price: %.2f\n", medicines[index].price);
    printf("Quantity: %d\n", medicines[index].quantity);
}

int main() {
    int choice;
    do {
        printf("1. Add Medicine\n");
        printf("2. Remove Medicine\n");
        printf("3. Update Medicine\n");
        printf("4. List Medicines\n");
        printf("5. Search Medicine\n");
        printf("6. Exit\n");
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
                list_medicines();
                break;
            case 5:
                search_medicine();
                break;
            case 6:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}