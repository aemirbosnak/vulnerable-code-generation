//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stock {
    char symbol[5];
    float price;
    int quantity;
    struct Stock* next;
} Stock;

void addStock(Stock** head, char symbol[], float price, int quantity) {
    Stock* newStock = (Stock*) malloc(sizeof(Stock));

    strcpy(newStock->symbol, symbol);
    newStock->price = price;
    newStock->quantity = quantity;

    if (*head == NULL) {
        *head = newStock;
    } else {
        Stock* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStock;
    }
}

void removeStock(Stock** head, char symbol[]) {
    Stock* current = *head;
    Stock* previous = NULL;

    while (current != NULL && strcmp(current->symbol, symbol) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Stock not found in portfolio.\n");
        return;
    }

    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
}

void viewPortfolio(Stock* head) {
    Stock* current = head;
    float totalValue = 0;

    printf("\nPortfolio:\n");

    while (current != NULL) {
        totalValue += current->price * current->quantity;
        printf("%s: %d shares @ %.2f = %.2f\n", current->symbol, current->quantity, current->price, current->price * current->quantity);
        current = current->next;
    }

    printf("\nTotal Portfolio Value: %.2f\n", totalValue);
}

int main() {
    Stock* portfolioHead = NULL;

    addStock(&portfolioHead, "AAPL", 120.50, 10);
    addStock(&portfolioHead, "GOOG", 90.20, 5);
    addStock(&portfolioHead, "MSFT", 150.30, 7);

    viewPortfolio(portfolioHead);

    removeStock(&portfolioHead, "GOOG");

    viewPortfolio(portfolioHead);

    return 0;
}