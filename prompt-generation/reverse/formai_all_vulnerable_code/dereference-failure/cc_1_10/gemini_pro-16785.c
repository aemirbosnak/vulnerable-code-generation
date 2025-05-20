//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an expense
typedef struct {
    char description[50];
    float amount;
    char category[20];
} Expense;

// Function to create a new expense
Expense* createExpense(char* description, float amount, char* category) {
    Expense* expense = (Expense*)malloc(sizeof(Expense));
    strcpy(expense->description, description);
    expense->amount = amount;
    strcpy(expense->category, category);
    return expense;
}

// Function to print an expense
void printExpense(Expense* expense) {
    printf("%-30s %.2f %s\n", expense->description, expense->amount, expense->category);
}

// Function to add an expense to the list
void addExpense(Expense** expenses, int* numExpenses, Expense* expense) {
    *expenses = (Expense*)realloc(*expenses, (*numExpenses + 1) * sizeof(Expense));
    (*expenses)[*numExpenses] = *expense;
    *numExpenses = *numExpenses + 1;
}

// Function to print the list of expenses
void printExpenses(Expense** expenses, int numExpenses) {
    printf("%-30s %.2f %s\n", "Description", "Amount", "Category");
    for (int i = 0; i < numExpenses; i++) {
        printExpense(expenses[i]);
    }
}

// Function to compare two expenses by amount
int compareExpensesByAmount(const void* a, const void* b) {
    Expense* expense1 = (Expense*)a;
    Expense* expense2 = (Expense*)b;
    return expense1->amount - expense2->amount;
}

// Function to compare two expenses by category
int compareExpensesByCategory(const void* a, const void* b) {
    Expense* expense1 = (Expense*)a;
    Expense* expense2 = (Expense*)b;
    return strcmp(expense1->category, expense2->category);
}

// Function to sort the list of expenses by amount
void sortExpensesByAmount(Expense** expenses, int numExpenses) {
    qsort(expenses, numExpenses, sizeof(Expense), compareExpensesByAmount);
}

// Function to sort the list of expenses by category
void sortExpensesByCategory(Expense** expenses, int numExpenses) {
    qsort(expenses, numExpenses, sizeof(Expense), compareExpensesByCategory);
}

// Function to get the total amount of expenses
float getTotalAmount(Expense** expenses, int numExpenses) {
    float totalAmount = 0;
    for (int i = 0; i < numExpenses; i++) {
        totalAmount += expenses[i]->amount;
    }
    return totalAmount;
}

// Function to get the average amount of expenses
float getAverageAmount(Expense** expenses, int numExpenses) {
    float averageAmount = 0;
    if (numExpenses > 0) {
        averageAmount = getTotalAmount(expenses, numExpenses) / numExpenses;
    }
    return averageAmount;
}

// Function to get the maximum amount of expenses
float getMaxAmount(Expense** expenses, int numExpenses) {
    float maxAmount = 0;
    for (int i = 0; i < numExpenses; i++) {
        if (expenses[i]->amount > maxAmount) {
            maxAmount = expenses[i]->amount;
        }
    }
    return maxAmount;
}

// Function to get the minimum amount of expenses
float getMinAmount(Expense** expenses, int numExpenses) {
    float minAmount = 0;
    for (int i = 0; i < numExpenses; i++) {
        if (expenses[i]->amount < minAmount) {
            minAmount = expenses[i]->amount;
        }
    }
    return minAmount;
}

// Function to get the most frequent category of expenses
char* getMostFrequentCategory(Expense** expenses, int numExpenses) {
    char* mostFrequentCategory = NULL;
    int maxCount = 0;
    for (int i = 0; i < numExpenses; i++) {
        int count = 0;
        for (int j = 0; j < numExpenses; j++) {
            if (strcmp(expenses[i]->category, expenses[j]->category) == 0) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mostFrequentCategory = expenses[i]->category;
        }
    }
    return mostFrequentCategory;
}

// Function to get the least frequent category of expenses
char* getLeastFrequentCategory(Expense** expenses, int numExpenses) {
    char* leastFrequentCategory = NULL;
    int minCount = numExpenses;
    for (int i = 0; i < numExpenses; i++) {
        int count = 0;
        for (int j = 0; j < numExpenses; j++) {
            if (strcmp(expenses[i]->category, expenses[j]->category) == 0) {
                count++;
            }
        }
        if (count < minCount) {
            minCount = count;
            leastFrequentCategory = expenses[i]->category;
        }
    }
    return leastFrequentCategory;
}

// Main function
int main() {
    // Create an array of expenses
    Expense* expenses[100];
    int numExpenses = 0;

    // Add some expenses to the array
    addExpense(expenses, &numExpenses, createExpense("Groceries", 100.00, "Food"));
    addExpense(expenses, &numExpenses, createExpense("Gas", 50.00, "Transportation"));
    addExpense(expenses, &numExpenses, createExpense("Electricity", 150.00, "Utilities"));
    addExpense(expenses, &numExpenses, createExpense("Rent", 1200.00, "Housing"));
    addExpense(expenses, &numExpenses, createExpense("Entertainment", 50.00, "Recreation"));
    addExpense(expenses, &numExpenses, createExpense("Clothing", 100.00, "Apparel"));
    addExpense(expenses, &numExpenses, createExpense("Healthcare", 100.00, "Medical"));
    addExpense(expenses, &numExpenses, createExpense("Education", 200.00, "Education"));

    // Print the list of expenses
    printf("Original list of expenses:\n");
    printExpenses(expenses, numExpenses);

    // Sort the list of expenses by amount
    sortExpensesByAmount(expenses, numExpenses);

    // Print the sorted list of expenses by amount
    printf("\nList of expenses sorted by amount:\n");
    printExpenses(expenses, numExpenses);

    // Sort the list of expenses by category
    sortExpensesByCategory(expenses, numExpenses);

    // Print the sorted list of expenses by category
    printf("\nList of expenses sorted by category:\n");
    printExpenses(expenses, numExpenses);

    // Get the total amount of expenses
    float totalAmount = getTotalAmount(expenses, numExpenses);

    // Get the average amount of expenses
    float averageAmount = getAverageAmount(expenses, numExpenses);

    // Get the maximum amount of expenses
    float maxAmount = getMaxAmount(expenses, numExpenses);

    // Get the minimum amount of expenses
    float minAmount = getMinAmount(expenses, numExpenses);

    // Get the most frequent category of expenses
    char* mostFrequentCategory = getMostFrequentCategory(expenses, numExpenses);

    // Get the least frequent category of expenses
    char* leastFrequentCategory = getLeastFrequentCategory(expenses, numExpenses);

    // Print the summary of expenses
    printf("\nSummary of expenses:\n");
    printf("Total amount: %.2f\n", totalAmount);
    printf("Average amount: %.2f\n", averageAmount);
    printf("Maximum amount: %.2f\n", maxAmount);
    printf("Minimum amount: %.2f\n", minAmount);
    printf("Most frequent category: %s\n", mostFrequentCategory);
    printf("Least frequent category: %s\n", leastFrequentCategory);

    return 0;
}