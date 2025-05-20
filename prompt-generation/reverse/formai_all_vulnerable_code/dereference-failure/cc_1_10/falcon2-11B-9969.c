//Falcon2-11B DATASET v1.0 Category: Stock market tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int shares;
    double price;
} stock_t;

int getStockInfo(stock_t *stock) {
    FILE *file = fopen("stock_info.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char line[1000];
    while (fgets(line, sizeof(line), file)) {
        char *token;
        token = strtok(line, ",");
        if (strcmp(token, "name") == 0) {
            strcpy(stock->name, token);
        } else if (strcmp(token, "shares") == 0) {
            stock->shares = atoi(token);
        } else if (strcmp(token, "price") == 0) {
            stock->price = atof(token);
        }
    }

    fclose(file);
    return 0;
}

int getNextStock(stock_t *stock) {
    char line[1000];
    FILE *file = fopen("stock_info.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, stock->name)!= NULL) {
            break;
        }
    }

    fclose(file);
    return 0;
}

int processStock(stock_t *stock) {
    if (stock->shares == 0) {
        return 1;
    }

    printf("Processing stock %s...\n", stock->name);
    printf("Shares: %d\n", stock->shares);
    printf("Price: %.2f\n", stock->price);
    return 0;
}

int writeStockInfo(stock_t *stock) {
    FILE *file = fopen("processed_stock_info.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fprintf(file, "Processed stock information:\n");
    fprintf(file, "Stock name: %s\n", stock->name);
    fprintf(file, "Shares: %d\n", stock->shares);
    fprintf(file, "Price: %.2f\n", stock->price);
    fclose(file);
    return 0;
}

int main() {
    stock_t stock;

    if (getStockInfo(&stock) == 1) {
        return 1;
    }

    while (getNextStock(&stock) == 0) {
        if (processStock(&stock) == 1) {
            break;
        }
        if (writeStockInfo(&stock) == 1) {
            break;
        }
    }

    return 0;
}