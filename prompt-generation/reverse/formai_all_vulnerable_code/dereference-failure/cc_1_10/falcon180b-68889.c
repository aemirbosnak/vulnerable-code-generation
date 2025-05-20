//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_CODE_LEN 10
#define MAX_PRICE_LEN 10
#define MAX_QUANTITY_LEN 10
#define MAX_SUPPLIER_LEN 50
#define MAX_CATEGORY_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char code[MAX_CODE_LEN];
    char price[MAX_PRICE_LEN];
    char quantity[MAX_QUANTITY_LEN];
    char supplier[MAX_SUPPLIER_LEN];
    char category[MAX_CATEGORY_LEN];
} product;

int main() {
    FILE *file;
    product products[MAX_PRODUCTS];
    int num_products = 0;
    int i, j;
    char line[1024];
    char *token;

    // Open the product file
    file = fopen("product.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open product file.\n");
        exit(1);
    }

    // Read in the product data
    while (fgets(line, sizeof(line), file)!= NULL) {
        // Remove the newline character from the end of the line
        line[strcspn(line, "\n")] = '\0';

        // Parse the line into fields
        token = strtok(line, ",");
        strcpy(products[num_products].name, token);
        token = strtok(NULL, ",");
        strcpy(products[num_products].code, token);
        token = strtok(NULL, ",");
        strcpy(products[num_products].price, token);
        token = strtok(NULL, ",");
        strcpy(products[num_products].quantity, token);
        token = strtok(NULL, ",");
        strcpy(products[num_products].supplier, token);
        token = strtok(NULL, ",");
        strcpy(products[num_products].category, token);

        // Increment the number of products
        num_products++;
    }

    // Close the product file
    fclose(file);

    // Print out the product data
    printf("Product Name\tCode\tPrice\tQuantity\tSupplier\tCategory\n");
    for (i = 0; i < num_products; i++) {
        printf("%s\t%s\t%s\t%s\t%s\t%s\n", products[i].name, products[i].code, products[i].price, products[i].quantity, products[i].supplier, products[i].category);
    }

    // Exit the program
    return 0;
}