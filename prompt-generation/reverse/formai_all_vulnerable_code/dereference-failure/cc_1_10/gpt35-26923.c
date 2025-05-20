//FormAI DATASET v1.0 Category: Product Inventory System ; Style: visionary
#include <stdio.h>
#include <unistd.h>

#define MAX_PRODUCTS 100

struct Product {
    int id;
    char name[50];
    int quantity;
    float cost;
};

struct Customer {
    int id;
    char name[50];
    int age;
    char gender[10];
    float balance;
};

int num_products = 0; // Keeps track of how many products we have
int num_customers = 0; // Keeps track of how many customers we have
struct Product products[MAX_PRODUCTS]; // Array of products
struct Customer customers[MAX_PRODUCTS]; // Array of customers

int add_product(char name[], int quantity, float cost) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Product inventory is full.\n");
        return 0;
    }
    struct Product product;
    product.id = num_products + 1;
    strcpy(product.name, name);
    product.quantity = quantity;
    product.cost = cost;
    products[num_products] = product;
    num_products++;
    return 1;
}

int add_customer(char name[], int age, char gender[], float balance) {
    if (num_customers >= MAX_PRODUCTS) {
        printf("Error: Customer list is full.\n");
        return 0;
    }
    struct Customer customer;
    customer.id = num_customers + 1;
    strcpy(customer.name, name);
    customer.age = age;
    strcpy(customer.gender, gender);
    customer.balance = balance;
    customers[num_customers] = customer; 
    num_customers++;
    return 1;
}

int main() {
    printf("Welcome to the Product Inventory System\n");
    sleep(2);
    printf("Please enter a command:\n");
    printf("add_product <name> <quantity> <cost>\n");
    printf("add_customer <name> <age> <gender> <balance>\n");
    printf("list_products\n");
    printf("list_customers\n");
    printf("exit\n");
    char input[100];
    while(1) {
        fgets(input, 100, stdin);
        char *token = strtok(input, " ");
        if (strcmp(token, "add_product") == 0) {
            char name[50];
            int quantity;
            float cost;
            token = strtok(NULL, " ");
            strcpy(name, token);
            token = strtok(NULL, " ");
            quantity = atoi(token);
            token = strtok(NULL, " ");
            cost = atof(token);
            int result = add_product(name, quantity, cost);
            if (result == 1) {
                printf("Product added successfully.\n");
            }
        } else if (strcmp(token, "add_customer") == 0) {
            char name[50];
            int age;
            char gender[10];
            float balance;
            token = strtok(NULL, " ");
            strcpy(name, token);
            token = strtok(NULL, " ");
            age = atoi(token);
            token = strtok(NULL, " ");
            strcpy(gender, token);
            token = strtok(NULL, " ");
            balance = atof(token);
            int result = add_customer(name, age, gender, balance);
            if (result == 1) {
                printf("Customer added successfully.\n");
            }
        } else if (strcmp(token, "list_products") == 0) {
            printf("Product Inventory List:\n");
            for (int i = 0; i < num_products; i++) {
                printf("ID: %d\t Name: %s\t Quantity: %d\t Cost: %g\n", products[i].id, products[i].name, products[i].quantity, products[i].cost);
            }
        } else if (strcmp(token, "list_customers") == 0) {
            printf("Customer List:\n");
            for (int i = 0; i < num_customers; i++) {
                printf("ID: %d\t Name: %s\t Age: %d\t Gender: %s\t Balance: %g\n", customers[i].id, customers[i].name, customers[i].age, customers[i].gender, customers[i].balance);
            }
        } else if (strcmp(token, "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid command, please try again.\n");
        }
    }
    return 0;
}