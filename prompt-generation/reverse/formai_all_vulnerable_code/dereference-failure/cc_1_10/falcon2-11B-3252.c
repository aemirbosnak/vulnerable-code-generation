//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: scalable
#include <stdio.h>
#include <string.h>

// Define a structure for the customer
typedef struct customer {
    char name[100];
    int age;
    float balance;
} Customer;

// Define a structure for the meal
typedef struct meal {
    char name[100];
    float price;
} Meal;

// Function to add a customer
Customer *add_customer(Customer *cust, char *name, int age) {
    strcpy(cust->name, name);
    cust->age = age;
    cust->balance = 0.0;
    return cust;
}

// Function to add a meal
Meal *add_meal(Meal *meal, char *name, float price) {
    strcpy(meal->name, name);
    meal->price = price;
    return meal;
}

// Function to display customer information
void display_customer(Customer *cust) {
    printf("Customer Name: %s\n", cust->name);
    printf("Customer Age: %d\n", cust->age);
    printf("Customer Balance: $%.2f\n", cust->balance);
}

// Function to display meal information
void display_meal(Meal *meal) {
    printf("Meal Name: %s\n", meal->name);
    printf("Meal Price: $%.2f\n", meal->price);
}

// Function to add a meal to a customer's bill
void add_meal_to_bill(Customer *cust, Meal *meal) {
    cust->balance += meal->price;
}

// Function to display the customer's bill
void display_bill(Customer *cust) {
    printf("Customer Name: %s\n", cust->name);
    printf("Customer Age: %d\n", cust->age);
    printf("Customer Balance: $%.2f\n", cust->balance);
}

// Function to calculate the total bill
float calculate_total_bill(Customer *cust, int num_meals) {
    float total_bill = 0.0;
    for (int i = 0; i < num_meals; i++) {
        total_bill += cust->balance;
    }
    return total_bill;
}

// Function to process a customer's order
void process_order(Customer *cust, int num_meals) {
    for (int i = 0; i < num_meals; i++) {
        Meal *meal = add_meal(NULL, "Meal " + (i+1), 9.99);
        add_meal_to_bill(cust, meal);
        free(meal);
    }
}

// Main function
int main() {
    Customer cust1 = {"John", 25, 0.0};
    Customer cust2 = {"Jane", 30, 0.0};
    Meal meal1 = {"Burger", 5.99};
    Meal meal2 = {"Fries", 2.99};
    Meal meal3 = {"Drink", 1.99};

    Customer *custs[] = {&cust1, &cust2};
    Meal *meals[] = {&meal1, &meal2, &meal3};

    for (int i = 0; i < sizeof(custs) / sizeof(custs[0]); i++) {
        printf("Enter customer name: ");
        scanf("%s", custs[i]->name);
        custs[i]->age = i + 1;

        for (int j = 0; j < sizeof(meals) / sizeof(meals[0]); j++) {
            printf("Enter meal name: ");
            scanf("%s", meals[j]->name);
            printf("Enter meal price: $");
            scanf("%f", &meals[j]->price);

            process_order(custs[i], 1);
        }

        printf("Customer %s's bill:\n", custs[i]->name);
        display_bill(custs[i]);
    }

    return 0;
}