//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a customer
struct customer {
    char name[50];
    char address[100];
    int age;
};

// Define the structure for a order
struct order {
    int order_id;
    struct customer customer;
    int total_amount;
};

// Define the structure for a restaurant
struct restaurant {
    char name[50];
    int capacity;
    struct order orders[5];
};

// Function to read customer information
void read_customer(struct customer *cust) {
    printf("Enter customer name: ");
    scanf("%s", cust->name);
    printf("Enter customer address: ");
    scanf("%s", cust->address);
    printf("Enter customer age: ");
    scanf("%d", &cust->age);
}

// Function to read order information
void read_order(struct order *ord) {
    printf("Enter order id: ");
    scanf("%d", &ord->order_id);
    printf("Enter customer name: ");
    scanf("%s", ord->customer.name);
    printf("Enter total amount: ");
    scanf("%d", &ord->total_amount);
}

// Function to read restaurant information
void read_restaurant(struct restaurant *rest) {
    printf("Enter restaurant name: ");
    scanf("%s", rest->name);
    printf("Enter restaurant capacity: ");
    scanf("%d", &rest->capacity);
}

// Function to add an order to a restaurant
void add_order(struct restaurant *rest, struct order *ord) {
    rest->orders[rest->capacity - 1] = *ord;
    rest->capacity--;
}

// Function to print the orders of a restaurant
void print_orders(struct restaurant *rest) {
    int i;
    for (i = 0; i < rest->capacity; i++) {
        printf("%d. Order ID: %d, Customer Name: %s, Total Amount: %d\n",
            i + 1, rest->orders[i].order_id, rest->orders[i].customer.name, rest->orders[i].total_amount);
    }
}

int main() {
    struct restaurant rest1, rest2;
    struct customer cust1, cust2;
    struct order ord1, ord2;

    // Read restaurant information
    read_restaurant(&rest1);
    read_restaurant(&rest2);

    // Read customer information
    read_customer(&cust1);
    read_customer(&cust2);

    // Add orders to the restaurants
    add_order(&rest1, &ord1);
    add_order(&rest2, &ord2);

    // Print the orders of the restaurants
    print_orders(&rest1);
    print_orders(&rest2);

    return 0;
}