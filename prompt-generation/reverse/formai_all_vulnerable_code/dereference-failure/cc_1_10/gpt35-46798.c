//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Warehouse {
    char productName[20];
    int productQuantity;
    float productPrice;
};

void addProduct(struct Warehouse* w, int n);
void removeProduct(struct Warehouse* w, int n);
void displayProducts(struct Warehouse* w, int n);
void searchProduct(struct Warehouse* w, int n);

int main() {
    int choice, n = 0;
    struct Warehouse* warehouse;

    printf("Enter the total number of products in the warehouse: ");
    scanf("%d", &n);

    warehouse = (struct Warehouse*)malloc(n * sizeof(struct Warehouse));  

    do{
        printf("\nWELCOME TO WAREHOUSE MANAGEMENT SYSTEM\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Display all products\n");
        printf("4. Search a product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addProduct(warehouse, n);
                break;
            case 2:
                removeProduct(warehouse, n);
                break;
            case 3:
                displayProducts(warehouse, n);
                break;
            case 4:
                searchProduct(warehouse, n);
                break;
            case 5:
                printf("THANK YOU FOR USING WAREHOUSE MANAGEMENT SYSTEM\n");
                break;
            default:
                printf("Invalid choice!!\n");
        }

    }while(choice != 5);

    free(warehouse);

    return 0;
}

void addProduct(struct Warehouse* w, int n) {
    char tempName[20];
    int tempQuantity;
    float tempPrice;

    printf("Enter the details of the product to add:\n");
    printf("Name: ");
    scanf("%s", tempName);
    printf("Quantity: ");
    scanf("%d", &tempQuantity);
    printf("Price: ");
    scanf("%f", &tempPrice);

    for(int i = 0; i < n; i++) {
        if(w[i].productQuantity == 0) {
            strcpy(w[i].productName, tempName);
            w[i].productQuantity = tempQuantity;
            w[i].productPrice = tempPrice;
            printf("Product added successfully!\n");
            return;
        }
    }

    printf("Warehouse is full, cannot add more products!!\n");
}

void removeProduct(struct Warehouse* w, int n) {
    char tempName[20];
    int flag = 0;

    printf("Enter the name of the product to remove: ");
    scanf("%s", tempName);

    for(int i = 0; i < n; i++) {
        if(strcmp(w[i].productName, tempName) == 0) {
            strcpy(w[i].productName, "");
            w[i].productQuantity = 0;
            w[i].productPrice = 0.0;
            flag = 1;
            printf("Product removed successfully!\n");
            break;
        }
    }

    if(flag == 0) {
        printf("Product not found in warehouse!!\n");
    }
}

void displayProducts(struct Warehouse* w, int n) {
    printf("Product Name\tProduct Quantity\tProduct Price\n");
    for(int i = 0; i < n; i++) {
        if(w[i].productQuantity != 0) {
            printf("%s\t\t%d\t\t%.2f\n", w[i].productName, w[i].productQuantity, w[i].productPrice);
        }
    }
}

void searchProduct(struct Warehouse* w, int n) {
    char tempName[20];
    int flag = 0;

    printf("Enter the name of the product to search: ");
    scanf("%s", tempName);

    for(int i = 0; i < n; i++) {
        if(strcmp(w[i].productName, tempName) == 0) {
            printf("Product Name\tProduct Quantity\tProduct Price\n");
            printf("%s\t\t%d\t\t%.2f\n", w[i].productName, w[i].productQuantity, w[i].productPrice);
            flag = 1;
            break;
        }
    }

    if(flag == 0) {
        printf("Product not found in warehouse!!\n");
    }
}