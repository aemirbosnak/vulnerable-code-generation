//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 50
#define UPDATE_INTERVAL 60 * 60 * 1000 // 1 hour in milliseconds

typedef struct {
    char symbol[5];
    double price;
    time_t last_update;
} Stock;

typedef struct Node {
    Stock data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *current = NULL;

void add_stock(char symbol[5], double price) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->data.symbol, symbol);
    new_node->data.price = price;
    new_node->data.last_update = time(NULL);
    new_node->next = head;
    head = new_node;
}

void update_stock_price(char symbol[5], double price) {
    Node *prev = NULL, *current = head;
    while (current != NULL && strcmp(current->data.symbol, symbol) != 0) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Error: Stock not found.\n");
        return;
    }
    current->data.price = price;
    current->data.last_update = time(NULL);
    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }
}

void display_stocks() {
    if (head == NULL) {
        printf("No stocks found.\n");
        return;
    }
    current = head;
    printf("%-5s %-10s %-15s\n", "Symbol", "Price", "Last Updated");
    while (current != NULL) {
        printf("%-5s $%.2f %-15s\n", current->data.symbol, current->data.price, ctime(&current->data.last_update));
        current = current->next;
    }
}

void stock_tracker() {
    char symbol[5];
    double price;
    while (1) {
        printf("Enter stock symbol (or 'q' to quit): ");
        scanf("%s", symbol);
        if (strcmp(symbol, "q") == 0) {
            break;
        }
        printf("Enter new price: $");
        scanf("%lf", &price);
        add_stock(symbol, price);
        printf("Stock added successfully.\n");
        usleep(UPDATE_INTERVAL);
    }
    display_stocks();
}

int main() {
    stock_tracker();
    return 0;
}