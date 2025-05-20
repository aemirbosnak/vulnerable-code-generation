//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Customer data structure
typedef struct customer {
    int id;
    char name[256];
    char address[256];
    char phone[256];
    char email[256];
} customer;

// Product data structure
typedef struct product {
    int id;
    char name[256];
    char description[256];
    float price;
    int quantity;
} product;

// Sale data structure
typedef struct sale {
    int id;
    int customer_id;
    int product_id;
    int quantity;
    float total;
} sale;

// Create a new customer
customer* create_customer(int id, char* name, char* address, char* phone, char* email) {
    // Allocate memory for the new customer
    customer* c = malloc(sizeof(customer));

    // Set the customer's data
    c->id = id;
    strcpy(c->name, name);
    strcpy(c->address, address);
    strcpy(c->phone, phone);
    strcpy(c->email, email);

    // Return the new customer
    return c;
}

// Create a new product
product* create_product(int id, char* name, char* description, float price, int quantity) {
    // Allocate memory for the new product
    product* p = malloc(sizeof(product));

    // Set the product's data
    p->id = id;
    strcpy(p->name, name);
    strcpy(p->description, description);
    p->price = price;
    p->quantity = quantity;

    // Return the new product
    return p;
}

// Create a new sale
sale* create_sale(int id, int customer_id, int product_id, int quantity, float total) {
    // Allocate memory for the new sale
    sale* s = malloc(sizeof(sale));

    // Set the sale's data
    s->id = id;
    s->customer_id = customer_id;
    s->product_id = product_id;
    s->quantity = quantity;
    s->total = total;

    // Return the new sale
    return s;
}

// Print a customer
void print_customer(customer* c) {
    // Print the customer's data
    printf("Customer ID: %d\n", c->id);
    printf("Customer Name: %s\n", c->name);
    printf("Customer Address: %s\n", c->address);
    printf("Customer Phone: %s\n", c->phone);
    printf("Customer Email: %s\n", c->email);
}

// Print a product
void print_product(product* p) {
    // Print the product's data
    printf("Product ID: %d\n", p->id);
    printf("Product Name: %s\n", p->name);
    printf("Product Description: %s\n", p->description);
    printf("Product Price: %.2f\n", p->price);
    printf("Product Quantity: %d\n", p->quantity);
}

// Print a sale
void print_sale(sale* s) {
    // Print the sale's data
    printf("Sale ID: %d\n", s->id);
    printf("Customer ID: %d\n", s->customer_id);
    printf("Product ID: %d\n", s->product_id);
    printf("Quantity: %d\n", s->quantity);
    printf("Total: %.2f\n", s->total);
}

// Main function
int main() {
    // Create some customers
    customer* c1 = create_customer(1, "John Doe", "123 Main Street", "555-123-4567", "john.doe@example.com");
    customer* c2 = create_customer(2, "Jane Doe", "456 Elm Street", "555-234-5678", "jane.doe@example.com");

    // Create some products
    product* p1 = create_product(1, "Apple", "A delicious, red fruit", 1.00, 10);
    product* p2 = create_product(2, "Orange", "A juicy, citrus fruit", 1.50, 15);
    product* p3 = create_product(3, "Banana", "A yellow, curved fruit", 0.75, 20);

    // Create some sales
    sale* s1 = create_sale(1, c1->id, p1->id, 2, 2.00);
    sale* s2 = create_sale(2, c2->id, p2->id, 3, 4.50);
    sale* s3 = create_sale(3, c1->id, p3->id, 5, 3.75);

    // Print the customers, products, and sales
    printf("Customers:\n");
    print_customer(c1);
    print_customer(c2);

    printf("\nProducts:\n");
    print_product(p1);
    print_product(p2);
    print_product(p3);

    printf("\nSales:\n");
    print_sale(s1);
    print_sale(s2);
    print_sale(s3);

    // Free the memory allocated for the customers, products, and sales
    free(c1);
    free(c2);
    free(p1);
    free(p2);
    free(p3);
    free(s1);
    free(s2);
    free(s3);

    return 0;
}