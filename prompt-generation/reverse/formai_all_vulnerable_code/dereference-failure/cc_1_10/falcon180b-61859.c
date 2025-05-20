//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPANIES 100
#define MAX_SYMBOLS 10

typedef struct {
    char symbol[MAX_SYMBOLS];
    float price;
    int volume;
} Company;

void read_companies(Company companies[]) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("companies.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open companies file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        strcpy(companies[i].symbol, strtok(line, ","));
        companies[i].price = atof(strtok(NULL, ","));
        companies[i].volume = atoi(strtok(NULL, ","));
        i++;
    }

    fclose(fp);
}

void print_companies(Company companies[]) {
    int i;

    for (i = 0; i < MAX_COMPANIES; i++) {
        if (companies[i].symbol[0]!= '\0') {
            printf("%s %.2f %d\n", companies[i].symbol, companies[i].price, companies[i].volume);
        }
    }
}

int main() {
    Company companies[MAX_COMPANIES];

    read_companies(companies);
    print_companies(companies);

    return 0;
}