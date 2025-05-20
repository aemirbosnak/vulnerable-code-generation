//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define NUM_COLUMNS 5

typedef struct {
    char line[MAX_LINE_LENGTH];
    float values[NUM_COLUMNS];
    int index[NUM_COLUMNS];
} CSV_LINE;

void extract_values(CSV_LINE *line, int column_index) {
    char *token = strtok(line->line, ",");
    int i;
    for (i = 0; i < column_index; i++) {
        token = strtok(NULL, ",");
        line->index[i] = atoi(token);
    }
    for (i = column_index; i < NUM_COLUMNS; i++) {
        token = strtok(NULL, ",");
        line->values[i] = atof(token);
    }
}

float calculate_average(float *data, int size) {
    int i;
    float sum = 0;
    for (i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}

int main() {
    FILE *file;
    CSV_LINE current_line;
    int column_index = 2; // column index for average calculation
    int line_number = 0;
    float column_sum[NUM_COLUMNS];
    float column_avg[NUM_COLUMNS];

    file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    while (fgets(current_line.line, MAX_LINE_LENGTH, file)) {
        line_number++;
        extract_values(&current_line, NUM_COLUMNS);
        column_sum[column_index] += current_line.values[column_index];
    }

    fclose(file);

    column_avg[column_index] = calculate_average(column_sum, line_number);
    printf("Line %d: Average value of column %d is %.2f\n", line_number, column_index, column_avg[column_index]);

    return 0;
}