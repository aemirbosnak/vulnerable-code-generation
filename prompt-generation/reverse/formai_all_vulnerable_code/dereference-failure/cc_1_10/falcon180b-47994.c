//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
    int category;
} item;

void addItem(item* list, int* numItems, char* name, float amount, int category) {
    if (*numItems >= MAX_ITEMS) {
        printf("Error: Cannot add more items.\n");
        return;
    }
    strcpy(list[*numItems].name, name);
    list[*numItems].amount = amount;
    list[*numItems].category = category;
    (*numItems)++;
}

void printItems(item* list, int numItems) {
    printf("Items:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - $%.2f - %d\n", list[i].name, list[i].amount, list[i].category);
    }
}

int main() {
    item expenses[MAX_ITEMS];
    int numExpenses = 0;
    char input[100];
    while (1) {
        printf("Enter an expense (name amount category) or type 'done' to finish:\n");
        scanf("%s", input);
        if (strcmp(input, "done") == 0) {
            break;
        }
        char* name = strtok(input, " ");
        float amount = atof(strtok(NULL, " "));
        int category = atoi(strtok(NULL, " "));
        addItem(expenses, &numExpenses, name, amount, category);
    }
    printf("Total expenses:\n");
    float total = 0;
    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }
    printf("$%.2f\n", total);
    return 0;
}