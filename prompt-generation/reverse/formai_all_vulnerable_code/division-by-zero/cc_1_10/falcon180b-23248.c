//Falcon-180B DATASET v1.0 Category: Data mining ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_CATEGORIES 50
#define MAX_TRANSACTIONS 1000

typedef struct item {
    char name[100];
    char category[50];
    int price;
    int quantity;
} Item;

typedef struct transaction {
    int customer_id;
    int item_id;
    int quantity;
    int total_price;
} Transaction;

int num_items = 0;
int num_transactions = 0;
Item items[MAX_ITEMS];
Transaction transactions[MAX_TRANSACTIONS];
char categories[MAX_CATEGORIES][50];
int num_categories = 0;

void generate_data() {
    srand(time(NULL));

    for (int i = 0; i < MAX_ITEMS; i++) {
        strcpy(items[i].category, categories[rand() % num_categories]);
        items[i].price = rand() % 1000;
        items[i].quantity = rand() % 100;
    }

    for (int i = 0; i < MAX_TRANSACTIONS; i++) {
        int customer_id = rand() % 1000;
        int item_id = rand() % MAX_ITEMS;
        int quantity = rand() % 10;
        transactions[i].customer_id = customer_id;
        transactions[i].item_id = item_id;
        transactions[i].quantity = quantity;
        transactions[i].total_price = items[item_id].price * quantity;
    }
}

void print_transactions() {
    for (int i = 0; i < num_transactions; i++) {
        printf("Transaction %d:\n", i+1);
        printf("Customer ID: %d\n", transactions[i].customer_id);
        printf("Item ID: %d\n", transactions[i].item_id);
        printf("Quantity: %d\n", transactions[i].quantity);
        printf("Total Price: $%d\n\n", transactions[i].total_price);
    }
}

void print_items() {
    for (int i = 0; i < num_items; i++) {
        printf("Item %d:\n", i+1);
        printf("Name: %s\n", items[i].name);
        printf("Category: %s\n", items[i].category);
        printf("Price: $%d\n", items[i].price);
        printf("Quantity: %d\n\n", items[i].quantity);
    }
}

int main() {
    generate_data();
    print_items();
    print_transactions();

    return 0;
}