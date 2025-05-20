//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define a structure to represent a product
typedef struct product {
   int id;
   char name[30];
   int quantity;
   float price;
} Product;

//function to add a new product to the inventory
void addProduct(Product **inventory, int *numProducts) {
    int id, quantity;
    float price;
    char name[30];
    printf("\nEnter Product ID: ");
    scanf("%d", &id);
    printf("Enter Product Name: ");
    scanf("%s", name);
    printf("Enter Product Quantity: ");
    scanf("%d", &quantity);
    printf("Enter Product Price: ");
    scanf("%f", &price);
    inventory[*numProducts] = malloc(sizeof(Product));
    inventory[*numProducts]->id = id;
    strcpy(inventory[*numProducts]->name, name);
    inventory[*numProducts]->quantity = quantity;
    inventory[*numProducts]->price = price;
    (*numProducts)++;
    printf("\nProduct Added Successfully!");
}

//function to display all the products in the inventory
void displayProducts(Product **inventory, int numProducts) {
    if(numProducts == 0) {
        printf("\nInventory is Empty!");
        return;
    }
    printf("\n\nID\tName\tQuantity\tPrice\n");
    for(int i=0;i<numProducts;i++) {
        printf("%d\t%s\t%d\t\t%0.2f\n", inventory[i]->id, inventory[i]->name, inventory[i]->quantity, inventory[i]->price);
    }
}

//function to find a product by ID
void searchProductById(Product **inventory, int numProducts) {
    if(numProducts == 0) {
        printf("\nInventory is Empty!");
        return;
    }
    int id;
    printf("\nEnter Product ID: ");
    scanf("%d", &id);
    int found = 0;
    for(int i=0;i<numProducts;i++) {
        if(inventory[i]->id == id) {
            printf("\nProduct Found!");
            printf("\nID\tName\tQuantity\tPrice\n");
            printf("%d\t%s\t%d\t\t%0.2f\n", inventory[i]->id, inventory[i]->name, inventory[i]->quantity, inventory[i]->price);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("\nProduct Not Found!");
    }
}

//function to remove a product from the inventory
void deleteProduct(Product **inventory, int *numProducts) {
    if(*numProducts == 0) {
        printf("\nInventory is Empty!");
        return;
    }
    int id;
    printf("\nEnter Product ID: ");
    scanf("%d", &id);
    int found = 0;
    for(int i=0;i<*numProducts;i++) {
        if(inventory[i]->id == id) {
            found = 1;
            free(inventory[i]);
            for(int j=i+1;j<*numProducts;j++) {
                inventory[j-1] = inventory[j];
            }
            (*numProducts)--;
            printf("\nProduct Removed Successfully!");
            break;
        }
    }
    if(!found) {
        printf("\nProduct Not Found!");
    }
}

//function to update the quantity of a product
void updateProductQuantity(Product **inventory, int numProducts) {
    if(numProducts == 0) {
        printf("\nInventory is Empty!");
        return;
    }
    int id, quantity;
    printf("\nEnter Product ID: ");
    scanf("%d", &id);
    int found = 0;
    for(int i=0;i<numProducts;i++) {
        if(inventory[i]->id == id) {
            printf("\nEnter New Product Quantity: ");
            scanf("%d", &quantity);
            inventory[i]->quantity = quantity;
            found = 1;
            printf("\nProduct Quantity Updated Successfully!");
            break;
        }
    }
    if(!found) {
        printf("\nProduct Not Found!");
    }
}

//function to update the price of a product
void updateProductPrice(Product **inventory, int numProducts) {
    if(numProducts == 0) {
        printf("\nInventory is Empty!");
        return;
    }
    int id;
    float price;
    printf("\nEnter Product ID: ");
    scanf("%d", &id);
    int found = 0;
    for(int i=0;i<numProducts;i++) {
        if(inventory[i]->id == id) {
            printf("\nEnter New Product Price: ");
            scanf("%f", &price);
            inventory[i]->price = price;
            found = 1;
            printf("\nProduct Price Updated Successfully!");
            break;
        }
    }
    if(!found) {
        printf("\nProduct Not Found!");
    }
}

int main() {
    int option, numProducts = 0;
    Product **inventory = malloc(100 * sizeof(Product*)); //initializing inventory with a max capacity of 100
    do {
        printf("\n\n----Warehouse Management System Menu----\n");
        printf("1. Add New Product\n");
        printf("2. Display Inventory\n");
        printf("3. Search Product by ID\n");
        printf("4. Remove Product by ID\n");
        printf("5. Update Product Quantity\n");
        printf("6. Update Product Price\n");
        printf("7. Exit\n");
        printf("\nEnter your option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                addProduct(inventory, &numProducts);
                break;
            case 2:
                displayProducts(inventory, numProducts);
                break;
            case 3:
                searchProductById(inventory, numProducts);
                break;
            case 4:
                deleteProduct(inventory, &numProducts);
                break;
            case 5:
                updateProductQuantity(inventory, numProducts);
                break;
            case 6:
                updateProductPrice(inventory, numProducts);
                break;
            case 7:
                printf("\nGoodbye!");
                break;
            default:
                printf("\nInvalid Option! Please Try Again.");
                break;
        }
    } while(option != 7);
    return 0;
}