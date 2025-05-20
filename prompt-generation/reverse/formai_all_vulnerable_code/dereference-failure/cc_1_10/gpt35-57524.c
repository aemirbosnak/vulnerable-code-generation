//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure to store the personal finance data
struct personal_finance {
    char category[50];
    double total_income;
    double total_expense;
    double total_savings;
};

int main() {
    int n, i;
    double total_income = 0, total_expense = 0, total_savings = 0;
    
    //Taking the inputs from the user
    printf("Enter the number of categories: ");
    scanf("%d", &n);
    
    struct personal_finance *finance = (struct personal_finance*)malloc(n * sizeof(struct personal_finance));
    
    printf("Enter the data:\n");
    
    for(i=0; i<n; i++) {
        printf("Category %d:\n", i+1);
        
        printf("Enter the category name: ");
        scanf("%s", finance[i].category);
        
        printf("Enter the total income: ");
        scanf("%lf", &finance[i].total_income);
        total_income += finance[i].total_income;
        
        printf("Enter the total expense: ");
        scanf("%lf", &finance[i].total_expense);
        total_expense += finance[i].total_expense;
        
        finance[i].total_savings = finance[i].total_income - finance[i].total_expense;
        total_savings += finance[i].total_savings;
    }
    
    //Displaying the output
    printf("\n\nPersonal Finance Planner:\n\n");
    printf("| %-20s | %-20s | %-20s | %-20s |\n", "Category", "Total Income", "Total Expense", "Total Savings");
    printf("+---------------------+---------------------+---------------------+---------------------+\n");
    for(i=0; i<n; i++) {
        printf("| %-20s | %-20.2lf | %-20.2lf | %-20.2lf |\n", finance[i].category, finance[i].total_income, finance[i].total_expense, finance[i].total_savings);
    }
    printf("+---------------------+---------------------+---------------------+---------------------+\n");
    printf("| %-20s | %-20.2lf | %-20.2lf | %-20.2lf |\n", "Total", total_income, total_expense, total_savings);
    printf("+---------------------+---------------------+---------------------+---------------------+\n");
    
    //Freeing the dynamically allocated memory
    free(finance);
    return 0;
}