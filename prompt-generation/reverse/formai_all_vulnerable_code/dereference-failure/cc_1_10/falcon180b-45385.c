//Falcon-180B DATASET v1.0 Category: Error handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: failed to open input file '%s': %s\n", argv[1], strerror(errno));
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error: failed to open output file '%s': %s\n", argv[2], strerror(errno));
        fclose(input_file);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        char *newline = strchr(line, '\n');
        if (newline!= NULL) {
            *newline = '\0';
        }

        if (fputs(line, output_file) == EOF) {
            fprintf(stderr, "Error: failed to write to output file: %s\n", strerror(errno));
            fclose(input_file);
            fclose(output_file);
            remove(argv[2]);
            return 1;
        }
    }

    if (fclose(input_file)!= 0) {
        fprintf(stderr, "Error: failed to close input file: %s\n", strerror(errno));
        fclose(output_file);
        remove(argv[2]);
        return 1;
    }

    if (fclose(output_file)!= 0) {
        fprintf(stderr, "Error: failed to close output file: %s\n", strerror(errno));
        remove(argv[2]);
        return 1;
    }

    return 0;
}