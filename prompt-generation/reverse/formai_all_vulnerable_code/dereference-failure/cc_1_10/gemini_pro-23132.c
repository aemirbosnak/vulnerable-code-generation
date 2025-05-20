//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESC 100
#define MAX_ITEMS 100

struct expense {
    char *desc;
    float amount;
    struct expense *next;
};

int main() {
     struct expense *head = NULL;
    int num_items = 0;
    char input[MAX_DESC+1];
    float amount;

    // Get user input
    while (1) {
        printf("Enter expense description (or 'q' to quit): ");
        scanf("%s", input);
        if (strcmp(input, "q") == 0)
            break;

        printf("Enter expense amount: ");
        scanf("%f", &amount);

        // Create a new expense item
        struct expense *new_item = malloc(sizeof(struct expense));
        new_item->desc = malloc(strlen(input) + 1);
        strcpy(new_item->desc, input);
        new_item->amount = amount;
        new_item->next = NULL;

        // Add the new item to the linked list
        if (head == NULL)
            head = new_item;
        else {
            struct expense *curr = head;
            while (curr->next != NULL)
                curr = curr->next;
            curr->next = new_item;
        }

        num_items++;
    }

    // Print the expenses
    printf("\nYour expenses:\n");
    struct expense *curr = head;
    while (curr != NULL) {
        printf("%s: %.2f\n", curr->desc, curr->amount);
        curr = curr->next;
    }

    // Calculate the total expense
    float total = 0.0;
    curr = head;
    while (curr != NULL) {
        total += curr->amount;
        curr = curr->next;
    }

    // Print the total expense
    printf("\nTotal expense: %.2f\n", total);

    // Free the memory allocated for the expenses
    curr = head;
    while (curr != NULL) {
        struct expense *next = curr->next;
        free(curr->desc);
        free(curr);
        curr = next;
    }

    return 0;
}