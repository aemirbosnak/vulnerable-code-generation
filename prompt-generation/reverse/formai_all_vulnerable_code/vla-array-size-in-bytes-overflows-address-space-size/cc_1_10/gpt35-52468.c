//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Item{
    char name[20];
    int quantity;
    float price;
    char supplier[30];
};

struct Warehouse{
    char location[20];
    struct Item inventory[100];
};

int main(){
    int numWarehouses;
    printf("Enter number of warehouses: ");
    scanf("%d", &numWarehouses);

    struct Warehouse warehouses[numWarehouses];

    for(int i=0; i<numWarehouses; i++){
        printf("\nEnter details for Warehouse %d\n", i+1);

        printf("Enter location: ");
        scanf("%s", warehouses[i].location);

        printf("\nEnter inventory details:\n");

        int numItems;
        printf("Enter number of items: ");
        scanf("%d", &numItems);

        for(int j=0; j<numItems; j++){
            printf("Enter details for Item %d\n", j+1);

            printf("Enter name: ");
            scanf("%s", warehouses[i].inventory[j].name);

            printf("Enter quantity: ");
            scanf("%d", &warehouses[i].inventory[j].quantity);

            printf("Enter price: ");
            scanf("%f", &warehouses[i].inventory[j].price);

            printf("Enter supplier: ");
            scanf("%s", warehouses[i].inventory[j].supplier);
        }
    }

    //Printing warehouse details
    for(int i=0; i<numWarehouses; i++){
        printf("\nWarehouse %d\n", i+1);
        printf("Location: %s\n", warehouses[i].location);

        printf("Inventory:\n");

        for(int j=0; j<100; j++){
            if(strcmp(warehouses[i].inventory[j].name, "")==0) break;

            printf("\t%s\t%d\t%.2f\t%s\n", warehouses[i].inventory[j].name, warehouses[i].inventory[j].quantity, warehouses[i].inventory[j].price, warehouses[i].inventory[j].supplier);
        }
    }

    return 0;
}