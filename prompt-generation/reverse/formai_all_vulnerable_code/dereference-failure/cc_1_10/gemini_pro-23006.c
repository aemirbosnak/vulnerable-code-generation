//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: Sherlock Holmes
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Watson, fetch the data!
char *slurp(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    char *buffer = malloc(size + 1);
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }
    fread(buffer, 1, size, file);
    fclose(file);
    buffer[size] = '\0';
    return buffer;
}

// Now, let us put the magnifying glass on this data
void analyze(char *data) {
    printf("Dear Watson, I have analyzed the data and found the following:\n");
    int num_lines = 0;
    char *line = strtok(data, "\n");
    while (line != NULL) {
        num_lines++;
        printf("%d. %s\n", num_lines, line);
        line = strtok(NULL, "\n");
    }
    printf("\nElementary, my dear Watson! We have %d lines in this text.\n", num_lines);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }
    char *data = slurp(argv[1]);
    if (data == NULL) {
        return EXIT_FAILURE;
    }
    analyze(data);
    free(data);
    return EXIT_SUCCESS;
}