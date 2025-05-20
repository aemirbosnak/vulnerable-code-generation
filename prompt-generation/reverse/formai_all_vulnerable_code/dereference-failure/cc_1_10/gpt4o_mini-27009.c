//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Expense {
    char description[50];
    float amount;
    struct Expense *next;
} Expense;

Expense *head = NULL;

void addExpense(char *description, float amount) {
    Expense *new_expense = (Expense *)malloc(sizeof(Expense));
    strcpy(new_expense->description, description);
    new_expense->amount = amount;
    new_expense->next = head;
    head = new_expense;
    printf("✨ Expense Added: %s | Amount: $%.2f\n", description, amount);
}

void viewExpenses() {
    if (head == NULL) {
        printf("📅 No expenses recorded yet!\n");
        return;
    }
    printf("\n💸 Your Expenses:\n");
    Expense *current = head;
    while (current != NULL) {
        printf("- %s: $%.2f\n", current->description, current->amount);
        current = current->next;
    }
    printf("\n");
}

void removeExpense(char *description) {
    Expense *current = head;
    Expense *previous = NULL;

    while (current != NULL && strcmp(current->description, description) != 0) {
        previous = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("❌ Expense not found: %s\n", description);
        return;
    }
    
    if (previous == NULL) {
        head = current->next; // Remove first node
    } else {
        previous->next = current->next; // Remove middle or last node
    }
    
    free(current);
    printf("✅ Expense Removed: %s\n", description);
}

void displayMenu() {
    printf("\n---- Welcome to the Expense Tracker! ----\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Remove Expense\n");
    printf("4. Exit\n");
    printf("-----------------------------------------\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char description[50];
    float amount;

    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // Add Expense
                printf("🎈 Enter Expense Description: ");
                scanf("%s", description);
                printf("💰 Enter Expense Amount: ");
                scanf("%f", &amount);
                addExpense(description, amount);
                break;
            case 2: // View Expenses
                viewExpenses();
                break;
            case 3: // Remove Expense
                printf("🗑️ Enter Expense Description to Remove: ");
                scanf("%s", description);
                removeExpense(description);
                break;
            case 4: // Exit
                printf("🚪 Exiting. Thank you for using the Expense Tracker!\n");
                break;
            default:
                printf("❗ Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 4);

    // Freeing up the expenses list before exit
    while (head != NULL) {
        Expense *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}