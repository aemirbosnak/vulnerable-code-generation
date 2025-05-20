//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 100

typedef struct {
    char name[100];
    int id;
    char address[100];
    int balance;
} Customer;

Customer customers[MAX_CUSTOMERS];
int num_customers = 0;

void *add_customer(void *ptr) {
    Customer *c = (Customer*)ptr;

    printf("Adding customer: %s - %d - %s - %d\n", c->name, c->id, c->address, c->balance);
    pthread_exit(0);
}

void *remove_customer(void *ptr) {
    Customer *c = (Customer*)ptr;

    printf("Removing customer: %s - %d - %s - %d\n", c->name, c->id, c->address, c->balance);
    pthread_exit(0);
}

int main() {
    pthread_t threads[4];

    for (int i = 0; i < 4; i++) {
        Customer c = {"John Doe", 1, "123 Main St", 1000};
        pthread_create(&threads[i], NULL, add_customer, &c);
    }

    for (int i = 0; i < 4; i++) {
        Customer c = {"Jane Smith", 2, "456 Elm St", 2000};
        pthread_create(&threads[i], NULL, remove_customer, &c);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Customer list:\n");
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        if (customers[i].balance > 0) {
            printf("%d - %s - %d - %d\n", i, customers[i].name, customers[i].id, customers[i].balance);
        }
    }

    printf("Store balance: %d\n", num_customers);

    return 0;
}