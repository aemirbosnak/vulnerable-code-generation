//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: modular
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    float price;
} Product;

int main() {
    Product medicines[10];
    int num_medicines = sizeof(medicines) / sizeof(medicines[0]);
    int i;

    printf("Medical Store Management System\n");
    printf("-----------------------------\n");
    printf("1. Add new product\n");
    printf("2. Search for a product\n");
    printf("3. Update product price\n");
    printf("4. Delete product\n");
    printf("5. Display all products\n");
    printf("6. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &i);

    switch (i) {
        case 1:
            printf("Enter product name: ");
            fgets(medicines[num_medicines].name, sizeof(medicines[0].name), stdin);
            printf("Enter product price: ");
            scanf("%f", &medicines[num_medicines].price);
            num_medicines++;
            break;
        case 2:
            printf("Enter product name to search: ");
            fgets(medicines[0].name, sizeof(medicines[0].name), stdin);
            break;
        case 3:
            printf("Enter product name to update: ");
            fgets(medicines[0].name, sizeof(medicines[0].name), stdin);
            printf("Enter new price: ");
            scanf("%f", &medicines[0].price);
            break;
        case 4:
            printf("Enter product name to delete: ");
            fgets(medicines[0].name, sizeof(medicines[0].name), stdin);
            for (i = 0; i < num_medicines - 1; i++) {
                strcpy(medicines[i].name, medicines[i + 1].name);
            }
            num_medicines--;
            break;
        case 5:
            printf("Displaying all products:\n");
            for (i = 0; i < num_medicines; i++) {
                printf("%s: %f\n", medicines[i].name, medicines[i].price);
            }
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}