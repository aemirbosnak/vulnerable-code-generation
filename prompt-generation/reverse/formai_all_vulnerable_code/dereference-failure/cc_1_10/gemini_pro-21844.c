//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Expense {
    char *description;
    float amount;
    struct Expense *next;
} Expense;

typedef struct Tracker {
    Expense *head;
    Expense *tail;
} Tracker;

Tracker *create_tracker() {
    Tracker *tracker = malloc(sizeof(Tracker));
    tracker->head = NULL;
    tracker->tail = NULL;
    printf("Tracker created. Awaiting Expenses\n");
    return tracker;
}

void add_expense(Tracker *tracker, char *description, float amount) {
    Expense *new_expense = malloc(sizeof(Expense));
    new_expense->description = description;
    new_expense->amount = amount;
    new_expense->next = NULL;
    
    if (tracker->head == NULL) {
        tracker->head = new_expense;
        tracker->tail = new_expense;
    } else {
        tracker->tail->next = new_expense;
        tracker->tail = new_expense;
    }
    printf("Expense added: %s - $%.2f\n", description, amount);
}

void print_expenses(Tracker *tracker) {
    int count = 1;
    Expense *current = tracker->head;
    if (current == NULL) {
        printf("No expenses to display.");
        return;
    }

    printf("\nExpense Report:\n");
    printf("----------------------------------------------------\n");
    printf("%-5s %-30s %10s\n", "#", "Description", "Amount");
    printf("----------------------------------------------------\n");
    do {
        printf("%-5d %-30s $%.2f\n", count, current->description, current->amount);
        count++;
        current = current->next;
    } while (current != NULL);
    printf("----------------------------------------------------\n");
}

void delete_tracker(Tracker *tracker) {
    Expense *current = tracker->head;
    Expense *next;
    while (current != NULL) {
        next = current->next;
        free(current->description);
        free(current);
        current = next;
    }
    free(tracker);
    printf("Tracker deleted.\n");
}

int main() {
    printf("\nExpense Tracker\n");
    printf("----------------------------------------------------\n");
    printf("Available Commands:\n");
    printf("\t- add (description, amount): Add an expense\n");
    printf("\t- list: List all expenses\n");
    printf("\t- quit: Exit the program\n");
    printf("----------------------------------------------------\n\n");

    Tracker *tracker = create_tracker();
    char input[100];
    char description[100];
    float amount;
    bool running = true;
    while (running) {
        printf("Command: ");
        fgets(input, sizeof(input), stdin);

        char *command = strtok(input, " ");
        if (strcmp(command, "add") == 0) {
            printf("Expense Description: ");
            fgets(description, sizeof(description), stdin);
            description[strcspn(description, "\n")] = 0;  // Remove newline from input
            printf("Expense Amount: ");
            scanf("%f", &amount);
            getchar();  // Consume newline character
            add_expense(tracker, description, amount);
        } else if (strcmp(command, "list") == 0) {
            print_expenses(tracker);
        } else if (strcmp(command, "quit") == 0) {
            running = false;
        }
    }

    delete_tracker(tracker);
    printf("Goodbye!\n");
    return 0;
}