//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Product
{
    char name[50];
    int quantity;
    float price;
} Product;

void addProduct(Product *products, int *size);
void displayProducts(Product *products, int size);
void updateQuantity(Product *products, int index, int quantity);

int main()
{
    Product *products = NULL;
    int size = 0;

    // Add some products
    addProduct(products, &size);
    addProduct(products, &size);
    addProduct(products, &size);

    // Display all products
    displayProducts(products, size);

    // Update the quantity of the second product
    updateQuantity(products, 1, 10);

    // Display all products again after updating the quantity
    displayProducts(products, size);

    return 0;
}

void addProduct(Product *products, int *size)
{
    products = (Product *)realloc(products, (*size + 1) * sizeof(Product));
    products[*size].name[0] = '\0';
    products[*size].quantity = 0;
    products[*size].price = 0.0f;
    *size++;
}

void displayProducts(Product *products, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s: %d, $%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void updateQuantity(Product *products, int index, int quantity)
{
    products[index].quantity = quantity;
}