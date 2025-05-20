//FormAI DATASET v1.0 Category: Data mining ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CUSTOMERS 100
#define MAX_PURCHASES 1000

typedef struct {
    int customer_id;
    char product[50];
    float price;
} Purchase;

typedef struct {
    int customer_id;
    int num_purchases;
    Purchase purchases[MAX_PURCHASES];
} Customer;

int main() {
    Customer customers[MAX_CUSTOMERS];
    int num_customers = 0;

    // read in purchases from file
    FILE* fp = fopen("purchases.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file!\n");
        return 1;
    }

    char line[100];
    while (fgets(line, 100, fp)) {
        Purchase purchase;
        char* token = strtok(line, ",");
        purchase.customer_id = atoi(token);
        token = strtok(NULL, ",");
        strcpy(purchase.product, token);
        token = strtok(NULL, ",");
        purchase.price = atof(token);

        // find corresponding customer or add new one
        int found_customer = 0;
        for (int i = 0; i < num_customers; i++) {
            if (customers[i].customer_id == purchase.customer_id) {
                customers[i].purchases[customers[i].num_purchases++] = purchase;
                found_customer = 1;
                break;
            }
        }
        if (!found_customer) {
            Customer customer = { purchase.customer_id, 1, { purchase } };
            customers[num_customers++] = customer;
        }
    }
    fclose(fp);

    // do some data mining on the purchases
    float total_sales = 0;
    for (int i = 0; i < num_customers; i++) {
        float customer_sales = 0;
        int num_products = 0;
        for (int j = 0; j < customers[i].num_purchases; j++) {
            customer_sales += customers[i].purchases[j].price;
            if (strstr(customers[i].purchases[j].product, "Apple") != NULL) {
                num_products++;
            }
        }
        if (num_products > 5) {
            printf("Customer %d bought more than 5 Apple products!\n", customers[i].customer_id);
        }
        total_sales += customer_sales;
    }

    printf("Total sales: $%.2f\n", total_sales);

    return 0;
}