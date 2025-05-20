//FormAI DATASET v1.0 Category: Product Inventory System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct product {
    char name[MAX_NAME_LENGTH];
    int code;
    int quantity;
    float price;
} product;

int count = 0;
product products[MAX_PRODUCTS];

int add_product() {
    if (count >= MAX_PRODUCTS) {
        printf("Maximum number of products reached.\n");
        return 0;
    }

    product new_product;
    printf("Enter product name: ");
    fgets(new_product.name, MAX_NAME_LENGTH, stdin);
    new_product.name[strcspn(new_product.name, "\n")] = 0;
    printf("Enter product code: ");
    scanf("%d", &new_product.code);
    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter product price: ");
    scanf("%f", &new_product.price);

    products[count++] = new_product;
    return 1;
}

void print_products() {
    printf("Product Inventory:\n");
    printf("------------------\n");
    printf("%-50s  %4s  %8s  %8s\n", "Name", "Code", "Quantity", "Price");
    printf("------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-50s  %04d  %8d  $%7.2f\n",
               products[i].name, products[i].code, products[i].quantity, products[i].price);
    }
}

int search_product(int code) {
    for (int i = 0; i < count; i++) {
        if (products[i].code == code) {
            return i;
        }
    }
    return -1;
}

int remove_product(int code) {
    int index = search_product(code);
    if (index == -1) {
        printf("Product not found.\n");
        return 0;
    }

    for (int i = index; i < count - 1; i++) {
        products[i] = products[i + 1];
    }
    count--;
    return 1;
}

void save_products() {
    FILE *file = fopen("products.txt", "w");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s;%d;%d;%.2f\n", products[i].name, products[i].code,
                products[i].quantity, products[i].price);
    }
    fclose(file);
    printf("Products saved to file.\n");
}

void load_products() {
    FILE *file = fopen("products.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ";");
        int code = atoi(strtok(NULL, ";"));
        int quantity = atoi(strtok(NULL, ";"));
        float price = atof(strtok(NULL, ";"));

        product new_product;
        strncpy(new_product.name, name, MAX_NAME_LENGTH);
        new_product.code = code;
        new_product.quantity = quantity;
        new_product.price = price;

        products[i++] = new_product;
    }
    count = i;
    fclose(file);
    printf("Products loaded from file.\n");
}

int main() {
    load_products();

    int choice, code;

    do {
        printf("\nProduct Inventory System\n");
        printf("------------------------\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Print products\n");
        printf("4. Save products\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                printf("Enter product code: ");
                scanf("%d", &code);
                remove_product(code);
                break;
            case 3:
                print_products();
                break;
            case 4:
                save_products();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);

    save_products();

    return 0;
}