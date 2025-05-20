//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void csv_file_parser(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Oh dear! Could not open file '%s'.\n", filename);
        return;
    }

    char line[1024];
    int cols = 0, rows = 0;
    const size_t buff_size = 1024;
    char **buffer = malloc(buff_size * sizeof(char *));

    while (fgets(line, sizeof(line), file)) {
        ++rows;
        char *token = strtok(line, ",");
        buffer[cols] = malloc(strlen(token) + 1);
        strcpy(buffer[cols], token);
        ++cols;

        while ((token = strtok(NULL, ","))) {
            cols++;
            buffer[cols] = malloc(strlen(token) + 1);
            strcpy(buffer[cols], token);
        }
        cols = 0;
    }

    printf("Hurray! We've read %d rows and %d columns!\n", rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%s%c", buffer[j + i * cols], j < cols - 1 ? ',' : '\n');
        }
    }

    for (int i = 0; i < cols + rows * cols; ++i) {
        free(buffer[i]);
    }
    free(buffer);
    fclose(file);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename.csv>\n", argv[0]);
        return 1;
    }

    csv_file_parser(argv[1]);

    return 0;
}