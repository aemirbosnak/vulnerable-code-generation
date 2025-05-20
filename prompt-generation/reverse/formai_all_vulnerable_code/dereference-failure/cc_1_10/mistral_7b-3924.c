//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    char name[50];
    float price;
    struct Product *left, *right;
} Product;

Product *createProduct(char *name, float price) {
    Product *product = (Product *)malloc(sizeof(Product));
    strcpy(product->name, name);
    product->price = price;
    product->left = product->right = NULL;
    return product;
}

Product *insertProduct(Product *root, Product *product) {
    if (root == NULL)
        return product;

    if (strcmp(product->name, root->name) < 0)
        root->left = insertProduct(root->left, product);
    else if (strcmp(product->name, root->name) > 0)
        root->right = insertProduct(root->right, product);

    return root;
}

Product *searchProduct(Product *root, char *name) {
    if (root == NULL || strcmp(root->name, name) == 0)
        return root;

    if (strcmp(name, root->name) < 0)
        return searchProduct(root->left, name);

    return searchProduct(root->right, name);
}

void removeProduct(Product **root, char *name) {
    if (*root == NULL)
        return;

    if (strcmp((*root)->name, name) < 0)
        removeProduct(&(*root)->right, name);
    else if (strcmp((*root)->name, name) > 0)
        removeProduct(&(*root)->left, name);
    else {
        Product *temp = *root;

        if (temp->left != NULL)
            *root = temp->left;
        else if (temp->right != NULL)
            *root = temp->right;

        free(temp);
    }
}

float calculateTotalRevenue(Product *root) {
    if (root == NULL)
        return 0.0;

    return root->price + calculateTotalRevenue(root->left) + calculateTotalRevenue(root->right);
}

float calculateAveragePrice(Product *root, float totalRevenue, int numProducts) {
    if (root == NULL)
        return totalRevenue / numProducts;

    numProducts++;
    return calculateAveragePrice(root->left, totalRevenue + root->price, numProducts) + calculateAveragePrice(root->right, totalRevenue + root->price, numProducts) / 2;
}

int main() {
    Product *tree = NULL;

    tree = insertProduct(tree, createProduct("Apple", 0.5));
    tree = insertProduct(tree, createProduct("Banana", 0.3));
    tree = insertProduct(tree, createProduct("Orange", 0.7));

    Product *product = searchProduct(tree, "Orange");
    if (product != NULL)
        printf("Product found: %s, Price: %.2f\n", product->name, product->price);
    else
        printf("Product not found.\n");

    removeProduct(&tree, "Banana");

    float totalRevenue = calculateTotalRevenue(tree);
    float averagePrice = calculateAveragePrice(tree, totalRevenue, 3);

    printf("Total revenue: %.2f\n", totalRevenue);
    printf("Average price: %.2f\n", averagePrice);

    return 0;
}