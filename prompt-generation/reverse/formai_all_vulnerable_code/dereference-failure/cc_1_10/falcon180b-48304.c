//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to calculate the checksum of a string
int calculate_checksum(char *str) {
    int checksum = 0;
    int i;

    for (i = 0; i < strlen(str); i++) {
        checksum += str[i];
    }

    return checksum;
}

// Function to read a line from the input file
char *read_line(FILE *file) {
    char *line = (char *) malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory.\n");
        exit(1);
    }

    fgets(line, MAX_LINE_LENGTH, file);
    line[strcspn(line, "\n")] = '\0';

    return line;
}

// Function to write the checksum to the output file
void write_checksum(FILE *file, int checksum) {
    fprintf(file, "%d\n", checksum);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Failed to open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Failed to open output file.\n");
        return 1;
    }

    char *line;
    int checksum = 0;

    while ((line = read_line(input_file))!= NULL) {
        int line_checksum = calculate_checksum(line);
        write_checksum(output_file, line_checksum);
        checksum += line_checksum;
    }

    write_checksum(output_file, checksum);

    fclose(input_file);
    fclose(output_file);

    return 0;
}