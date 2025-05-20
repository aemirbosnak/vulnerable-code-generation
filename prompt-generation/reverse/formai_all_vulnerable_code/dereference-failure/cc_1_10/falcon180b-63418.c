//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to calculate the checksum of a string
int checksum(char *str) {
    int sum = 0;
    int i;
    for (i = 0; i < strlen(str); i++) {
        sum += (int)str[i];
    }
    return sum % 256;
}

// Function to read a line from a file
char *read_line(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    fgets(line, MAX_LINE_LENGTH, file);
    return line;
}

// Function to write a line to a file
void write_line(FILE *file, char *line) {
    fprintf(file, "%s\n", line);
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char *line = read_line(input_file);
    while (line!= NULL) {
        int checksum_value = checksum(line);
        sprintf(line + strlen(line), "%d\n", checksum_value);
        write_line(output_file, line);
        line = read_line(input_file);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}