//FormAI DATASET v1.0 Category: Data mining ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct sales_record {
    char *customer_name;
    float amount_spent;
    int purchase_year;
};

int main() {
    // Load sales records from file
    FILE *sales_file = fopen("sales_data.txt", "r");
    if (sales_file == NULL) {
        printf("Error loading sales data file.\n");
        exit(1);
    }
    int num_records = 0;
    struct sales_record records[1000];
    char buffer[256];
    int i = 0;
    while (fgets(buffer, 255, sales_file)) {
        char *token = strtok(buffer, ",");
        records[i].customer_name = malloc(strlen(token)+1);
        strcpy(records[i].customer_name, token);
        token = strtok(NULL, ",");
        records[i].amount_spent = atof(token);
        token = strtok(NULL, ",");
        records[i].purchase_year = atoi(token);
        i++;
        num_records++;
    }
    fclose(sales_file);

    // Calculate total sales volume by year
    float total_sales_by_year[5] = {0, 0, 0, 0, 0};
    for (i = 0; i < num_records; i++) {
        total_sales_by_year[records[i].purchase_year-2015] += records[i].amount_spent;
    }

    // Output results
    printf("Total sales volume by year:\n");
    printf("2015: $%.2f\n", total_sales_by_year[0]);
    printf("2016: $%.2f\n", total_sales_by_year[1]);
    printf("2017: $%.2f\n", total_sales_by_year[2]);
    printf("2018: $%.2f\n", total_sales_by_year[3]);
    printf("2019: $%.2f\n", total_sales_by_year[4]);

    // Find top spending customers
    float highest_spenders[5] = {0, 0, 0, 0, 0};
    char *highest_spenders_names[5];
    for (i = 0; i < num_records; i++) {
        if (records[i].amount_spent > highest_spenders[records[i].purchase_year-2015]) {
            highest_spenders[records[i].purchase_year-2015] = records[i].amount_spent;
            highest_spenders_names[records[i].purchase_year-2015] = records[i].customer_name;
        }
    }
    printf("Top spending customers by year:\n");
    printf("2015: %s ($%.2f)\n", highest_spenders_names[0], highest_spenders[0]);
    printf("2016: %s ($%.2f)\n", highest_spenders_names[1], highest_spenders[1]);
    printf("2017: %s ($%.2f)\n", highest_spenders_names[2], highest_spenders[2]);
    printf("2018: %s ($%.2f)\n", highest_spenders_names[3], highest_spenders[3]);
    printf("2019: %s ($%.2f)\n", highest_spenders_names[4], highest_spenders[4]);

    // Free memory
    for (i = 0; i < num_records; i++) {
        free(records[i].customer_name);
    }
    return 0;
}