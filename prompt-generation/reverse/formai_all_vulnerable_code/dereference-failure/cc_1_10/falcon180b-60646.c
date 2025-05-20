//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 512

char *read_line(FILE *file) {
    char line[MAX_LINE_LENGTH];
    char *result = NULL;

    if (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        result = strdup(line);
    }

    return result;
}

void print_line(const char *line) {
    printf("%s", line);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <line_number>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    int line_number = atoi(argv[2]) - 1;

    char *line = read_line(file);

    while (line_number > 0 && line!= NULL) {
        print_line(line);
        line = read_line(file);
        line_number--;
    }

    if (line!= NULL) {
        print_line(line);
    }

    fclose(file);

    return 0;
}