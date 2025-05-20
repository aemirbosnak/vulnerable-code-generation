//FormAI DATASET v1.0 Category: Product Inventory System ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// structure to hold the product details
struct Product {
    char name[50];
    int id;
    float price;
    int quantity;
};

// function to display the product details
void displayProduct(struct Product p) {
    printf("Name: %s\n", p.name);
    printf("ID: %d\n", p.id);
    printf("Price: %f\n", p.price);
    printf("Quantity: %d\n", p.quantity);
    printf("=========================\n");
}

int main() {
    int choice;
    int numProducts = 0;
    struct Product *products = NULL;

    while(1) {
        printf("1. Add a product\n");
        printf("2. Display all products\n");
        printf("3. Update a product\n");
        printf("4. Delete a product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                // add a product

                // get the details from the user
                struct Product p;
                printf("Enter the name of the product: ");
                scanf("%s", p.name);
                printf("Enter the ID of the product: ");
                scanf("%d", &p.id);
                printf("Enter the price of the product: ");
                scanf("%f", &p.price);
                printf("Enter the quantity of the product: ");
                scanf("%d", &p.quantity);

                // add the product to the list
                numProducts++;
                products = (struct Product *) realloc(products, numProducts * sizeof(struct Product));
                products[numProducts-1] = p;

                printf("Product added successfully.\n\n");
                break;
            }
            case 2: {
                // display all products
                printf("Product Inventory:\n");
                for(int i=0; i<numProducts; i++) {
                    displayProduct(products[i]);
                }
                break;
            }
            case 3: {
                // update a product
                int id;
                printf("Enter the ID of the product to be updated: ");
                scanf("%d", &id);

                int index = -1;
                for(int i=0; i<numProducts; i++) {
                    if(products[i].id == id) {
                        index = i;
                        break;
                    }
                }

                if(index == -1) {
                    printf("Product not found.\n\n");
                }
                else {
                    // get the updated details from the user
                    printf("Enter the new name of the product: ");
                    scanf("%s", products[index].name);
                    printf("Enter the new price of the product: ");
                    scanf("%f", &products[index].price);
                    printf("Enter the new quantity of the product: ");
                    scanf("%d", &products[index].quantity);

                    printf("Product updated successfully.\n\n");
                }
                break;
            }
            case 4: {
                // delete a product
                int id;
                printf("Enter the ID of the product to be deleted: ");
                scanf("%d", &id);

                int index = -1;
                for(int i=0; i<numProducts; i++) {
                    if(products[i].id == id) {
                        index = i;
                        break;
                    }
                }

                if(index == -1) {
                    printf("Product not found.\n\n");
                }
                else {
                    // delete the product
                    for(int i=index; i<numProducts-1; i++) {
                        products[i] = products[i+1];
                    }
                    numProducts--;
                    products = (struct Product *) realloc(products, numProducts * sizeof(struct Product));

                    printf("Product deleted successfully.\n\n");
                }
                break;
            }
            case 5: {
                // exit the program
                printf("Exiting program...\n\n");
                exit(0);
            }
            default:
                printf("Invalid choice.\n\n");
        }
    }

    return 0;
}