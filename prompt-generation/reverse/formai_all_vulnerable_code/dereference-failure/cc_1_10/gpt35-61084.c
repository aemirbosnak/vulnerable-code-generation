//FormAI DATASET v1.0 Category: Data mining ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 1000
#define MAX_LINE_LEN 100

typedef struct {
    char* name;
    float price;
    int quantity_sold;
    float total_revenue;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

// Function to add a new product to the list
void addProduct(char* name, float price, int quantity_sold) {
    Product newProduct;
    newProduct.name = name;
    newProduct.price = price;
    newProduct.quantity_sold = quantity_sold;
    newProduct.total_revenue = price * quantity_sold;
    products[num_products++] = newProduct;
}

// Function to print the top-selling products and the total revenue generated from each product
void printTopSellingProducts() {
    printf("\nTop Selling Products:\n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < num_products; i++) {
        for (int j = i + 1; j < num_products; j++) {
            if (products[j].quantity_sold > products[i].quantity_sold) {
                Product temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
        printf("%s (%.2f): %d sold, $%.2f earned\n", products[i].name, products[i].price, products[i].quantity_sold, products[i].total_revenue);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s [input_file]\n", argv[0]);
        return 1;
    }

    FILE* input_file;
    char line[MAX_LINE_LEN];
    char* token;
    char* name;
    float price;
    int quantity_sold;

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LEN, input_file) != NULL) {
        token = strtok(line, ";\n");
        name = token;
        token = strtok(NULL, ";\n");
        price = atof(token);
        token = strtok(NULL, ";\n");
        quantity_sold = atoi(token);
        addProduct(name, price, quantity_sold);
    }

    fclose(input_file);
    printTopSellingProducts();

    return 0;
}