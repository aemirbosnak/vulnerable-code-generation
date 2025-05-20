//FormAI DATASET v1.0 Category: Stock market tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stock {
    char symbol[6];
    float price;
    int numShares;
};

void printStock(struct Stock s);
int getNumberOfLines(FILE* fp);

int main(int argc, char* argv[])
{
    // Check that a file name was provided as a command line argument
    if (argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return -1;
    }

    // Open the file for reading
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file \"%s\"\n", argv[1]);
        return -1;
    }
    // Get the number of stocks in the file
    int numStocks = getNumberOfLines(fp);
    // Reset the file pointer to the beginning of the file
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for an array of Stock structs
    struct Stock* stocks = (struct Stock*)malloc(numStocks * sizeof(struct Stock));
    if (stocks == NULL) {
        printf("Error: Could not allocate memory\n");
        return -1;
    }

    // Read in the data from the file and store it in the array of structs
    for (int i = 0; i < numStocks; i++) {
        fscanf(fp, "%s %f %d", stocks[i].symbol, &stocks[i].price, &stocks[i].numShares);
    }

    // Close the file
    fclose(fp);

    // Print out the data for each stock
    for (int i = 0; i < numStocks; i++) {
        printStock(stocks[i]);
    }

    // Free the memory allocated for the array of Stock structs
    free(stocks);

    return 0;
}

void printStock(struct Stock s)
{
    printf("Stock Symbol: %s\n", s.symbol);
    printf("Price per Share: $%.2f\n", s.price);
    printf("Number of Shares: %d\n", s.numShares);
    printf("Total Value: $%.2f\n\n", s.price * s.numShares);
}

int getNumberOfLines(FILE* fp)
{
    char ch;
    int numLines = 0;

    while (!feof(fp)) {
        ch = fgetc(fp);
        if (ch == '\n') {
            numLines++;
        }
    }

    // Reset the file pointer to the beginning of the file
    fseek(fp, 0, SEEK_SET);

    return numLines;
}