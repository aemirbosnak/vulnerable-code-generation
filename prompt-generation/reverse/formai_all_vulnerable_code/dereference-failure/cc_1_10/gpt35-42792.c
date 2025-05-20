//FormAI DATASET v1.0 Category: Product Inventory System ; Style: protected
#include<stdio.h>
#include<stdlib.h>

struct product {
    int productId;
    char productName[50];
    float productPrice;
    int productQuantity;
};

void addProduct(struct product *ptr, int num);
void displayInventory(struct product *ptr, int num);
void sellProduct(struct product *ptr, int productId, int num);

int main() {
    int num, operation, productId, quantity;
    printf("Enter the number of products: ");
    scanf("%d", &num);
    struct product *ptr;
    ptr = (struct product*) malloc(num*sizeof(struct product));
    if(ptr == NULL) {
        printf("Memory allocation unsuccessful!\n");
        exit(0);
    } 
    printf("Enter all the products information:\n");
    addProduct(ptr, num);
    printf("\n\nInventory System\n");
    printf("1. Display all products\n");
    printf("2. Sell a product\n");
    printf("3. Exit\n");
    do {
        printf("\nEnter operation to perform: ");
        scanf("%d", &operation);
        switch(operation) {
            case 1:
                displayInventory(ptr, num);
                break;
            case 2:
                printf("\nEnter the Product ID: ");
                scanf("%d", &productId);
                printf("\nEnter the quantity to sell: ");
                scanf("%d", &quantity);
                sellProduct(ptr, productId, quantity);
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid operation. Try Again!");
        }
    } while(1);
    return 0;
}

void addProduct(struct product *ptr, int num) {
    for(int i=0;i<num;i++) {
        printf("\nEnter the Product ID: ");
        scanf("%d", &ptr->productId);
        printf("\nEnter the Product Name: ");
        scanf("%s", ptr->productName);
        printf("\nEnter the Product Price: ");
        scanf("%f", &ptr->productPrice);
        printf("\nEnter the Product Quantity: ");
        scanf("%d", &ptr->productQuantity);
        ptr++;
    }
}

void displayInventory(struct product *ptr, int num) {
    printf("\n\nProduct ID\tProduct Name\t\tProduct Price\tQuantity\n");
    for(int i=0;i<num;i++) {
        printf("%d\t\t%s\t\t%.2f\t\t%d\n", ptr->productId, ptr->productName, ptr->productPrice, ptr->productQuantity);
        ptr++;
    }
}

void sellProduct(struct product *ptr, int productId, int num) {
    for(int i=0;i<num;i++) {
        if(ptr -> productId == productId) {
            if(ptr -> productQuantity >= num) {
                ptr -> productQuantity -= num;
                printf("\n%d %s sold successfully!\n", num, ptr -> productName);
                return;
            } else {
                printf("\n%d %s not in stock!\n", ptr -> productName);
                return;
            }
        }
        ptr++;
    }   
    printf("\nProduct ID does not exist!\n");
}