//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[256];
    char address[256];
    char phone[256];
} Person;

typedef struct {
    int id;
    char name[256];
    char description[256];
} Product;

typedef struct {
    int id;
    Person *person;
    Product *product;
    int quantity;
} Order;

typedef struct {
    int id;
    char name[256];
    Person *owner;
    Order **orders;
    int num_orders;
} Company;

void create_person(Person *person, int id, char *name, char *address, char *phone) {
    person->id = id;
    strcpy(person->name, name);
    strcpy(person->address, address);
    strcpy(person->phone, phone);
}

void create_product(Product *product, int id, char *name, char *description) {
    product->id = id;
    strcpy(product->name, name);
    strcpy(product->description, description);
}

void create_order(Order *order, int id, Person *person, Product *product, int quantity) {
    order->id = id;
    order->person = person;
    order->product = product;
    order->quantity = quantity;
}

void create_company(Company *company, int id, char *name, Person *owner) {
    company->id = id;
    strcpy(company->name, name);
    company->owner = owner;
    company->orders = NULL;
    company->num_orders = 0;
}

void add_order_to_company(Company *company, Order *order) {
    company->orders = realloc(company->orders, (company->num_orders + 1) * sizeof(Order *));
    company->orders[company->num_orders++] = order;
}

void print_person(Person *person) {
    printf("Person:\n");
    printf("ID: %d\n", person->id);
    printf("Name: %s\n", person->name);
    printf("Address: %s\n", person->address);
    printf("Phone: %s\n", person->phone);
    printf("\n");
}

void print_product(Product *product) {
    printf("Product:\n");
    printf("ID: %d\n", product->id);
    printf("Name: %s\n", product->name);
    printf("Description: %s\n", product->description);
    printf("\n");
}

void print_order(Order *order) {
    printf("Order:\n");
    printf("ID: %d\n", order->id);
    print_person(order->person);
    print_product(order->product);
    printf("Quantity: %d\n", order->quantity);
    printf("\n");
}

void print_company(Company *company) {
    printf("Company:\n");
    printf("ID: %d\n", company->id);
    printf("Name: %s\n", company->name);
    print_person(company->owner);
    printf("Orders:\n");
    for (int i = 0; i < company->num_orders; i++) {
        print_order(company->orders[i]);
    }
    printf("\n");
}

int main() {
    Person person;
    Product product;
    Order order;
    Company company;

    create_person(&person, 1, "John Smith", "123 Main Street", "555-1212");
    create_product(&product, 1, "Widget", "A small, plastic widget");
    create_order(&order, 1, &person, &product, 10);
    create_company(&company, 1, "Acme Corporation", &person);
    add_order_to_company(&company, &order);

    print_person(&person);
    print_product(&product);
    print_order(&order);
    print_company(&company);

    return 0;
}