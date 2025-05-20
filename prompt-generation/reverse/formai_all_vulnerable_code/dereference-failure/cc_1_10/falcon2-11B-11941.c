//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the total price of an item
int calculate_price(int quantity, int price) {
    return quantity * price;
}

// Function to generate a random number between 0 and 9
int generate_random_number(void) {
    srand(time(NULL));
    return (rand() % 10) + 0;
}

// Function to print the bill for a customer
void print_bill(char* customer_name, int total_price) {
    printf("Bill for %s:\n", customer_name);
    printf("Total price: %.2f\n", total_price);
}

// Function to add items to the bill
void add_to_bill(char* customer_name, int item_price, int item_quantity) {
    int total_price = calculate_price(item_quantity, item_price);
    int total_bill = total_price + generate_random_number();
    printf("Added item %d (%d units) for %s: %.2f\n", item_price, item_quantity, customer_name, total_bill);
    print_bill(customer_name, total_bill);
}

// Function to add items to the bill for all customers
void add_to_bill_for_all_customers(char** customer_names, int** item_prices, int** item_quantities, int total_bill) {
    int i;
    for (i = 0; i < 10; i++) {
        add_to_bill(customer_names[i], item_prices[i], item_quantities[i]);
    }
}

int main(void) {
    char** customer_names = malloc(10 * sizeof(char*));
    int** item_prices = malloc(10 * sizeof(int*));
    int** item_quantities = malloc(10 * sizeof(int*));
    int i;

    for (i = 0; i < 10; i++) {
        customer_names[i] = malloc(10 * sizeof(char));
        item_prices[i] = malloc(10 * sizeof(int));
        item_quantities[i] = malloc(10 * sizeof(int));

        sprintf(customer_names[i], "Customer %d", i + 1);
        srand(time(NULL));
        for (int j = 0; j < 10; j++) {
            item_prices[i][j] = generate_random_number();
            item_quantities[i][j] = generate_random_number();
        }
    }

    add_to_bill_for_all_customers(customer_names, item_prices, item_quantities, 0);

    return 0;
}