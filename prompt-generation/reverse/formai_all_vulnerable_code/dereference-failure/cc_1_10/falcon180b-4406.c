//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Product{
    char name[50];
    int quantity;
    float price;
};

struct Warehouse{
    int capacity;
    int numProducts;
    struct Product *products;
};

void initWarehouse(struct Warehouse *warehouse, int capacity){
    warehouse->capacity = capacity;
    warehouse->numProducts = 0;
    warehouse->products = (struct Product*)malloc(capacity * sizeof(struct Product));
    memset(warehouse->products, 0, capacity * sizeof(struct Product));
}

void addProduct(struct Warehouse *warehouse, char *name, int quantity, float price){
    if(warehouse->numProducts >= warehouse->capacity){
        printf("Warehouse is full.\n");
        return;
    }

    strcpy(warehouse->products[warehouse->numProducts].name, name);
    warehouse->products[warehouse->numProducts].quantity = quantity;
    warehouse->products[warehouse->numProducts].price = price;

    warehouse->numProducts++;
}

void removeProduct(struct Warehouse *warehouse, char *name){
    int i;

    for(i=0; i<warehouse->numProducts; i++){
        if(strcmp(warehouse->products[i].name, name) == 0){
            warehouse->numProducts--;

            if(i!= warehouse->numProducts){
                strcpy(warehouse->products[i].name, warehouse->products[warehouse->numProducts].name);
                warehouse->products[i].quantity = warehouse->products[warehouse->numProducts].quantity;
                warehouse->products[i].price = warehouse->products[warehouse->numProducts].price;
            }

            break;
        }
    }
}

void displayProducts(struct Warehouse *warehouse){
    int i;

    for(i=0; i<warehouse->numProducts; i++){
        printf("Name: %s\n", warehouse->products[i].name);
        printf("Quantity: %d\n", warehouse->products[i].quantity);
        printf("Price: $%.2f\n\n", warehouse->products[i].price);
    }
}

int main(){
    struct Warehouse warehouse;
    initWarehouse(&warehouse, 10);

    addProduct(&warehouse, "Apple", 100, 0.50);
    addProduct(&warehouse, "Banana", 50, 0.25);
    addProduct(&warehouse, "Orange", 25, 0.75);

    displayProducts(&warehouse);

    removeProduct(&warehouse, "Banana");

    displayProducts(&warehouse);

    return 0;
}