//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, input_file)!= NULL) {
        // Remove leading and trailing whitespace
        char *start = line;
        while (isspace(*start)) {
            start++;
        }
        char *end = start + strlen(start) - 1;
        while (isspace(*end)) {
            end--;
        }
        *end = '\0';

        // Remove comments
        char *comment_start = strstr(start, "//");
        if (comment_start!= NULL) {
            *comment_start = '\0';
        }

        // Write line to output file
        fprintf(output_file, "%s\n", start);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}