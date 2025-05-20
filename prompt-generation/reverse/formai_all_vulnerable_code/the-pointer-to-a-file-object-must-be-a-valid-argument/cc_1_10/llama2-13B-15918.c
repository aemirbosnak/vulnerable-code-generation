//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_SIZE 100000

// Function to read a line from a file and calculate its statistical properties
void read_line(FILE *file, char *line, int *length, double *mean, double *stddev) {
    int i;
    double sum = 0;
    double square_sum = 0;

    // Read a line from the file
    fgets(line, MAX_LINE_LENGTH, file);

    // Calculate the length of the line
    *length = strlen(line);

    // Calculate the mean of the line
    for (i = 0; i < *length; i++) {
        sum += line[i];
    }
    *mean = sum / *length;

    // Calculate the standard deviation of the line
    for (i = 0; i < *length; i++) {
        square_sum += (line[i] - *mean) * (line[i] - *mean);
    }
    *stddev = sqrt(square_sum / *length);
}

// Function to calculate the statistical properties of a file
void calculate_statistics(FILE *file, char *file_name) {
    int line_number = 0;
    char line[MAX_LINE_LENGTH];
    int length;
    double mean = 0;
    double stddev = 0;

    // Read the file line by line
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        // Calculate the statistical properties of the current line
        read_line(file, line, &length, &mean, &stddev);

        // Print the statistical properties of the current line
        printf("%d: mean = %f, stddev = %f\n", line_number, mean, stddev);

        // Increment the line number
        line_number++;
    }
}

int main() {
    // Open a file for reading
    FILE *file = fopen("data.txt", "r");

    // Calculate the statistical properties of the file
    calculate_statistics(file, "data.txt");

    // Close the file
    fclose(file);

    return 0;
}