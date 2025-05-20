//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_LENGTH 50

typedef struct {
    char date[MAX_LENGTH];
    float open;
    float close;
} StockRecord;

void displayRecords(StockRecord records[], int n);

int main() {
    StockRecord records[MAX_RECORDS];
    char filename[MAX_LENGTH];
    printf("Enter the name of the CSV file: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: cannot open file %s\n", filename);
        exit(1);
    }

    char line[MAX_LENGTH*3];
    char* token;
    int i = 0;
    while (fgets(line, sizeof(line), file) != NULL && i < MAX_RECORDS) {
        token = strtok(line, ",");
        strcpy(records[i].date, token);
        token = strtok(NULL, ",");
        records[i].open = atof(token);
        token = strtok(NULL, ",");
        records[i].close = atof(token);
        i++;
    }
    fclose(file);

    displayRecords(records, i);

    return 0;
}

void displayRecords(StockRecord records[], int n) {
    printf("Date\tOpen\tClose\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%.2f\t%.2f\n", records[i].date, records[i].open, records[i].close);
    }
}