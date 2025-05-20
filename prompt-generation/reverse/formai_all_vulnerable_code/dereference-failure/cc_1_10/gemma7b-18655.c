//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Stocks 10

typedef struct Stock {
    char name[20];
    double price;
    int quantity;
    struct Stock* next;
} Stock;

Stock* createStock(char* name, double price, int quantity) {
    Stock* newStock = malloc(sizeof(Stock));
    strcpy(newStock->name, name);
    newStock->price = price;
    newStock->quantity = quantity;
    newStock->next = NULL;
    return newStock;
}

void printStockList(Stock* head) {
    while (head) {
        printf("%s: %.2lf, Q: %d\n", head->name, head->price, head->quantity);
        head = head->next;
    }
}

void updateStockPrice(Stock* head, double newPrice) {
    while (head) {
        if (strcmp(head->name, "Gold") == 0) {
            head->price = newPrice;
        }
        head = head->next;
    }
}

int main() {
    Stock* head = createStock("Gold", 100.0, 100);
    createStock("Silver", 50.0, 50);
    createStock("Bronze", 25.0, 25);

    printStockList(head);

    updateStockPrice(head, 110.0);

    printStockList(head);

    return 0;
}