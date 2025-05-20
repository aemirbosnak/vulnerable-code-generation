//FormAI DATASET v1.0 Category: Product Inventory System ; Style: curious
#include <stdio.h>
#include <string.h>

// struct definition for product
struct product {
    int id;
    char name[30];
    float price;
    int quantity;
};

// function prototypes
void addProduct(struct product p[], int n);
void displayProducts(struct product p[], int n);
void searchProduct(struct product p[], int n);

int main() {
    int n, option;
    printf("Welcome to the Product Inventory System!\n");
    printf("Enter the number of products: ");
    scanf("%d", &n);
    
    // declare array of products
    struct product p[n];

    do {
        // display menu options
        printf("\nMenu Options:\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1: 
                addProduct(p, n);
                break;
            case 2: 
                displayProducts(p, n);
                break;
            case 3: 
                searchProduct(p, n);
                break;
            case 4:
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid Option. Try Again.\n");
        }
    } while(option != 4);

    return 0;
}

// function to add product to inventory
void addProduct(struct product p[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (p[i].id == 0) {
            printf("\nEnter Product Details:\n");
            printf("Product ID: ");
            scanf("%d", &p[i].id);
            printf("Product Name: ");
            scanf("%s", p[i].name);
            printf("Product Price: ");
            scanf("%f", &p[i].price);
            printf("Product Quantity: ");
            scanf("%d", &p[i].quantity);
            printf("Product Added Successfully.\n");
            break;
        }
    }
    if (i == n) {
        printf("Inventory Full. Cannot add more products.\n");
    }
}

// function to display all products in inventory
void displayProducts(struct product p[], int n) {
    int i;
    printf("\nList of Products:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (i = 0; i < n; i++) {
        if (p[i].id != 0) {
            printf("%d\t%s\t%.2f\t%d\n", p[i].id, p[i].name, p[i].price, p[i].quantity);
        }
    }
}

// function to search for a product by ID
void searchProduct(struct product p[], int n) {
    int id, i;
    printf("\nEnter Product ID to search: ");
    scanf("%d", &id);
    for (i = 0; i < n; i++) {
        if (p[i].id == id) {
            printf("Product Details:\n");
            printf("ID: %d\n", p[i].id);
            printf("Name: %s\n", p[i].name);
            printf("Price: %.2f\n", p[i].price);
            printf("Quantity: %d\n", p[i].quantity);
            break;
        }
    }
    if (i == n) {
        printf("Product with ID %d not found.\n", id);
    }
}