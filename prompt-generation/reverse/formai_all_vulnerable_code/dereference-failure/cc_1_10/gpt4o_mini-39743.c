//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINES 1000
#define MAX_LENGTH 100

void calculate_statistics(double data[], int n, double *mean, double *median, double *stddev) {
    double sum = 0.0;
    // Calculate mean
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    *mean = sum / n;

    // Calculate median
    // Sorting the data
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (data[i] > data[j]) {
                double temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    if (n % 2 == 0) {
        *median = (data[n/2 - 1] + data[n/2]) / 2.0;
    } else {
        *median = data[n/2];
    }

    // Calculate standard deviation
    double variance = 0.0;
    for (int i = 0; i < n; i++) {
        variance += pow(data[i] - *mean, 2);
    }
    variance /= n;
    *stddev = sqrt(variance);
}

int read_data(const char *filename, double data[], int column_index) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return -1;
    }

    char line[MAX_LENGTH];
    int count = 0;

    while (fgets(line, sizeof(line), file) && count < MAX_LINES) {
        char *token = strtok(line, ",");
        int index = 0;
        while (token != NULL) {
            if (index == column_index) {
                data[count] = atof(token);
                count++;
                break;
            }
            token = strtok(NULL, ",");
            index++;
        }
    }

    fclose(file);
    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <column_index>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    int column_index = atoi(argv[2]);
    
    double data[MAX_LINES];
    int n = read_data(filename, data, column_index);
    
    if (n < 0) {
        return 1;
    }
    
    double mean, median, stddev;
    calculate_statistics(data, n, &mean, &median, &stddev);
    
    printf("Column Index: %d\n", column_index);
    printf("Count: %d\n", n);
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    printf("Standard Deviation: %.2f\n", stddev);

    return 0;
}