//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Product {
    char name[50];
    int quantity;
    double price;
} Product;

void insertProduct(Product **products, int *numProducts);
void displayProducts(Product **products, int numProducts);

int main()
{
    Product **products = NULL;
    int numProducts = 0;

    insertProduct(&products, &numProducts);
    insertProduct(&products, &numProducts);
    insertProduct(&products, &numProducts);

    displayProducts(products, numProducts);

    return 0;
}

void insertProduct(Product **products, int *numProducts)
{
    Product *newProduct = (Product *)malloc(sizeof(Product));
    printf("Enter product name: ");
    scanf("%s", newProduct->name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct->quantity);
    printf("Enter product price: ");
    scanf("%lf", &newProduct->price);

    *products = realloc(*products, (*numProducts + 1) * sizeof(Product));
    products[*numProducts] = newProduct;
    *numProducts++;
}

void displayProducts(Product **products, int numProducts)
{
    for (int i = 0; i < numProducts; i++)
    {
        printf("%s - %d - %.2lf\n", products[i]->name, products[i]->quantity, products[i]->price);
    }
}