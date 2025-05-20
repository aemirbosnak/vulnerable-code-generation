//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Struct defining a product
typedef struct Product
{
    char name[50];
    int quantity;
    float price;
} Product;

//Struct defining a warehouse
typedef struct Warehouse
{
    int warehouse_id;
    char location[50];
    int capacity;
    Product *products;
    int num_products;
} Warehouse;

//Defining global array of warehouses
Warehouse warehouses[10];
int num_warehouses = 0;

//Function to add a product to a warehouse
void add_product(int warehouse_id, char *name, int quantity, float price)
{
    if (warehouse_id > num_warehouses)
    {
        printf("Error: Invalid Warehouse ID!\n");
        return;
    }
    Product *product = (Product*) malloc(sizeof(Product));
    strcpy(product->name, name);
    product->quantity = quantity;
    product->price = price;
    warehouses[warehouse_id].num_products++;
    warehouses[warehouse_id].products = realloc(warehouses[warehouse_id].products, sizeof(Product) * warehouses[warehouse_id].num_products);
    warehouses[warehouse_id].products[warehouses[warehouse_id].num_products - 1] = *product;
    free(product);
    printf("Product added successfully!\n");
}

//Function to remove a product from a warehouse
void remove_product(int warehouse_id, char *name)
{
    if (warehouse_id > num_warehouses)
    {
        printf("Error: Invalid Warehouse ID!\n");
        return;
    }
    int found_index = -1;
    for (int i = 0; i < warehouses[warehouse_id].num_products; i++)
    {
        if (strcmp(warehouses[warehouse_id].products[i].name, name) == 0)
        {
            found_index = i;
            break;
        }
    }
    if (found_index == -1)
    {
        printf("Error: Product not found in Warehouse!\n");
        return;
    }
    for (int i = found_index; i < warehouses[warehouse_id].num_products - 1; i++)
    {
        warehouses[warehouse_id].products[i] = warehouses[warehouse_id].products[i + 1];
    }
    warehouses[warehouse_id].num_products--;
    warehouses[warehouse_id].products = realloc(warehouses[warehouse_id].products, sizeof(Product) * warehouses[warehouse_id].num_products);
    printf("Product removed successfully!\n");
}

//Function to display the products in a warehouse
void display_warehouse_products(int warehouse_id)
{
    if (warehouse_id > num_warehouses)
    {
        printf("Error: Invalid Warehouse ID!\n");
        return;
    }
    printf("\nProducts in Warehouse %d (%s):\n", warehouse_id, warehouses[warehouse_id].location);
    printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");
    for (int i = 0; i < warehouses[warehouse_id].num_products; i++)
    {
        printf("%-20s %-10d %-10.2f\n", 
                warehouses[warehouse_id].products[i].name, 
                warehouses[warehouse_id].products[i].quantity, 
                warehouses[warehouse_id].products[i].price);
    }
    printf("\n");
}

//Main function
int main()
{
    //Initializing warehouses
    Warehouse warehouse1 = {1, "New York", 10, NULL, 0};
    Warehouse warehouse2 = {2, "Los Angeles", 20, NULL, 0};
    warehouses[0] = warehouse1;
    warehouses[1] = warehouse2;
    num_warehouses = 2;

    //Adding products to warehouses
    add_product(1, "Apple", 100, 2.99);
    add_product(1, "Banana", 50, 1.99);
    add_product(2, "Orange", 75, 3.99);
    add_product(2, "Grapes", 30, 4.99);

    //Displaying the products in warehouses
    display_warehouse_products(1);
    display_warehouse_products(2);

    //Removing a product from a warehouse
    remove_product(2, "Grapes");

    //Displaying the updated products in warehouses
    display_warehouse_products(2);

    return 0;
}