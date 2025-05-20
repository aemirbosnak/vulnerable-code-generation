//FormAI DATASET v1.0 Category: Database querying ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining struct to store information of customers
typedef struct {
    char name[50];
    int age;
    char address[100];
    double balance;
} customer;

// Defining struct to store information of orders
typedef struct {
    int order_id;
    char order_date[20];
    char customer_name[50];
    double order_total;
} order;

// Function to read customers data from file
void read_customers_data(customer* customers, int num_customers) {
    FILE* fp = fopen("customers.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to read customers data!\n");
        exit(1);
    }

    for (int i = 0; i < num_customers; i++) {
        fscanf(fp, "%s %d %s %lf", customers[i].name, &customers[i].age, customers[i].address, &customers[i].balance);
    }

    fclose(fp);
}

// Function to read orders data from file
void read_orders_data(order* orders, int num_orders) {
    FILE* fp = fopen("orders.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to read orders data!\n");
        exit(1);
    }

    for (int i = 0; i < num_orders; i++) {
        fscanf(fp, "%d %s %s %lf", &orders[i].order_id, orders[i].order_date, orders[i].customer_name, &orders[i].order_total);
    }

    fclose(fp);
}

int main() {
    // Initializing variables
    int num_customers = 5;
    int num_orders = 10;
    int customer_age;
    double order_amount;
    
    // Creating arrays to store customers and orders data
    customer* customers = (customer*)malloc(num_customers * sizeof(customer));
    order* orders = (order*)malloc(num_orders * sizeof(order));
    
    // Reading customers and orders data from files
    read_customers_data(customers, num_customers);
    read_orders_data(orders, num_orders);
    
    // Getting input from user
    printf("Enter customer age: ");
    scanf("%d", &customer_age);
    
    printf("Enter order amount: ");
    scanf("%lf", &order_amount);
    
    printf("\nOrders with total greater than %.2lf and customer age less than %d:\n", order_amount, customer_age);
    printf("Order ID     Order Date      Customer Name       Order Total\n");
    printf("--------------------------------------------------------------\n");
    
    // Looping through orders to find relevant ones
    for (int i = 0; i < num_orders; i++) {
        if (orders[i].order_total > order_amount) {
            for (int j = 0; j < num_customers; j++) {
                if (strcmp(orders[i].customer_name, customers[j].name) == 0 && customers[j].age < customer_age) {
                    printf("%-12d%-16s%-20s$%-10.2lf\n", orders[i].order_id, orders[i].order_date, orders[i].customer_name, orders[i].order_total);
                }
            }
        }
    }
    
    // Freeing dynamically allocated memory
    free(customers);
    free(orders);
    
    return 0;
}