//FormAI DATASET v1.0 Category: Expense Tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct Expense {
    char item[MAX];
    float cost;
    char date[MAX];
};

int main() {
    int num_expenses, choice;
    float total_spent = 0.0;
    printf("Enter the number of expenses to track: ");
    scanf("%d", &num_expenses);
    struct Expense expenses[num_expenses];
    
    for(int i=0; i<num_expenses; i++){
        printf("\nEnter item name: ");
        scanf("%s", expenses[i].item);
        printf("Enter cost of item: ");
        scanf("%f", &expenses[i].cost);
        printf("Enter date of purchase (MM/DD/YYYY): ");
        scanf("%s", expenses[i].date);
    }
    
    printf("\n\nEXPENSES TRACKED:\n");
    printf("%-20s %-10s %-10s\n","ITEM","COST","DATE");
    for(int i=0; i<num_expenses; i++){
        printf("%-20s %-10.2f %-10s\n", expenses[i].item, expenses[i].cost, expenses[i].date);
        total_spent += expenses[i].cost;
    }
    printf("Total spent: $%.2f\n", total_spent);
    
    while(1){
        printf("\n\nWhat would you like to do now?\n");
        printf("1) Search expenses by date\n");
        printf("2) Add new expense\n");
        printf("3) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if(choice == 1){
            char search_date[MAX];
            printf("\nEnter the date to search (MM/DD/YYYY): ");
            scanf("%s", search_date);
            printf("\nEXPENSES ON %s:\n",search_date);
            printf("%-20s %-10s %-10s\n","ITEM","COST","DATE");
            for(int i=0; i<num_expenses; i++){
                if(strcmp(search_date, expenses[i].date)==0){
                    printf("%-20s %-10.2f %-10s\n", expenses[i].item, expenses[i].cost, expenses[i].date);
                }
            }
        }
        else if(choice == 2){
            printf("\nEnter the item name: ");
            scanf("%s", expenses[num_expenses].item);
            printf("Enter the cost of item: ");
            scanf("%f", &expenses[num_expenses].cost);
            printf("Enter the date of purchase (MM/DD/YYYY): ");
            scanf("%s", expenses[num_expenses].date);
            num_expenses++;
            printf("\nExpense added successfully!\n");
        }
        else if(choice == 3){
            printf("\nThank you for using the expense tracker!\n");
            exit(0);
        }
        else{
            printf("\nInvalid choice! Please try again.\n");
        }
    }   
    
    return 0;
}