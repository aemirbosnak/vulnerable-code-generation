//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000

typedef struct {
    char *text;
    int length;
} Line;

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[MAX_LINE_LENGTH];
    Line *lines = NULL;
    int num_lines = 0;
    int i, j;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read each line of the file and store in linked list
    while (fgets(filename, MAX_LINE_LENGTH, file)!= NULL) {
        num_lines++;
        if (num_lines > MAX_NUM_LINES) {
            printf("Error: too many lines in file.\n");
            fclose(file);
            return 1;
        }
        lines = realloc(lines, sizeof(Line) * num_lines);
        if (lines == NULL) {
            printf("Error: memory allocation failed.\n");
            fclose(file);
            return 1;
        }
        lines[num_lines - 1].text = strdup(filename);
        lines[num_lines - 1].length = strlen(filename);
    }

    // Print each line of the file
    printf("File contents:\n");
    for (i = 0; i < num_lines; i++) {
        printf("%d: %s\n", i + 1, lines[i].text);
    }

    // Prompt user for search string
    printf("Enter search string: ");
    scanf("%s", filename);

    // Search for search string in file
    for (i = 0; i < num_lines; i++) {
        if (strstr(lines[i].text, filename)!= NULL) {
            printf("Line %d contains search string.\n", i + 1);
        }
    }

    // Free memory and close file
    for (i = 0; i < num_lines; i++) {
        free(lines[i].text);
    }
    free(lines);
    fclose(file);

    return 0;
}