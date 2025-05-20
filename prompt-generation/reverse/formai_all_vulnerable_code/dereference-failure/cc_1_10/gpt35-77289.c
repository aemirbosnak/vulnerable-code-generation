//FormAI DATASET v1.0 Category: Stock market tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    float price;
    int volume;
} Stock;

int addStock(Stock *arr, int size) {
    int i = 0;
    while (arr[i].price != -1) {
        i++;
    }
    if (i >= size) {
        printf("Stock list is full.\n");
        return size;
    }
    printf("Enter name of stock: ");
    scanf("%s", arr[i].name);
    printf("Enter price of stock: ");
    scanf("%f", &arr[i].price);
    printf("Enter volume of stock: ");
    scanf("%d", &arr[i].volume);

    return i + 1;
}

void viewStocks(Stock *arr, int size) {
    printf("%-20s %-10s %-10s\n", "Name", "Price", "Volume");
    for (int i = 0; i < size; i++) { 
        if (arr[i].price == -1) {
            continue;
        }
        printf("%-20s $%-9.2f %-10d\n", arr[i].name, arr[i].price, arr[i].volume);
    }
}

void searchStock(Stock *arr, int size) {
    char name[20];
    printf("Enter the name of the stock to search for: ");
    scanf("%s", name);

    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].name, name) == 0) {
            printf("%-20s $%-9.2f %-10d\n", arr[i].name, arr[i].price, arr[i].volume);
            return;
        }
    }
    printf("Stock not found.\n");
}

void updateStock(Stock *arr, int size) {
    char name[20];
    printf("Enter the name of the stock to update: ");
    scanf("%s", name);

    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].name, name) == 0) {
            printf("%-20s $%-9.2f %-10d\n", arr[i].name, arr[i].price, arr[i].volume);

            printf("Enter new price of stock: ");
            scanf("%f", &arr[i].price);
            printf("Enter new volume of stock: ");
            scanf("%d", &arr[i].volume);

            printf("Stock updated.\n");
            return;
        }
    }
    printf("Stock not found.\n");
}

void deleteStock(Stock *arr, int size) {
    char name[20];
    printf("Enter the name of the stock to delete: ");
    scanf("%s", name);

    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].name, name) == 0) {
            printf("%-20s $%-9.2f %-10d\n", arr[i].name, arr[i].price, arr[i].volume);

            arr[i].price = -1;
            arr[i].volume = -1;

            printf("Stock deleted.\n");
            return;
        }
    }
    printf("Stock not found.\n");
}

int main() {
    int option, size = 10;
    Stock *stockList = (Stock *)malloc(size * sizeof(Stock));
    for (int i = 0; i < size; i++) {
        stockList[i].price = -1;
    }

    do {
        printf("\nStock Market Tracker Menu\n");
        printf("1. Add stock\n");
        printf("2. View stocks\n");
        printf("3. Search stock\n");
        printf("4. Update stock\n");
        printf("5. Delete stock\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                size = addStock(stockList, size);
                break;
            case 2:
                viewStocks(stockList, size);
                break;
            case 3:
                searchStock(stockList, size);
                break;
            case 4:
                updateStock(stockList, size);
                break;
            case 5:
                deleteStock(stockList, size);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != 6);

    free(stockList);
    return 0;
}