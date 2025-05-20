//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the data structure for each customer
typedef struct {
    char name[50];
    int num_items;
    double total_amount;
} Customer;

// Define a function to create a new customer
Customer* create_customer(const char* name, int num_items, double total_amount) {
    Customer* customer = (Customer*) malloc(sizeof(Customer));
    strcpy(customer->name, name);
    customer->num_items = num_items;
    customer->total_amount = total_amount;
    return customer;
}

// Define a function to process a customer's order
void process_order(Customer* customer) {
    // Simulate processing the order by sleeping for a random amount of time
    sleep(rand() % 5);
    printf("Processing order for %s...\n", customer->name);
}

// Define a function to calculate the total bill for a customer
void calculate_bill(Customer* customer) {
    // Simulate calculating the total bill by sleeping for a random amount of time
    sleep(rand() % 5);
    printf("Calculating bill for %s...\n", customer->name);
}

// Define a function to print the final bill for a customer
void print_bill(Customer* customer) {
    // Simulate printing the final bill by sleeping for a random amount of time
    sleep(rand() % 5);
    printf("Printing final bill for %s...\n", customer->name);
}

// Define a function to simulate the billing process for a customer
void* billing_process(void* customer) {
    Customer* c = (Customer*) customer;

    // Process the order
    process_order(c);

    // Calculate the bill
    calculate_bill(c);

    // Print the final bill
    print_bill(c);

    free(c);

    return NULL;
}

// Define a function to create a new thread for each customer
void* create_customer_thread(void* customer) {
    Customer* c = (Customer*) customer;

    // Create a new thread for the billing process
    pthread_t t;
    pthread_create(&t, NULL, billing_process, c);

    // Wait for the billing process to complete
    pthread_join(t, NULL);

    return NULL;
}

// Define a function to create customers and start the billing process
void create_customers() {
    // Create customers
    Customer* c1 = create_customer("John", 2, 10.0);
    Customer* c2 = create_customer("Jane", 1, 5.0);
    Customer* c3 = create_customer("Bob", 3, 15.0);

    // Create threads for each customer
    pthread_t t1, t2, t3;
    pthread_create(&t1, NULL, create_customer_thread, c1);
    pthread_create(&t2, NULL, create_customer_thread, c2);
    pthread_create(&t3, NULL, create_customer_thread, c3);

    // Wait for all threads to complete
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    // Free the customers
    free(c1);
    free(c2);
    free(c3);
}

// Define the main function
int main() {
    // Create customers
    create_customers();

    return 0;
}