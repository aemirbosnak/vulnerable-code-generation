//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Stock;

typedef struct {
    Stock *array;
    size_t size;
} StockList;

void initializeStockList(StockList *list) {
    list->array = malloc(MAX_STOCKS * sizeof(Stock));
    list->size = 0;
}

void addStock(StockList *list, const char *name, float price, int quantity) {
    if (list->size < MAX_STOCKS) {
        strncpy(list->array[list->size].name, name, NAME_LENGTH);
        list->array[list->size].price = price;
        list->array[list->size].quantity = quantity;
        list->size++;
        printf("Added stock: %s, Price: %.2f, Quantity: %d\n", name, price, quantity);
    } else {
        printf("Stock list is full!\n");
    }
}

void printStocks(const StockList *list) {
    printf("Current stock list:\n");
    for (size_t i = 0; i < list->size; i++) {
        printf("Stock: %s, Price: %.2f, Quantity: %d\n",
               list->array[i].name,
               list->array[i].price,
               list->array[i].quantity);
    }
}

void saveStocksToFile(const StockList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error saving stocks to file");
        return;
    }
    for (size_t i = 0; i < list->size; i++) {
        fprintf(file, "%s %.2f %d\n", list->array[i].name, list->array[i].price, list->array[i].quantity);
    }
    fclose(file);
    printf("Stocks saved to %s\n", filename);
}

void freeStockList(StockList *list) {
    free(list->array);
}

int main() {
    StockList stockList;
    initializeStockList(&stockList);

    int choice;
    char name[NAME_LENGTH];
    float price;
    int quantity;

    do {
        printf("\nStock Market Tracker\n");
        printf("1. Add Stock\n");
        printf("2. View Stocks\n");
        printf("3. Save Stocks to File\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter stock name: ");
                scanf("%s", name);
                printf("Enter stock price: ");
                scanf("%f", &price);
                printf("Enter stock quantity: ");
                scanf("%d", &quantity);
                addStock(&stockList, name, price, quantity);
                break;
            case 2:
                printStocks(&stockList);
                break;
            case 3:
                saveStocksToFile(&stockList, "stocks.txt");
                break;
            case 4:
                freeStockList(&stockList);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}