//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_LINE_LENGTH 1000

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    int line_number;
    char line[MAX_LINE_LENGTH];
} LineInfo;

int compare_line_info(const void *a, const void *b) {
    const LineInfo *line_info_a = (const LineInfo *)a;
    const LineInfo *line_info_b = (const LineInfo *)b;

    if (line_info_a->line_number < line_info_b->line_number) {
        return -1;
    } else if (line_info_a->line_number > line_info_b->line_number) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    FILE *input_file = NULL;
    char input_file_name[MAX_FILE_NAME_LENGTH];
    char line[MAX_LINE_LENGTH];
    LineInfo lines[MAX_LINE_LENGTH];
    int num_lines = 0;
    int i;

    if (argc!= 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    strcpy(input_file_name, argv[1]);

    input_file = fopen(input_file_name, "r");

    if (input_file == NULL) {
        printf("Error opening input file: %s\n", input_file_name);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        if (num_lines >= MAX_LINE_LENGTH) {
            printf("Maximum number of lines reached.\n");
            break;
        }

        lines[num_lines].file_name[0] = '\0';
        strcat(lines[num_lines].file_name, input_file_name);
        lines[num_lines].line_number = num_lines + 1;
        strcpy(lines[num_lines].line, line);

        num_lines++;
    }

    if (ferror(input_file)) {
        printf("Error reading input file: %s\n", input_file_name);
        return 1;
    }

    fclose(input_file);

    qsort(lines, num_lines, sizeof(LineInfo), compare_line_info);

    printf("Line number\tFile name\tLine\n");

    for (i = 0; i < num_lines; i++) {
        printf("%d\t%s\t%s", lines[i].line_number, lines[i].file_name, lines[i].line);
    }

    return 0;
}