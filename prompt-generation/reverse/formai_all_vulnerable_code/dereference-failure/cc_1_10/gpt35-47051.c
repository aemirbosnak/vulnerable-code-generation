//FormAI DATASET v1.0 Category: File handling ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    // Open input file
    FILE *in_file = fopen(argv[1], "r");
    if (in_file == NULL) {
        printf("Error opening input file %s\n", argv[1]);
        return 1;
    }

    // Open output file
    FILE *out_file = fopen(argv[2], "w");
    if (out_file == NULL) {
        printf("Error opening output file %s\n", argv[2]);
        return 1;
    }

    // Read input file line by line
    char buffer[BUF_SIZE];
    while (fgets(buffer, BUF_SIZE, in_file) != NULL) {
        // Trim newline character if present
        char *newline = strchr(buffer, '\n');
        if (newline != NULL) {
            *newline = '\0';
        }

        // Process data
        int sum = 0;
        char *p = buffer;
        while (*p != '\0') {
            if (*p >= '0' && *p <= '9') {
                sum += *p - '0';
            }
            p++;
        }

        // Write results to output file
        fprintf(out_file, "Sum of digits in %s is %d\n", buffer, sum);
    }

    // Close files
    fclose(in_file);
    fclose(out_file);

    return 0;
}