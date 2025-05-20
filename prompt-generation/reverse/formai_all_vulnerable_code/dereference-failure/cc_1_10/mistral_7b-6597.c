//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    FILE *input_file = NULL;
    char line[MAX_LINE_LENGTH] = {0};
    size_t len = 0;
    ssize_t read = 0;
    int line_already_printed = 0;

    if (argc > 1) {
        input_file = fopen(argv[1], "r");
        if (input_file == NULL) {
            perror("Error opening file");
            return 1;
        }
    } else {
        input_file = stdin;
    }

    int *unique_lines = calloc(1, sizeof(int) * MAX_LINE_LENGTH / MAX_LINE_LENGTH);
    if (unique_lines == NULL) {
        perror("Error allocating memory");
        fclose(input_file);
        return 1;
    }

    while ((read = getline(&line, &len, input_file)) != -1) {
        char *line_copy = strdup(line);
        int hash = 0;

        for (int i = 0; i < strlen(line_copy); i++) {
            hash += line_copy[i] * (i + 1);
        }

        int index = hash % (MAX_LINE_LENGTH / MAX_LINE_LENGTH);
        if (unique_lines[index] == 0) {
            printf("%s", line);
            unique_lines[index] = 1;
            line_already_printed = 1;
        } else if (!line_already_printed) {
            free(line_copy);
        }

        free(line_copy);
    }

    fclose(input_file);
    free(unique_lines);

    return 0;
}