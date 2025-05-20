//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_COMPANIES 100
#define MAX_NAME_LEN 100
#define MAX_SYMBOL_LEN 10
#define MAX_SHARE_PRICE_LEN 10
#define MAX_SHARE_VOLUME_LEN 10
#define MAX_DATE_LEN 10
#define MAX_TIME_LEN 8

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char share_price[MAX_SHARE_PRICE_LEN];
    char share_volume[MAX_SHARE_VOLUME_LEN];
    char date[MAX_DATE_LEN];
    char time[MAX_TIME_LEN];
} company_t;

company_t companies[MAX_COMPANIES];
int num_companies = 0;

void add_company(char *name, char *symbol, char *share_price, char *share_volume, char *date, char *time) {
    strncpy(companies[num_companies].name, name, MAX_NAME_LEN);
    strncpy(companies[num_companies].symbol, symbol, MAX_SYMBOL_LEN);
    strncpy(companies[num_companies].share_price, share_price, MAX_SHARE_PRICE_LEN);
    strncpy(companies[num_companies].share_volume, share_volume, MAX_SHARE_VOLUME_LEN);
    strncpy(companies[num_companies].date, date, MAX_DATE_LEN);
    strncpy(companies[num_companies].time, time, MAX_TIME_LEN);
    num_companies++;
}

void print_companies() {
    printf("Company Name\tSymbol\tShare Price\tShare Volume\tDate\tTime\n");
    for (int i = 0; i < num_companies; i++) {
        printf("%-30s %-10s %-10s %-10s %-10s %-8s\n", companies[i].name, companies[i].symbol, companies[i].share_price, companies[i].share_volume, companies[i].date, companies[i].time);
    }
}

int main() {
    FILE *fp;
    char line[1000];
    char *token;
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char share_price[MAX_SHARE_PRICE_LEN];
    char share_volume[MAX_SHARE_VOLUME_LEN];
    char date[MAX_DATE_LEN];
    char time[MAX_TIME_LEN];

    fp = fopen("stock_market.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, "\t");
        strcpy(name, token);
        token = strtok(NULL, "\t");
        strcpy(symbol, token);
        token = strtok(NULL, "\t");
        strcpy(share_price, token);
        token = strtok(NULL, "\t");
        strcpy(share_volume, token);
        token = strtok(NULL, "\t");
        strcpy(date, token);
        token = strtok(NULL, "\t");
        strcpy(time, token);

        add_company(name, symbol, share_price, share_volume, date, time);
    }

    fclose(fp);

    print_companies();

    return 0;
}