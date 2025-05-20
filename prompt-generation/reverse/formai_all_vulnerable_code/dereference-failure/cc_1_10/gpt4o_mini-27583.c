//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_LINE_LENGTH 256

typedef struct {
    char name[50];
    int total_sales;
    int sales_count;
} Product;

void process_sales_data(const char *filename, Product products[], int *product_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        if (token == NULL) continue;

        char product_name[50];
        strcpy(product_name, token);

        int sale_amount = atoi(strtok(NULL, ","));
        if (sale_amount <= 0) continue; // Consider only positive sales

        int product_index = -1;
        for (int i = 0; i < *product_count; i++) {
            if (strcmp(products[i].name, product_name) == 0) {
                product_index = i;
                break;
            }
        }

        if (product_index == -1) {
            // New product found
            strcpy(products[*product_count].name, product_name);
            products[*product_count].total_sales = sale_amount;
            products[*product_count].sales_count = 1;
            (*product_count)++;
        } else {
            // Existing product found
            products[product_index].total_sales += sale_amount;
            products[product_index].sales_count++;
        }
    }

    fclose(file);
}

void display_average_sales(Product products[], int product_count) {
    printf("Average Sales per Product:\n");
    for (int i = 0; i < product_count; i++) {
        float average = (float)products[i].total_sales / products[i].sales_count;
        printf("Product: %s | Total Sales: %d | Sales Count: %d | Average Sales: %.2f\n",
               products[i].name, products[i].total_sales, products[i].sales_count, average);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path_to_csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Product products[MAX_PRODUCTS];
    int product_count = 0;

    process_sales_data(argv[1], products, &product_count);
    display_average_sales(products, product_count);

    return EXIT_SUCCESS;
}