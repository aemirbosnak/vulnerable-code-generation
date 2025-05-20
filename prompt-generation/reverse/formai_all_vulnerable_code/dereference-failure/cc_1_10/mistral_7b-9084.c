//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stock {
    char symbol[5];
    char name[20];
    float price;
    float quantity;
    struct Stock *next;
} Stock;

void addStock(Stock **head, char symbol[], char name[], float price, float quantity) {
    Stock *newStock = (Stock *) malloc(sizeof(Stock));
    strcpy(newStock->symbol, symbol);
    strcpy(newStock->name, name);
    newStock->price = price;
    newStock->quantity = quantity;
    newStock->next = *head;
    *head = newStock;
}

void removeStock(Stock **head, char symbol[]) {
    Stock *current = *head, *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->symbol, symbol) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void displayPortfolio(Stock *head) {
    Stock *current = head;
    float totalValue = 0.0;

    printf("\nPortfolio:\n");
    while (current != NULL) {
        printf("%-5s %-20s %-8.2f %-8.2f %-8.2f\n", current->symbol, current->name, current->price, current->quantity, current->price * current->quantity);
        totalValue += current->price * current->quantity;
        current = current->next;
    }
    printf("\nTotal Value: %-8.2f\n", totalValue);
}

int main() {
    Stock *head = NULL;

    addStock(&head, "AAPL", "Apple Inc", 145.25, 10.0);
    addStock(&head, "MSFT", "Microsoft Corporation", 215.35, 5.0);
    addStock(&head, "GOOG", "Alphabet Inc", 1234.56, 3.0);

    displayPortfolio(head);

    removeStock(&head, "GOOG");

    displayPortfolio(head);

    return 0;
}