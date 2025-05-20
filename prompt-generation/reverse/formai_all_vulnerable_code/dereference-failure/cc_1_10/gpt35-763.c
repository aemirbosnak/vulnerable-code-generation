//FormAI DATASET v1.0 Category: Product Inventory System ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct product {   //structure of the product
    int id;
    char name[20];
    float price;
    int quantity;
};

void add_product(struct product *prod, int num_products);
void display_products(struct product *prod, int num_products);
void search_product(struct product *prod, int num_products);
void update_product(struct product *prod, int num_products);

int main() 
{
    int num_products, choice;
    struct product *prod;

    printf("Enter the number of products: ");
    scanf("%d", &num_products);

    prod = (struct product*) malloc(num_products * sizeof(struct product)); //memory allocation

    do {
        printf("\n\nPRODUCT INVENTORY SYSTEM\n");
        printf("1. Add a new product to inventory\n");
        printf("2. Display all products in inventory\n");
        printf("3. Search a product in inventory\n");
        printf("4. Update a product in inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product(prod, num_products);
                break;
            case 2:
                display_products(prod, num_products);
                break;
            case 3:
                search_product(prod, num_products);
                break;
            case 4:
                update_product(prod, num_products);
                break;
            case 5:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 5);

    free(prod); //freeing allocated memory
    return 0;
}

void add_product(struct product *prod, int num_products) {
    int id, quantity;
    float price;
    char name[20];

    printf("Enter the following details of the product:\n");
    printf("ID: ");
    scanf("%d", &id);

    for(int i = 0; i < num_products; i++) {
        if(id == prod[i].id) { //checking if ID already exists
            printf("Product with given ID already exists. Please try again.\n");
            return;
        }
    }

    printf("Name: ");
    scanf("%s", name);

    printf("Price: ");
    scanf("%f", &price);

    printf("Quantity: ");
    scanf("%d", &quantity);

    //adding product to inventory
    prod[num_products-1].id = id;
    strncpy(prod[num_products-1].name, name, 20);
    prod[num_products-1].price = price;
    prod[num_products-1].quantity = quantity;

    printf("Product added successfully.\n");
}

void display_products(struct product *prod, int num_products) {
    printf("Product ID\tProduct Name\tProduct Price\tProduct Quantity\n");
    for(int i = 0; i < num_products; i++) {
        printf("%d\t\t%s\t\t%.2f\t\t%d\n", prod[i].id, prod[i].name, prod[i].price, prod[i].quantity);
    }
}

void search_product(struct product *prod, int num_products) {
    int id, flag = 0;

    printf("Enter the ID of the product to search: ");
    scanf("%d", &id);

    for(int i = 0; i < num_products; i++) {
        if(id == prod[i].id) { //checking if ID exists
            printf("Product ID\tProduct Name\tProduct Price\tProduct Quantity\n");
            printf("%d\t\t%s\t\t%.2f\t\t%d\n", prod[i].id, prod[i].name, prod[i].price, prod[i].quantity);
            flag = 1;
            break;
        }
    }

    if(flag == 0)
        printf("Product not found.\n");
}

void update_product(struct product *prod, int num_products) {
    int id, choice, new_quantity;
    float new_price;

    printf("Enter the ID of the product to update: ");
    scanf("%d", &id);

    for(int i = 0; i < num_products; i++) {
        if(id == prod[i].id) { //checking if ID exists
            printf("Product found. What do you want to update?\n");
            printf("1. Quantity\n");
            printf("2. Price\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("Enter the new quantity: ");
                    scanf("%d", &new_quantity);
                    prod[i].quantity = new_quantity;
                    printf("Quantity updated successfully.\n");
                    break;
                case 2:
                    printf("Enter the new price: ");
                    scanf("%f", &new_price);
                    prod[i].price = new_price;
                    printf("Price updated successfully.\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
            }
            return;
        }
    }

    printf("Product not found.\n");
}