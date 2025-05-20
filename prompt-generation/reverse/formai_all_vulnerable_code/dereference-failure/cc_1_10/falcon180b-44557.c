//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char input_file[256];
    char output_file[256];
    FILE *input_fp = NULL;
    FILE *output_fp = NULL;
    char line[256];
    char *token;
    int checksum = 0;

    // Get input and output file names
    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Open input file for reading
    input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        printf("Error: could not open input file %s\n", input_file);
        exit(1);
    }

    // Open output file for writing
    output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        printf("Error: could not open output file %s\n", output_file);
        exit(1);
    }

    // Loop through input file and calculate checksum
    while (fgets(line, sizeof(line), input_fp)!= NULL) {
        token = strtok(line, " \t\n");
        while (token!= NULL) {
            checksum += atoi(token);
            token = strtok(NULL, " \t\n");
        }
    }

    // Write checksum to output file
    fprintf(output_fp, "Checksum: %d\n", checksum);

    // Close input and output files
    fclose(input_fp);
    fclose(output_fp);

    return 0;
}