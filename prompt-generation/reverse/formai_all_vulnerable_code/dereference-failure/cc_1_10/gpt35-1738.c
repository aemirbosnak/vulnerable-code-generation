//FormAI DATASET v1.0 Category: Stock market tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a linked list to store the stock market data
typedef struct Stock {
    char name[50];
    float price;
    struct Stock *next;
} Stock;

// Initialize the head of the linked list
Stock *head = NULL;

// Function to add a new stock to the linked list
void addStock(char *name, float price) {
    Stock *newStock = (Stock*) malloc(sizeof(Stock));
    strcpy(newStock->name, name);
    newStock->price = price;
    newStock->next = NULL;

    if (head == NULL) {
        head = newStock;
    } else {
        Stock *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStock;
    }
}

// Function to print the list of stocks and their prices
void printStocks() {
    Stock *current = head;
    printf("Name\tPrice\n");
    while (current != NULL) {
        printf("%s\t%.2f\n", current->name, current->price);
        current = current->next;
    }
}

int main() {
    // Simulate adding stock data to the program
    addStock("Apple", 132.05);
    addStock("Microsoft", 238.93);
    addStock("Amazon", 3456.08);

    // Print the list of stocks
    printStocks();
    
    return 0;
}