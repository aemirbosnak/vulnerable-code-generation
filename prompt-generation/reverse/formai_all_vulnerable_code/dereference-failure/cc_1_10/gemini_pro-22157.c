//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Romeo and Juliet style C Stock market tracker

// The star-crossed lovers
typedef struct {
    char *name;
    double price;
    double change;
} Stock;

// The tragic tale
int main(int argc, char *argv[]) {
    // Set the scene
    srand(time(NULL));
    int num_stocks = 10;
    Stock stocks[num_stocks];
    for (int i = 0; i < num_stocks; i++) {
        stocks[i].name = malloc(20 * sizeof(char));
        strcpy(stocks[i].name, "Stock ");
        char c = 'A' + rand() % 26;
        stocks[i].name[6] = c;
        stocks[i].price = 100 + (double)rand() / RAND_MAX * 50;
        stocks[i].change = (double)(rand() % 101 - 50) / 100;
    }

    // Print the opening scene
    printf("A tale of woe and tragedy, where love and loss entwine,\n");
    printf("Where stocks take flight and dreams collide, a modern-day design.\n");
    printf("\n");

    // The star-crossed lovers meet
    int romeo_index = rand() % num_stocks;
    int juliet_index = rand() % num_stocks;
    while (romeo_index == juliet_index) {
        juliet_index = rand() % num_stocks;
    }
    Stock romeo = stocks[romeo_index];
    Stock juliet = stocks[juliet_index];

    // Their love is forbidden
    printf("But hark! A cruel twist of fate, their love forbidden,\n");
    printf("For Romeo's price is high, while Juliet's remains hidden.\n");
    printf("\n");

    // The tragic end
    double change = juliet.price - romeo.price;
    if (change > 0) {
        printf("Alas, their love was not meant to be,\n");
        printf("For Juliet's worth soared beyond Romeo's decree.\n");
    } else {
        printf("A tragic end, where love was torn,\n");
        printf("For Romeo's price sank, leaving Juliet forlorn.\n");
    }

    // Free the memory
    for (int i = 0; i < num_stocks; i++) {
        free(stocks[i].name);
    }

    return 0;
}