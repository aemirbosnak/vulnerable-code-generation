//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// A single stock entry
typedef struct stock {
    char* name;
    double price;
    double change;
    double change_percent;
    struct stock* next;
} stock;

// The head of the linked list of stocks
stock* head = NULL;

// Add a new stock to the linked list
void add_stock(char* name, double price, double change, double change_percent) {
    stock* new_stock = (stock*)malloc(sizeof(stock));
    new_stock->name = (char*)malloc(strlen(name) + 1);
    strcpy(new_stock->name, name);
    new_stock->price = price;
    new_stock->change = change;
    new_stock->change_percent = change_percent;
    new_stock->next = head;
    head = new_stock;
}

// Print the linked list of stocks
void print_stocks() {
    stock* current = head;
    while (current != NULL) {
        printf("%s: $%.2f (%.2f%%)\n", current->name, current->price, current->change_percent);
        current = current->next;
    }
}

// Free the memory allocated for the linked list of stocks
void free_stocks() {
    stock* current = head;
    while (current != NULL) {
        stock* next = current->next;
        free(current->name);
        free(current);
        current = next;
    }
}

// Generate a random stock price
double generate_price() {
    return (double)rand() / RAND_MAX * 100;
}

// Generate a random stock change
double generate_change() {
    return (double)rand() / RAND_MAX * 10 - 5;
}

// Generate a random stock change percent
double generate_change_percent() {
    return (double)rand() / RAND_MAX * 10 - 5;
}

// Generate 10 random stocks
void generate_stocks() {
    char* names[] = {"Apple", "Microsoft", "Amazon", "Google", "Tesla", "Berkshire Hathaway", "JPMorgan Chase", "ExxonMobil", "Chevron", "Johnson & Johnson"};
    for (int i = 0; i < 10; i++) {
        add_stock(names[i], generate_price(), generate_change(), generate_change_percent());
    }
}

int main() {
    srand(time(NULL));
    generate_stocks();
    print_stocks();
    free_stocks();
    return 0;
}