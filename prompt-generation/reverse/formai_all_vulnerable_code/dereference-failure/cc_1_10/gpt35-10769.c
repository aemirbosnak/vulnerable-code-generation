//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[100];
    int quantity;
};

void displayMenu(){
    printf("Please choose an option:\n");
    printf("1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. Display Available Products\n");
    printf("4. Exit\n");
}

void addProduct(struct Product* products, int* numProducts){
    printf("Enter the name of the Product: ");
    scanf("%s", products[*numProducts].name);
    printf("Enter the quantity of the Product: ");
    scanf("%d", &products[*numProducts].quantity);
    products[*numProducts].id = *numProducts + 1;
    (*numProducts)++;
}

void removeProduct(struct Product* products, int* numProducts){
    int idToDelete, indexToDelete;
    printf("Enter the ID of the product you want to remove: ");
    scanf("%d", &idToDelete);
    
    for(int i=0; i<*numProducts; i++){
        if(products[i].id == idToDelete){
            indexToDelete = i;
            break;
        }
    }
    
    for(int i=indexToDelete; i<*numProducts-1; i++){
        products[i] = products[i+1];
    }
    (*numProducts)--;
}

void displayProducts(struct Product* products, int numProducts){
    printf("\nID\tName\t\tQuantity\n");
    for(int i=0; i<numProducts; i++){
        printf("%d\t%s\t\t%d\n", products[i].id, products[i].name, products[i].quantity);
    }
    printf("\n");
}

int main() {
    printf("Welcome to the Warehouse Management System!\n");
    
    struct Product products[100];
    int numProducts = 0;
    int choice = 0;
    
    while(choice != 4){
        displayMenu();
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                addProduct(products, &numProducts);
                break;
            case 2:
                removeProduct(products, &numProducts);
                break;
            case 3:
                displayProducts(products, numProducts);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}