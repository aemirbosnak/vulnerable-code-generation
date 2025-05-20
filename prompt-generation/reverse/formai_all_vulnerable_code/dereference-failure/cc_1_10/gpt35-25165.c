//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMITER ","

typedef struct {
    int id;
    char name[50];
    double price;
} Product;

typedef struct {
    Product *products;
    int size;
} ProductList;

void remove_newline(char *str) {
    char *pos = strchr(str, '\n');
    if (pos != NULL) {
        *pos = '\0';
    }
}

Product create_product(char *row) {
    Product product;
    char *token;

    // get product id
    token = strtok(row, DELIMITER);
    product.id = atoi(token);

    // get product name
    token = strtok(NULL, DELIMITER);
    strcpy(product.name, token);

    // get product price
    token = strtok(NULL, DELIMITER);
    product.price = atof(token);

    return product;
}

ProductList read_csv(char *filename) {
    ProductList productList;
    productList.products = NULL;
    productList.size = 0;

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    char row[1024];

    // read file line by line
    while (fgets(row, 1024, file)) {
        remove_newline(row);

        // allocate memory for product
        Product product = create_product(row);
        productList.size++;
        productList.products = (Product *)realloc(productList.products, productList.size * sizeof(Product));
        productList.products[productList.size - 1] = product;
    }

    fclose(file);

    return productList;
}

void print_product(Product product) {
    printf("ID: %d, Name: %s, Price: %.2f\n", product.id, product.name, product.price);
}

void print_products(ProductList productList) {
    for (int i = 0; i < productList.size; i++) {
        print_product(productList.products[i]);
    }
}

int main() {
    ProductList productList = read_csv("products.csv");
    print_products(productList);

    return 0;
}