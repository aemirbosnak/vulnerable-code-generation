//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

void process_line(char *line);

int main() {
    FILE *input_file, *output_file;
    char line[MAX_LINE_LENGTH];

    input_file = fopen(INPUT_FILE, "r");
    output_file = fopen(OUTPUT_FILE, "w");

    if (input_file == NULL || output_file == NULL) {
        perror("Could not open files");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        process_line(line);
        fprintf(output_file, "%s", line);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}

void process_line(char *line) {
    int i, j;
    char temp;

    for (i = 0; i < strlen(line); i++) {
        if (isspace(line[i])) {
            for (j = i; j < strlen(line); j++) {
                if (!isspace(line[j])) {
                    temp = line[i];
                    line[i] = line[j];
                    line[j] = temp;
                    break;
                }
            }
        }
    }

    for (i = 0; i < strlen(line); i++) {
        if (isalpha(line[i])) {
            line[i] = toupper(line[i]);
        }
    }
}