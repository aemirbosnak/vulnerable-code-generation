//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COMPANIES 50
#define MAX_SYMBOL_LEN 10
#define MAX_DATA_POINTS 100

typedef struct {
    char symbol[MAX_SYMBOL_LEN + 1];
    double current_price;
    double previous_price;
    double change_percentage;
} Company;

void read_data_from_csv(const char *filename, Company companies[MAX_COMPANIES]) {
    FILE *file = fopen(filename, "r");
    char line[1024];
    int num_companies = 0;

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%s%lf%lf", companies[num_companies].symbol, &companies[num_companies].previous_price, &companies[num_companies].current_price);
        if (num_companies < MAX_COMPANIES - 1) {
            num_companies++;
        }
    }

    fclose(file);
}

void calculate_change_percentage(Company *company) {
    company->change_percentage = (company->current_price - company->previous_price) / company->previous_price * 100;
}

void print_company_data(const Company *company) {
    printf("Symbol: %s\n", company->symbol);
    printf("Previous Price: %.2f\n", company->previous_price);
    printf("Current Price: %.2f\n", company->current_price);
    printf("Change Percentage: %.2f%%\n", company->change_percentage);
    printf("\n");
}

int main() {
    Company companies[MAX_COMPANIES];
    const char *filename = "stocks.csv";

    read_data_from_csv(filename, companies);

    for (int i = 0; i < MAX_COMPANIES && i < 5; i++) {
        calculate_change_percentage(&companies[i]);
        print_company_data(&companies[i]);
    }

    return 0;
}