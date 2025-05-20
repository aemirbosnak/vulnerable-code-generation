//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stock {
    char name[50];
    float price;
    struct Stock *next;
} Stock;

Stock *head = NULL;

void addStock(char *name, float price) {
    Stock *newStock = (Stock *) malloc(sizeof(Stock));
    strcpy(newStock->name, name);
    newStock->price = price;
    newStock->next = head;
    head = newStock;
}

void removeStock(char *name) {
    Stock *current = head;
    Stock *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Stock not found.\n");
}

void viewStocks() {
    Stock *current = head;

    while (current != NULL) {
        printf("%s: %.2f\n", current->name, current->price);
        current = current->next;
    }
}

int main() {
    addStock("Apple", 150.50);
    addStock("Microsoft", 200.25);
    addStock("Amazon", 300.00);

    viewStocks();

    removeStock("Microsoft");

    viewStocks();

    return 0;
}