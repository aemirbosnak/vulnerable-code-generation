//FormAI DATASET v1.0 Category: Stock market tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOL_LEN 5
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 10

typedef struct stock {
    char symbol[MAX_SYMBOL_LEN];
    char name[MAX_NAME_LEN];
    float price;
} stock_t;

void clear_input_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int get_menu_choice() {
    int choice;
    printf("Stock Market Tracker\n\n");
    printf("1. View all stocks\n");
    printf("2. Add a new stock\n");
    printf("3. Remove a stock\n");
    printf("4. Quit\n");
    printf("\nEnter your choice (1-4): ");
    scanf("%d", &choice);
    clear_input_buffer(); // to clear any extra input in the buffer
    return choice;
}

void print_stock(stock_t *stock) {
    printf("Symbol: %s\n", stock->symbol);
    printf("Name: %s\n", stock->name);
    printf("Price: $%.2f\n", stock->price);
}

void view_all_stocks(stock_t **stocks, int num_stocks) {
    printf("\nAll Stocks:\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("Stock %d:\n", i+1);
        print_stock(stocks[i]);
        printf("\n");
    }
}

void add_new_stock(stock_t **stocks, int *num_stocks) {
    stock_t *new_stock = (stock_t*)malloc(sizeof(stock_t));
    
    printf("\nEnter the stock symbol (max %d characters): ", MAX_SYMBOL_LEN);
    fgets(new_stock->symbol, MAX_SYMBOL_LEN, stdin);
    strtok(new_stock->symbol, "\n"); // remove newline character from the input
    
    printf("Enter the stock name (max %d characters): ", MAX_NAME_LEN);
    fgets(new_stock->name, MAX_NAME_LEN, stdin);
    strtok(new_stock->name, "\n"); // remove newline character from the input
    
    printf("Enter the stock price (max %d characters): $", MAX_PRICE_LEN);
    scanf("%f", &new_stock->price);
    clear_input_buffer(); // to clear any extra input in the buffer
    
    // add new stock to existing stocks
    stocks[*num_stocks] = new_stock;
    (*num_stocks)++;
    
    printf("\nSuccessfully added new stock!\n");
}

void remove_stock(stock_t **stocks, int *num_stocks) {
    char symbol[MAX_SYMBOL_LEN];
    printf("\nEnter the stock symbol of the stock to remove: ");
    fgets(symbol, MAX_SYMBOL_LEN, stdin);
    strtok(symbol, "\n"); // remove newline character from the input
    
    int found = 0;
    for (int i = 0; i < *num_stocks; i++) {
        if (strcmp(stocks[i]->symbol, symbol) == 0) {
            found = 1;
            // free memory allocated for the stock
            free(stocks[i]);
            
            // shift all stocks after the removed stock one position to the left
            for (int j = i+1; j < *num_stocks; j++) {
                stocks[j-1] = stocks[j];
            }
            
            (*num_stocks)--;
            printf("\nSuccessfully removed stock %s!\n", symbol);
            break;
        }
    }
    
    if (!found) {
        printf("\nStock %s not found!\n", symbol);
    }
}

int main() {
    stock_t *stocks[100]; // array of pointers to stocks
    int num_stocks = 0; // number of stocks currently in the array
    
    // adding some initial stocks
    stock_t *stock1 = (stock_t*)malloc(sizeof(stock_t));
    strcpy(stock1->symbol, "AAPL");
    strcpy(stock1->name, "Apple Inc");
    stock1->price = 148.48;
    stocks[num_stocks++] = stock1;
    
    stock_t *stock2 = (stock_t*)malloc(sizeof(stock_t));
    strcpy(stock2->symbol, "GOOG");
    strcpy(stock2->name, "Alphabet Inc Class C");
    stock2->price = 2727.82;
    stocks[num_stocks++] = stock2;
    
    stock_t *stock3 = (stock_t*)malloc(sizeof(stock_t));
    strcpy(stock3->symbol, "TSLA");
    strcpy(stock3->name, "Tesla Inc");
    stock3->price = 733.57;
    stocks[num_stocks++] = stock3;
    
    int choice;
    do {
        choice = get_menu_choice();
        switch (choice) {
            case 1:
                view_all_stocks(stocks, num_stocks);
                break;
            case 2:
                add_new_stock(stocks, &num_stocks);
                break;
            case 3:
                remove_stock(stocks, &num_stocks);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    } while (choice != 4);
    
    // free memory allocated for all stocks
    for (int i = 0; i < num_stocks; i++) {
        free(stocks[i]);
    }
    
    return 0;
}