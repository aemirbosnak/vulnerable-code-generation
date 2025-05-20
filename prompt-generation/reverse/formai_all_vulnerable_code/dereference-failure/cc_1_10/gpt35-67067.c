//FormAI DATASET v1.0 Category: Stock market tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct stock {
    char symbol[6];
    float price;
    float change;
    char date[11];
} Stock;

void displayMenu() {
    printf("\n");
    printf("1. Add stock\n");
    printf("2. List all stocks\n");
    printf("3. Search for stock\n");
    printf("4. Update a stock\n");
    printf("5. Quit\n");
    printf("\n");
}

int getChoice() {
    char input[100];
    int choice = 0;
    printf("Enter choice: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &choice);
    return choice;
}

void addStock(Stock *stocks[], int *count) {
    printf("\n");
    printf("Add a stock:\n");
    printf("\n");
    char symbol[6];
    float price = 0.0;
    float change = 0.0;
    char date[11];
    printf("Enter symbol (max length 5 characters): ");
    fgets(symbol, sizeof(symbol), stdin);
    symbol[strcspn(symbol, "\n")] = '\0';
    printf("Enter price: ");
    scanf("%f", &price);
    getchar(); // Clear the input buffer
    printf("Enter change: ");
    scanf("%f", &change);
    getchar(); // Clear the input buffer
    printf("Enter date (dd/mm/yyyy): ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = '\0';
    Stock *newStock = (Stock*)malloc(sizeof(Stock));
    strncpy(newStock->symbol, symbol, sizeof(newStock->symbol));
    newStock->price = price;
    newStock->change = change;
    strncpy(newStock->date, date, sizeof(newStock->date));
    stocks[*count] = newStock;
    (*count)++;
    printf("\n");
}

void listStocks(Stock *stocks[], int count) {
    printf("\n");
    printf("All stocks:\n");
    printf("\n");
    for (int i = 0; i < count; i++) {
        printf("%s %.2f %.2f %s\n", stocks[i]->symbol, stocks[i]->price, stocks[i]->change, stocks[i]->date);
    }
    printf("\n");
}

void searchStock(Stock *stocks[], int count) {
    printf("\n");
    printf("Search for a stock:\n");
    printf("\n");
    char symbol[6];
    printf("Enter symbol to search for: ");
    fgets(symbol, sizeof(symbol), stdin);
    symbol[strcspn(symbol, "\n")] = '\0';
    for (int i = 0; i < count; i++) {
        if (strcasecmp(stocks[i]->symbol, symbol) == 0) {
            printf("%s %.2f %.2f %s\n", stocks[i]->symbol, stocks[i]->price, stocks[i]->change, stocks[i]->date);
            return;
        }
    }
    printf("Stock not found.\n");
    printf("\n");
}

void updateStock(Stock *stocks[], int count) {
    printf("\n");
    printf("Update a stock:\n");
    printf("\n");
    char symbol[6];
    printf("Enter symbol to update: ");
    fgets(symbol, sizeof(symbol), stdin);
    symbol[strcspn(symbol, "\n")] = '\0';
    for (int i = 0; i < count; i++) {
        if (strcasecmp(stocks[i]->symbol, symbol) == 0) {
            printf("%s %.2f %.2f %s\n", stocks[i]->symbol, stocks[i]->price, stocks[i]->change, stocks[i]->date);
            printf("\n");
            printf("Enter new price: ");
            scanf("%f", &stocks[i]->price);
            getchar(); // Clear the input buffer
            printf("Enter new change: ");
            scanf("%f", &stocks[i]->change);
            getchar(); // Clear the input buffer
            printf("Enter new date (dd/mm/yyyy): ");
            fgets(stocks[i]->date, sizeof(stocks[i]->date), stdin);
            stocks[i]->date[strcspn(stocks[i]->date, "\n")] = '\0';
            printf("\n");
            return;
        }
    }
    printf("Stock not found.\n");
    printf("\n");
}

int main() {
    Stock *stocks[100];
    int count = 0;
    int choice = 0;
    do {
        displayMenu();
        choice = getChoice();
        switch (choice) {
            case 1:
                addStock(stocks, &count);
                break;
            case 2:
                listStocks(stocks, count);
                break;
            case 3:
                searchStock(stocks, count);
                break;
            case 4:
                updateStock(stocks, count);
                break;
            case 5:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);
    for (int i = 0; i < count; i++) {
        free(stocks[i]);
    }
    return 0;
}