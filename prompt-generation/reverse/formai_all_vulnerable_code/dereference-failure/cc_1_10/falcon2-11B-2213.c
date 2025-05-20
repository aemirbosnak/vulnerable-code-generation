//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[256];
    int age;
    char gender;
} Person;

typedef struct {
    int line_count;
    int column_count;
    char **data;
} CsvFile;

CsvFile *read_csv_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open file '%s'\n", filename);
        exit(1);
    }

    CsvFile *csv_file = malloc(sizeof(CsvFile));
    csv_file->line_count = 0;
    csv_file->column_count = 0;
    csv_file->data = NULL;

    int header = 1;
    char line[512];
    while (fgets(line, sizeof(line), file)) {
        csv_file->line_count++;
        if (strlen(line) == 0 || line[0] == '#')
            continue;

        char *token;
        token = strtok(line, ",");
        while (token!= NULL) {
            char *ptr = strchr(token, '"');
            if (ptr)
                *ptr = '\0';
            csv_file->data = realloc(csv_file->data, (csv_file->column_count + 1) * sizeof(char *));
            csv_file->data[csv_file->column_count] = malloc(strlen(token) + 1);
            strcpy(csv_file->data[csv_file->column_count], token);
            csv_file->column_count++;
            token = strtok(NULL, ",");
        }
    }
    fclose(file);
    return csv_file;
}

void free_csv_file(CsvFile *csv_file) {
    if (csv_file->data!= NULL) {
        for (int i = 0; i < csv_file->column_count; i++) {
            free(csv_file->data[i]);
        }
        free(csv_file->data);
    }
    free(csv_file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    CsvFile *csv_file = read_csv_file(argv[1]);
    if (!csv_file) {
        fprintf(stderr, "Failed to read CSV file\n");
        return 1;
    }

    printf("Number of lines: %d\n", csv_file->line_count);
    printf("Number of columns: %d\n", csv_file->column_count);

    for (int i = 0; i < csv_file->column_count; i++) {
        printf("%s\n", csv_file->data[i]);
    }

    free_csv_file(csv_file);
    return 0;
}