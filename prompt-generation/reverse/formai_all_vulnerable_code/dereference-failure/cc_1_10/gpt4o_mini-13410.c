//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 20

typedef struct {
    double *data;
    int count;
} ColumnData;

void cleanBuffer() {
    while(getchar() != '\n');
}

void loadData(const char *filename, ColumnData *columns, int *columnCount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    *columnCount = 0;

    // Read the header line
    if (fgets(line, sizeof(line), file)) {
        char *columnName = strtok(line, ",");
        while (columnName != NULL) {
            columns[*columnCount].data = NULL;
            columns[*columnCount].count = 0;
            *columnCount += 1;
            columnName = strtok(NULL, ",");
        }
    }

    while (fgets(line, sizeof(line), file)) {
        char *token;
        int columnIndex = 0;
        
        token = strtok(line, ",");
        while (token != NULL && columnIndex < *columnCount) {
            columns[columnIndex].data = realloc(columns[columnIndex].data, 
                                                (columns[columnIndex].count + 1) * sizeof(double));
            columns[columnIndex].data[columns[columnIndex].count] = atof(token);
            columns[columnIndex].count += 1;
            token = strtok(NULL, ",");
            columnIndex++;
        }
    }

    fclose(file);
}

double calculateMean(ColumnData *column) {
    if (column->count == 0) return 0;
    double sum = 0.0;
    for (int i = 0; i < column->count; i++) {
        sum += column->data[i];
    }
    return sum / column->count;
}

double calculateMedian(ColumnData *column) {
    if (column->count == 0) return 0;
    double *temp = malloc(column->count * sizeof(double));
    memcpy(temp, column->data, column->count * sizeof(double));

    // Sort the data
    for (int i = 0; i < column->count - 1; i++) {
        for (int j = i + 1; j < column->count; j++) {
            if (temp[i] > temp[j]) {
                double swap = temp[i];
                temp[i] = temp[j];
                temp[j] = swap;
            }
        }
    }

    double median;
    if (column->count % 2 == 0) {
        median = (temp[column->count / 2 - 1] + temp[column->count / 2]) / 2;
    } else {
        median = temp[column->count / 2];
    }

    free(temp);
    return median;
}

double calculateStandardDeviation(ColumnData *column, double mean) {
    if (column->count == 0) return 0;
    double sum = 0.0;
    for (int i = 0; i < column->count; i++) {
        sum += (column->data[i] - mean) * (column->data[i] - mean);
    }
    return sqrt(sum / column->count);
}

void displayStatistics(ColumnData *column, int columnIndex) {
    double mean = calculateMean(column);
    double median = calculateMedian(column);
    double stdDev = calculateStandardDeviation(column, mean);

    printf("Statistics for Column %d:\n", columnIndex + 1);
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    printf("Standard Deviation: %.2f\n", stdDev);
}

int main() {
    ColumnData columns[MAX_COLUMNS];
    int columnCount = 0;

    const char *filename = "data.csv";
    loadData(filename, columns, &columnCount);

    int choice;
    while (1) {
        printf("Select a column to analyze (1 to %d, 0 to exit): ", columnCount);
        scanf("%d", &choice);
        cleanBuffer();
        
        if (choice == 0) break;
        if (choice < 1 || choice > columnCount) {
            printf("Invalid choice. Try again.\n");
            continue;
        }

        displayStatistics(&columns[choice - 1], choice - 1);
    }

    // Free allocated memory
    for (int i = 0; i < columnCount; i++) {
        free(columns[i].data);
    }

    return 0;
}