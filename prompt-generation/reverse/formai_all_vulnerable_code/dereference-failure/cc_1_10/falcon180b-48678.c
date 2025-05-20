//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structures for Products and Inventory
typedef struct{
    int id;
    char name[30];
    char type[20];
    float price;
    int quantity;
}Product;

typedef struct{
    int size;
    Product *products;
}Inventory;

//Function to add a product to the inventory
void addProduct(Inventory *inventory, Product product){
    inventory->products = (Product*)realloc(inventory->products, (inventory->size+1)*sizeof(Product));
    inventory->products[inventory->size] = product;
    inventory->size++;
}

//Function to display the inventory
void displayInventory(Inventory inventory){
    printf("ID\tName\tType\tPrice\tQuantity\n");
    for(int i=0;i<inventory.size;i++){
        printf("%d\t%s\t%s\t%.2f\t%d\n",inventory.products[i].id,inventory.products[i].name,inventory.products[i].type,inventory.products[i].price,inventory.products[i].quantity);
    }
}

//Main function
int main(){
    Inventory inventory = {0,NULL};
    char choice;
    do{
        printf("\n1.Add Product\n2.Display Inventory\n3.Exit\n");
        scanf("%c",&choice);
        switch(choice){
            case '1':{
                Product product;
                printf("Enter Product ID: ");
                scanf("%d",&product.id);
                printf("Enter Product Name: ");
                scanf("%s",product.name);
                printf("Enter Product Type: ");
                scanf("%s",product.type);
                printf("Enter Product Price: ");
                scanf("%f",&product.price);
                printf("Enter Product Quantity: ");
                scanf("%d",&product.quantity);
                addProduct(&inventory,product);
                break;
            }
            case '2':{
                displayInventory(inventory);
                break;
            }
            case '3':{
                exit(0);
            }
            default:{
                printf("Invalid Choice\n");
            }
        }
    }while(choice!='3');
    return 0;
}