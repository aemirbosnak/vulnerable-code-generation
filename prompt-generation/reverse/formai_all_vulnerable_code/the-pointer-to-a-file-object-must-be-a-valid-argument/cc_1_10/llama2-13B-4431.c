//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_SIZE 100000

// Function to read a line from a file and calculate its statistical properties
void read_line(FILE *file, char *line, int *len, double *avg, double *stddev) {
    int i;
    double sum = 0;
    double sum_squared = 0;

    // Read the line from the file
    *len = fread(line, 1, MAX_LINE_LENGTH, file);
    line[*len] = '\0';

    // Calculate the average and standard deviation of the line
    for (i = 0; i < *len; i++) {
        sum += line[i];
        sum_squared += line[i] * line[i];
    }

    *avg = sum / *len;
    *stddev = sqrt(sum_squared / (*len - 1));
}

// Function to read a file and calculate its statistical properties
void read_file(char *filename, int *file_size, double *avg, double *stddev) {
    FILE *file = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];
    int len;

    // Calculate the size of the file
    *file_size = 0;
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        *file_size += strlen(line) + 1;
    }

    // Calculate the average and standard deviation of the file
    int num_lines = 0;
    double sum = 0;
    double sum_squared = 0;
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        num_lines++;
        read_line(file, line, &len, &sum, &sum_squared);
    }

    *avg = sum / num_lines;
    *stddev = sqrt(sum_squared / (num_lines - 1));

    fclose(file);
}

int main() {
    char *filename = "example.txt";
    int file_size = 0;
    double avg = 0;
    double stddev = 0;

    // Read the file and calculate its statistical properties
    read_file(filename, &file_size, &avg, &stddev);

    // Print the results
    printf("File size: %d\n", file_size);
    printf("Average: %f\n", avg);
    printf("Standard deviation: %f\n", stddev);

    return 0;
}