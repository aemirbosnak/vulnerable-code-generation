//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

void calculate_statistics(double *data, int count, double *mean, double *std_dev) {
    double sum = 0.0;
    double sum_squared_diff = 0.0;

    for (int i = 0; i < count; i++) {
        sum += data[i];
    }
    *mean = sum / count;

    for (int i = 0; i < count; i++) {
        sum_squared_diff += pow(data[i] - *mean, 2);
    }
    *std_dev = sqrt(sum_squared_diff / count);
}

void parse_csv(const char *filename, int column_index) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    double data[MAX_COLUMNS];
    int count = 0;

    // Read the header line
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return;
    }

    // Read data from CSV
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        int index = 0;

        while (token != NULL) {
            if (index == column_index) {
                data[count++] = atof(token);
                break; // Only store the value from the target column
            }
            token = strtok(NULL, ",");
            index++;
        }
    }
    fclose(file);

    if (count == 0) {
        printf("No data found in the specified column.\n");
        return;
    }

    double mean, std_dev;
    calculate_statistics(data, count, &mean, &std_dev);

    printf("Statistics for column %d:\n", column_index + 1);
    printf("Mean: %.2f\n", mean);
    printf("Standard Deviation: %.2f\n", std_dev);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename.csv> <column_number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    int column_number = atoi(argv[2]);

    if (column_number < 1) {
        fprintf(stderr, "Column number must be greater than 0.\n");
        return EXIT_FAILURE;
    }

    parse_csv(filename, column_number - 1);

    return EXIT_SUCCESS;
}