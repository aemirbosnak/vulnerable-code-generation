//FormAI DATASET v1.0 Category: Data mining ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

/* Define a struct to hold data for each record */
typedef struct {
    int id;
    float age;
    float income;
    int married;
} Record;

/* Define a function to read in data from a file */
int read_data(char* filename, Record** records, int num_records) {
    FILE* fp;
    int i;

    /* Allocate memory for the records */
    *records = malloc(sizeof(Record) * num_records);

    /* Open the file */
    fp = fopen(filename, "r");

    /* Read in data */
    for (i = 0; i < num_records; i++) {
        fscanf(fp, "%d,%f,%f,%d", &((*records)[i].id), &((*records)[i].age), &((*records)[i].income), &((*records)[i].married));
    }

    /* Close the file */
    fclose(fp);

    /* Return the number of records read */
    return num_records;
}

int main() {
    Record* records;
    int num_records;
    int i;

    /* Read in the data from a file */
    num_records = read_data("data.csv", &records, 100);

    /* Compute some statistics */
    float total_income = 0;
    int num_married = 0;
    for (i = 0; i < num_records; i++) {
        total_income += records[i].income;
        if (records[i].married == 1) {
            num_married++;
        }
    }
    float average_income = total_income / num_records;
    float percent_married = ((float)num_married / (float)num_records) * 100.0;

    /* Print out the results */
    printf("Number of records: %d\n", num_records);
    printf("Average income: $%.2f\n", average_income);
    printf("Percentage married: %.2f%%\n", percent_married);

    /* Free the memory */
    free(records);

    return 0;
}