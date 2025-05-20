//Falcon-180B DATASET v1.0 Category: Error handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUM_LINES 1000

typedef struct {
    char *text;
    int length;
} Line;

int main(int argc, char *argv[]) {
    FILE *input_file;
    Line *lines = NULL;
    int num_lines = 0;
    int current_line_index = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "r");

    if (input_file == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    while (num_lines < MAX_NUM_LINES && fgets(lines[num_lines].text, MAX_LINE_LENGTH, input_file)!= NULL) {
        lines[num_lines].length = strlen(lines[num_lines].text);
        num_lines++;
    }

    fclose(input_file);

    if (num_lines == 0) {
        printf("Error: File is empty.\n");
        return 1;
    }

    printf("Enter the line number to print:\n");
    scanf("%d", &current_line_index);

    if (current_line_index < 0 || current_line_index >= num_lines) {
        printf("Error: Invalid line number.\n");
        return 1;
    }

    printf("Line %d:\n", current_line_index + 1);
    printf("%s", lines[current_line_index].text);

    free(lines);

    return 0;
}