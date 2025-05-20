//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000000

int main() {
    char *input_file = "input.txt";
    char *output_file = "output.txt";
    FILE *input_fp, *output_fp;
    char line[MAX_SIZE];
    int count = 0;

    // Open input file
    input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Open output file
    output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Read input file line by line
    while (fgets(line, MAX_SIZE, input_fp)!= NULL) {
        count++;
        if (count % 100000 == 0) {
            printf("Processed %d lines.\n", count);
        }

        // Perform some computation on each line
        int len = strlen(line);
        for (int i = 0; i < len; i++) {
            if (line[i] == 'a') {
                line[i] = 'b';
            } else if (line[i] == 'b') {
                line[i] = 'c';
            } else {
                line[i] = 'a';
            }
        }

        // Write modified line to output file
        fputs(line, output_fp);
    }

    // Close files
    fclose(input_fp);
    fclose(output_fp);

    printf("Processed %d lines.\n", count);
    return 0;
}