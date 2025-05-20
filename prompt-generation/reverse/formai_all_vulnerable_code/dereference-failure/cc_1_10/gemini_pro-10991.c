//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
// Hey there, fellow Linus! Let's craft a gnarly expense tracker, shall we?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Let's keep track of some smelly expenses...
typedef struct {
    char *desc;     // What the heck did we spend the loot on?
    float amount;   // How much did this madness cost us?
} expense_t;

// And let's have a list of these smelly things...
typedef struct {
    expense_t *expenses;  // An array of expenses, oh so charming
    int size;            // How many smelly expenses do we have?
} expense_list_t;

// Now, let's add some extra functionality...
expense_list_t *expense_list_create() {
    // Allocate memory for our list
    expense_list_t *list = malloc(sizeof(expense_list_t));
    if (!list) {
        printf("Out of memory, you fool!\n");
        exit(1);
    }

    // Initialize the list
    list->expenses = NULL;
    list->size = 0;

    return list;
}

void expense_list_add(expense_list_t *list, const char *desc, float amount) {
    // Reallocate memory for our expenses
    list->expenses = realloc(list->expenses, (list->size + 1) * sizeof(expense_t));
    if (!list->expenses) {
        printf("Out of memory, you dolt!\n");
        exit(1);
    }

    // Add the new expense
    list->expenses[list->size].desc = strdup(desc);
    list->expenses[list->size].amount = amount;
    list->size++;
}

void expense_list_print(expense_list_t *list) {
    // Let's show off our smelly expenses!
    printf("Behold, your loathsome expenses:\n");
    for (int i = 0; i < list->size; i++) {
        printf("%d. %s: %.2f\n", i+1, list->expenses[i].desc, list->expenses[i].amount);
    }
}

void expense_list_free(expense_list_t *list) {
    // Let's clean up our mess...
    for (int i = 0; i < list->size; i++) {
        free(list->expenses[i].desc);
    }
    free(list->expenses);
    free(list);
}

// Now, let's have some fun!
int main() {
    // Create our expense list
    expense_list_t *list = expense_list_create();

    // Add some smelly expenses
    expense_list_add(list, "Pizza and beer", 20.0);
    expense_list_add(list, "New socks", 10.0);
    expense_list_add(list, "Therapy session", 50.0);

    // Show off our expenses
    expense_list_print(list);

    // Clean up our mess
    expense_list_free(list);

    return 0;
}