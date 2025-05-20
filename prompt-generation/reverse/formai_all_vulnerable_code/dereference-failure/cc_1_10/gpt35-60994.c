//FormAI DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

void addProduct(struct product *p, int *count) {
    printf("Enter the product name:");
    scanf("%s",p[*count].name);
    printf("Enter the quantity available:");
    scanf("%d",&p[*count].quantity);
    printf("Enter the price per unit:");
    scanf("%f",&p[*count].price);
    p[*count].id = *count+1;
    printf("Product added successfully!\n");
    *count += 1;
}

void updateProduct(struct product *p, int count) {
    int id, index, choice;
    printf("Enter the product ID to update:");
    scanf("%d",&id);
    for(int i=0;i<count;i++) {
        if(p[i].id == id) {
            index = i;
            break;
        }
        if(i == count - 1) {
            printf("Product not found!\n");
            return;
        }
    }
    printf("What would you like to update?\n");
    printf("1. Name\n2. Quantity\n3. Price\n");
    scanf("%d",&choice);
    switch(choice) {
        case 1:
            printf("Enter the new name:");
            scanf("%s",p[index].name);
            break;
        case 2:
            printf("Enter the new quantity available:");
            scanf("%d",&p[index].quantity);
            break;
        case 3:
            printf("Enter the new price per unit:");
            scanf("%f",&p[index].price);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    printf("Product updated successfully!\n");
}

void deleteProduct(struct product *p, int *count) {
    int id, index;
    printf("Enter the ID of the product to be deleted:");
    scanf("%d",&id);
    for(int i=0;i<*count;i++) {
        if(p[i].id == id) {
            index = i;
            break;
        }
        if(i == *count - 1) {
            printf("Product not found!\n");
            return;
        }
    }
    for(int i=index;i<*count-1;i++) {
        p[i] = p[i+1];
    }
    *count -= 1;
    printf("Product deleted successfully!\n");
}

void displayProducts(struct product *p, int count) {
    printf("ID\tNAME\tQUANTITY\tPRICE PER UNIT\n");
    for(int i=0;i<count;i++) {
        printf("%d\t%s\t%d\t\t%.2f\n",p[i].id,p[i].name,p[i].quantity,p[i].price);
    }
}

int main() {
    struct product products[100];
    int count=0, choice;
    while(1) {
        printf("PRODUCT INVENTORY SYSTEM\n");
        printf("1. Add Product\n2. Update Product\n3. Delete Product\n4. Display Products\n5. Exit\n");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                addProduct(products,&count);
                break;
            case 2:
                updateProduct(products,count);
                break;
            case 3:
                deleteProduct(products,&count);
                break;
            case 4:
                displayProducts(products,count);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}