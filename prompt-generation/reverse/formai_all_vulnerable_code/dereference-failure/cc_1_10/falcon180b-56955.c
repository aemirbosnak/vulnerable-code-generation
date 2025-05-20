//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *data;
    int length;
} Line;

Line read_line(FILE *file) {
    char line[MAX_LINE_SIZE];
    Line result;

    result.data = NULL;
    result.length = 0;

    if (fgets(line, MAX_LINE_SIZE, file) == NULL) {
        return result;
    }

    result.data = strdup(line);
    result.length = strlen(result.data);

    return result;
}

void free_line(Line line) {
    free(line.data);
}

int main() {
    FILE *file;
    char filename[MAX_LINE_SIZE];
    Line line;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while ((line = read_line(file)).length > 0) {
        printf("%d characters: %s\n", line.length, line.data);
        free_line(line);
    }

    fclose(file);

    return 0;
}