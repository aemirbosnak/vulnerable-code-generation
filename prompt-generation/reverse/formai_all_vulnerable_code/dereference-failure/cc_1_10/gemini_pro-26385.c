//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold stock data
typedef struct stock {
    char* name;
    double price;
    double open;
    double high;
    double low;
    double volume;
} stock;

// Function to print stock data
void print_stock(stock* s) {
    printf("Name: %s\n", s->name);
    printf("Price: %f\n", s->price);
    printf("Open: %f\n", s->open);
    printf("High: %f\n", s->high);
    printf("Low: %f\n", s->low);
    printf("Volume: %f\n", s->volume);
}

// Function to compare two stocks by price
int compare_stocks(const void* a, const void* b) {
    stock* s1 = (stock*)a;
    stock* s2 = (stock*)b;
    return s1->price - s2->price;
}

// Function to load stock data from a file
int load_stocks(stock** stocks, int* num_stocks, char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }
    int i = 0;
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        stocks[i] = (stock*)malloc(sizeof(stock));
        char* name = strtok(line, ",");
        double price = atof(strtok(NULL, ","));
        double open = atof(strtok(NULL, ","));
        double high = atof(strtok(NULL, ","));
        double low = atof(strtok(NULL, ","));
        double volume = atof(strtok(NULL, ","));
        stocks[i]->name = strdup(name);
        stocks[i]->price = price;
        stocks[i]->open = open;
        stocks[i]->high = high;
        stocks[i]->low = low;
        stocks[i]->volume = volume;
        i++;
    }
    fclose(fp);
    *num_stocks = i;
    return 0;
}

// Function to free stock data
void free_stocks(stock** stocks, int num_stocks) {
    for (int i = 0; i < num_stocks; i++) {
        free(stocks[i]->name);
        free(stocks[i]);
    }
}

// Function to print the stock data
void print_stocks(stock** stocks, int num_stocks) {
    qsort(stocks, num_stocks, sizeof(stock*), compare_stocks);
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }
}

int main() {
    // Set up the time
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    printf("The time is: %s", asctime(tm));
    
    // Set up the stocks
    stock* stocks[100];
    int num_stocks;
    if (load_stocks(stocks, &num_stocks, "stocks.csv") == -1) {
        printf("Error loading stocks\n");
        return -1;
    }
    
    // Print the stocks
    print_stocks(stocks, num_stocks);
    
    // Free the stocks
    free_stocks(stocks, num_stocks);
    
    return 0;
}