//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10
#define MAX_LINE_LENGTH 1024

int main(void)
{
    // File handling variables
    FILE *file_ptr;
    char file_name[50];
    char line[MAX_LINE_LENGTH];
    int line_count = 0;
    int file_size = 0;

    // Set the file name
    printf("Enter the file name: ");
    fgets(file_name, 50, stdin);

    // Open the file in read/write mode
    file_ptr = fopen(file_name, "r+");
    if (file_ptr == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Get the file size
    file_size = ftell(file_ptr);
    if (file_size == -1L) {
        perror("Error getting file size");
        return 1;
    }

    // Print the file size
    printf("File size: %ld bytes\n", file_size);

    // Read the file line by line
    while (fgets(line, MAX_LINE_LENGTH, file_ptr) != NULL) {
        line_count++;
        printf("%d: %s\n", line_count, line);
    }

    // Calculate the average line length
    double average_length = 0;
    for (int i = 0; i < line_count; i++) {
        average_length += strlen(line[i]);
    }
    average_length /= line_count;
    printf("Average line length: %.2f\n", average_length);

    // Calculate the standard deviation of line lengths
    double standard_deviation = 0;
    for (int i = 0; i < line_count; i++) {
        double length = strlen(line[i]);
        standard_deviation += (length - average_length) * (length - average_length);
    }
    standard_deviation /= line_count;
    standard_deviation = sqrt(standard_deviation);
    printf("Standard deviation of line lengths: %.2f\n", standard_deviation);

    // Close the file
    fclose(file_ptr);

    return 0;
}