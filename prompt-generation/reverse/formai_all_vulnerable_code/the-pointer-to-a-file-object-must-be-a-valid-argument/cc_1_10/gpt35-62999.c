//FormAI DATASET v1.0 Category: Data mining ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROWS 1000
#define MAX_COLS 100

// struct to hold data from csv file
typedef struct Data {
    int val[MAX_COLS];
} Data;

// struct to hold the metadata for the csv file
typedef struct Metadata {
    int num_rows, num_cols;
    char header[MAX_COLS][20];
} Metadata;

// function to parse metadata from csv file
Metadata parse_metadata(FILE *fp) {
    Metadata md;
    char line[100], *token;
    fgets(line, sizeof(line), fp);
    token = strtok(line, ",");
    md.num_cols = 0;
    while (token != NULL) {
        strcpy(md.header[md.num_cols++], token);
        token = strtok(NULL, ",");
    }
    md.num_rows = 0;
    while (fgets(line, sizeof(line), fp)) {
        md.num_rows++;
    }
    rewind(fp);
    return md;
}

// function to parse data from csv file
Data* parse_data(FILE *fp, Metadata md) {
    Data* data = (Data*) malloc(sizeof(Data) * md.num_rows);
    char line[100], *token;
    fgets(line, sizeof(line), fp);
    int row_num = 0;
    while (fgets(line, sizeof(line), fp)) {
        token = strtok(line, ",");
        int col_num = 0;
        while (token != NULL) {
            data[row_num].val[col_num++] = atoi(token);
            token = strtok(NULL, ",");
        }
        row_num++;
    }
    return data;
}

// function to compute mean of a column
float compute_mean(Data* data, int col_num, int num_rows) {
    float total = 0;
    for (int i = 0; i < num_rows; i++) {
        total += data[i].val[col_num];
    }
    return total / num_rows;
}

// function to compute standard deviation of a column
float compute_std_dev(Data* data, int col_num, int num_rows, float mean) {
    float variance = 0;
    for (int i = 0; i < num_rows; i++) {
        variance += pow(data[i].val[col_num] - mean, 2);
    }
    return sqrt(variance / num_rows);
}

int main() {
    FILE* fp = fopen("data.csv", "r");
    Metadata md = parse_metadata(fp);
    Data* data = parse_data(fp, md);
    fclose(fp);

    printf("Data has %d rows and %d columns.\n", md.num_rows, md.num_cols);
    printf("Columns:\n");
    for (int i = 0; i < md.num_cols; i++) {
        printf("%d. %s\n", i + 1, md.header[i]);
    }

    printf("\nStatistics:\n");
    for (int i = 0; i < md.num_cols; i++) {
        float mean = compute_mean(data, i, md.num_rows);
        float std_dev = compute_std_dev(data, i, md.num_rows, mean);
        printf("%s:\n", md.header[i]);
        printf("\tMean: %f\n", mean);
        printf("\tStandard Deviation: %f\n", std_dev);
    }

    free(data);
    return 0;
}