//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct Entry {
    int id;
    char description[50];
    float amount;
    struct Entry* next;
} Entry;

Entry* head = NULL;
int count = 0;

void addExpense(char description[], float amount);
void viewExpenses(Entry* entry);
void deleteExpense(int id);
void freeList(Entry* entry);
void displayMenu();
void processMenuChoice(int choice);

int main() {
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        processMenuChoice(choice);
    } while (choice != 4);
    
    freeList(head);
    return 0;
}

void displayMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Exit\n");
}

void processMenuChoice(int choice) {
    char description[50];
    float amount;
    int id;

    switch (choice) {
        case 1:
            printf("Enter description of the expense: ");
            scanf(" %[^\n]s", description);
            printf("Enter amount: ");
            scanf("%f", &amount);
            addExpense(description, amount);
            printf("Expense added successfully!\n");
            break;
        case 2:
            if (head == NULL) {
                printf("No expenses recorded.\n");
            } else {
                printf("Expenses:\n");
                viewExpenses(head);
            }
            break;
        case 3:
            printf("Enter the ID of the expense to delete: ");
            scanf("%d", &id);
            deleteExpense(id);
            break;
        case 4:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

void addExpense(char description[], float amount) {
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    newEntry->id = ++count;
    newEntry->amount = amount;
    snprintf(newEntry->description, sizeof(newEntry->description), "%s", description);
    newEntry->next = head;
    head = newEntry;
}

void viewExpenses(Entry* entry) {
    if (entry == NULL) {
        return;
    }
    printf("ID: %d, Description: %s, Amount: %.2f\n", entry->id, entry->description, entry->amount);
    viewExpenses(entry->next);
}

void deleteExpense(int id) {
    Entry* current = head;
    Entry* previous = NULL;

    while (current != NULL) {
        if (current->id == id) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Expense with ID %d has been deleted.\n", id);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Expense with ID %d not found.\n", id);
}

void freeList(Entry* entry) {
    if (entry == NULL) {
        return;
    }
    freeList(entry->next);
    free(entry);
}