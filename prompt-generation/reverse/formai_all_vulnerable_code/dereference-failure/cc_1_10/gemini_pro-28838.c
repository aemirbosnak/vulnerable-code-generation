//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
typedef struct MenuItem {
    char *name;
    double price;
} MenuItem;

MenuItem menuItems[] = {
    {"Coffee", 2.50},
    {"Tea", 1.50},
    {"Soda", 1.75},
    {"Water", 1.00},
    {"Pastry", 2.00}
};

// Define the order struct
typedef struct Order {
    int itemIndex;
    int quantity;
} Order;

// Define the customer struct
typedef struct Customer {
    char *name;
    Order *orders;
    int numOrders;
} Customer;

// Define the cafe struct
typedef struct Cafe {
    Customer *customers;
    int numCustomers;
} Cafe;

// Create a new cafe
Cafe *createCafe() {
    Cafe *cafe = malloc(sizeof(Cafe));
    cafe->customers = NULL;
    cafe->numCustomers = 0;
    return cafe;
}

// Add a customer to the cafe
void addCustomer(Cafe *cafe, Customer *customer) {
    cafe->customers = realloc(cafe->customers, (cafe->numCustomers + 1) * sizeof(Customer));
    cafe->customers[cafe->numCustomers] = *customer;
    cafe->numCustomers++;
}

// Create a new customer
Customer *createCustomer(char *name) {
    Customer *customer = malloc(sizeof(Customer));
    customer->name = name;
    customer->orders = NULL;
    customer->numOrders = 0;
    return customer;
}

// Add an order to a customer
void addOrder(Customer *customer, Order *order) {
    customer->orders = realloc(customer->orders, (customer->numOrders + 1) * sizeof(Order));
    customer->orders[customer->numOrders] = *order;
    customer->numOrders++;
}

// Create a new order
Order *createOrder(int itemIndex, int quantity) {
    Order *order = malloc(sizeof(Order));
    order->itemIndex = itemIndex;
    order->quantity = quantity;
    return order;
}

// Calculate the total price of an order
double calculateOrderTotal(Order *order) {
    return menuItems[order->itemIndex].price * order->quantity;
}

// Calculate the total price of a customer's orders
double calculateCustomerTotal(Customer *customer) {
    double total = 0;
    for (int i = 0; i < customer->numOrders; i++) {
        total += calculateOrderTotal(&customer->orders[i]);
    }
    return total;
}

// Print the cafe's menu
void printMenu() {
    printf("Menu:\n");
    for (int i = 0; i < sizeof(menuItems) / sizeof(MenuItem); i++) {
        printf("%d. %s - $%.2f\n", i + 1, menuItems[i].name, menuItems[i].price);
    }
}

// Print a customer's orders
void printCustomerOrders(Customer *customer) {
    printf("Orders for %s:\n", customer->name);
    for (int i = 0; i < customer->numOrders; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menuItems[customer->orders[i].itemIndex].name, calculateOrderTotal(&customer->orders[i]));
    }
}

// Print the cafe's total sales
double calculateTotalSales(Cafe *cafe) {
    double total = 0;
    for (int i = 0; i < cafe->numCustomers; i++) {
        total += calculateCustomerTotal(&cafe->customers[i]);
    }
    return total;
}

// Main function
int main() {
    // Create a new cafe
    Cafe *cafe = createCafe();

    // Add some customers to the cafe
    Customer *customer1 = createCustomer("John Doe");
    addCustomer(cafe, customer1);
    Customer *customer2 = createCustomer("Jane Doe");
    addCustomer(cafe, customer2);

    // Add some orders to the customers
    Order *order1 = createOrder(0, 2);
    addOrder(customer1, order1);
    Order *order2 = createOrder(1, 1);
    addOrder(customer1, order2);
    Order *order3 = createOrder(2, 3);
    addOrder(customer2, order3);
    Order *order4 = createOrder(3, 2);
    addOrder(customer2, order4);

    // Print the cafe's menu
    printMenu();

    // Print the customers' orders
    printCustomerOrders(customer1);
    printCustomerOrders(customer2);

    // Print the cafe's total sales
    printf("Total sales: $%.2f\n", calculateTotalSales(cafe));

    return 0;
}