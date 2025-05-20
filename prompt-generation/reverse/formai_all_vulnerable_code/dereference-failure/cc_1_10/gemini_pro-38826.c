//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_NAMES_COUNT 148
#define COLOR_CODES_COUNT 216

typedef struct {
    char *name;
    char *code;
} Color;

Color colors[COLOR_NAMES_COUNT];

int compare_colors(const void *a, const void *b) {
    return strcmp(((const Color *)a)->name, ((const Color *)b)->name);
}

int main() {
    FILE *fp;
    char line[1024];
    char *name, *code;
    int i, j;

    // Read color names and codes from file
    fp = fopen("colors.txt", "r");
    if (fp == NULL) {
        perror("Error opening colors.txt");
        return EXIT_FAILURE;
    }

    i = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        name = strtok(line, ":");
        code = strtok(NULL, "\n");
        colors[i].name = strdup(name);
        colors[i].code = strdup(code);
        i++;
    }

    fclose(fp);

    // Sort colors by name
    qsort(colors, COLOR_NAMES_COUNT, sizeof(Color), compare_colors);

    // Print color names and codes
    printf("Color Names and Codes:\n");
    for (i = 0; i < COLOR_NAMES_COUNT; i++) {
        printf("%s: %s\n", colors[i].name, colors[i].code);
    }

    // Free memory
    for (i = 0; i < COLOR_NAMES_COUNT; i++) {
        free(colors[i].name);
        free(colors[i].code);
    }

    return EXIT_SUCCESS;
}