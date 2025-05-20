//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 100

typedef struct {
    char type[10];
    float amount;
    struct Entry *next;
} Entry;

Entry *head = NULL;
Entry *current = NULL;
Entry *file_head = NULL;

void add_entry(Entry **head, char *type, float amount) {
    Entry *new_entry = (Entry *)malloc(sizeof(Entry));
    strcpy(new_entry->type, type);
    new_entry->amount = amount;
    new_entry->next = *head;
    *head = new_entry;
}

void display_balance() {
    float balance = 0;
    Entry *entry = head;

    while (entry != NULL) {
        if (strcmp(entry->type, "income") == 0) {
            balance += entry->amount;
        } else if (strcmp(entry->type, "expense") == 0) {
            balance -= entry->amount;
        }
        entry = entry->next;
    }

    printf("Current Balance: %.2f\n", balance);
}

void save_data(Entry *head, const char *filename) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    Entry *entry = head;

    while (entry != NULL) {
        fprintf(file, "%s %.2f\n", entry->type, entry->amount);
        entry = entry->next;
    }

    fclose(file);
    printf("Data saved to file.\n");
}

int main() {
    char command[15];
    char type[10];
    float amount;

    while (1) {
        printf("\nPersonal Finance Planner\n"
               "1. Add income\n"
               "2. Add expense\n"
               "3. Display balance\n"
               "4. Save data to file\n"
               "5. Exit\n"
               "Enter command: ");

        scanf("%s", command);

        switch (command[0]) {
            case '1':
                printf("Enter income type: ");
                scanf("%s", type);
                printf("Enter income amount: ");
                scanf("%f", &amount);
                add_entry(&head, type, amount);
                break;

            case '2':
                printf("Enter expense type: ");
                scanf("%s", type);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                add_entry(&head, "expense", amount);
                break;

            case '3':
                display_balance();
                break;

            case '4':
                printf("Enter filename: ");
                scanf("%s", command);
                save_data(head, command);
                break;

            case '5':
                exit(0);

            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}