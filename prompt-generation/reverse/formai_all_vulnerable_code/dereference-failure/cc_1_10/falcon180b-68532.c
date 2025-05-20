//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_TICKERS 50
#define MAX_HISTORY 100

typedef struct {
    char ticker[10];
    double price;
    time_t timestamp;
} Ticker;

void print_ticker(Ticker ticker) {
    printf("%-10s $%.2f %s\n", ticker.ticker, ticker.price, ctime(&ticker.timestamp));
}

int main() {
    Ticker tickers[MAX_TICKERS];
    int num_tickers = 0;
    FILE *fp;
    char line[1024];
    char *token;
    time_t now;

    time(&now);

    fp = fopen("tickers.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open tickers.txt\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ",");
        strcpy(tickers[num_tickers].ticker, token);
        num_tickers++;

        if (num_tickers >= MAX_TICKERS) {
            break;
        }
    }

    fclose(fp);

    while (1) {
        system("clear");
        printf("Stock Market Tracker\n\n");

        for (int i = 0; i < num_tickers; i++) {
            fp = fopen(tickers[i].ticker, "r");
            if (fp == NULL) {
                fprintf(stderr, "Error: could not open %s\n", tickers[i].ticker);
                exit(1);
            }

            fseek(fp, 0, SEEK_END);
            long size = ftell(fp);
            fseek(fp, 0, SEEK_SET);

            char *buffer = malloc(size + 1);
            fread(buffer, sizeof(char), size, fp);
            fclose(fp);

            buffer[size] = '\0';

            char *price_str = strstr(buffer, "price:");
            if (price_str == NULL) {
                continue;
            }

            price_str += strlen("price:");
            while (!isdigit(*price_str)) {
                price_str++;
            }

            tickers[i].price = atof(price_str);
            tickers[i].timestamp = now;

            print_ticker(tickers[i]);
        }

        sleep(60);
    }

    return 0;
}