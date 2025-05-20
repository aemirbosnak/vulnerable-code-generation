//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the Romeo and Juliet types
typedef struct {
    char *name;
    int age;
    double income;
    double expenses;
} Romeo;

typedef struct {
    char *name;
    int age;
    double income;
    double expenses;
} Juliet;

// Declare the Romeo and Juliet functions
Romeo *createRomeo(char *name, int age, double income, double expenses);
Juliet *createJuliet(char *name, int age, double income, double expenses);
void printRomeo(Romeo *romeo);
void printJuliet(Juliet *juliet);
void calculateBudget(Romeo *romeo, Juliet *juliet);

// Define the main function
int main() {
    // Create Romeo and Juliet
    Romeo *romeo = createRomeo("Romeo", 20, 50000.0, 25000.0);
    Juliet *juliet = createJuliet("Juliet", 18, 40000.0, 20000.0);

    // Print Romeo and Juliet
    printRomeo(romeo);
    printJuliet(juliet);

    // Calculate the budget
    calculateBudget(romeo, juliet);

    // Free the memory allocated for Romeo and Juliet
    free(romeo);
    free(juliet);

    return 0;
}

// Define the createRomeo function
Romeo *createRomeo(char *name, int age, double income, double expenses) {
    // Allocate memory for the Romeo struct
    Romeo *romeo = (Romeo *)malloc(sizeof(Romeo));

    // Set the Romeo's name, age, income, and expenses
    romeo->name = strdup(name);
    romeo->age = age;
    romeo->income = income;
    romeo->expenses = expenses;

    // Return the Romeo struct
    return romeo;
}

// Define the createJuliet function
Juliet *createJuliet(char *name, int age, double income, double expenses) {
    // Allocate memory for the Juliet struct
    Juliet *juliet = (Juliet *)malloc(sizeof(Juliet));

    // Set the Juliet's name, age, income, and expenses
    juliet->name = strdup(name);
    juliet->age = age;
    juliet->income = income;
    juliet->expenses = expenses;

    // Return the Juliet struct
    return juliet;
}

// Define the printRomeo function
void printRomeo(Romeo *romeo) {
    // Print the Romeo's name, age, income, and expenses
    printf("Romeo's name: %s\n", romeo->name);
    printf("Romeo's age: %d\n", romeo->age);
    printf("Romeo's income: %.2f\n", romeo->income);
    printf("Romeo's expenses: %.2f\n", romeo->expenses);
}

// Define the printJuliet function
void printJuliet(Juliet *juliet) {
    // Print the Juliet's name, age, income, and expenses
    printf("Juliet's name: %s\n", juliet->name);
    printf("Juliet's age: %d\n", juliet->age);
    printf("Juliet's income: %.2f\n", juliet->income);
    printf("Juliet's expenses: %.2f\n", juliet->expenses);
}

// Define the calculateBudget function
void calculateBudget(Romeo *romeo, Juliet *juliet) {
    // Calculate the combined income and expenses
    double combinedIncome = romeo->income + juliet->income;
    double combinedExpenses = romeo->expenses + juliet->expenses;

    // Calculate the budget
    double budget = combinedIncome - combinedExpenses;

    // Print the budget
    printf("Romeo and Juliet's budget: %.2f\n", budget);
}