//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024 // maximum length of a CSV line
#define MAX_FIELD_LENGTH 256 // maximum length of a CSV field
#define MAX_FIELD_COUNT 64 // maximum number of fields in a single CSV line

/* Define the data structure for a CSV file */
typedef struct {
    char **fields; // array of field values
    int num_fields; // number of fields in the line
} csv_line;

/* Function to parse a single line from a CSV file */
csv_line *parse_csv_line(char *line) {
    csv_line *new_line = malloc(sizeof(csv_line));
    new_line->fields = malloc(sizeof(char*) * MAX_FIELD_COUNT);
    new_line->num_fields = 0;
    char *field = strtok(line, ",");
    while (field != NULL && new_line->num_fields < MAX_FIELD_COUNT) {
        new_line->fields[new_line->num_fields] = strdup(field);
        new_line->num_fields++;
        field = strtok(NULL, ",");
    }
    return new_line;
}

/* Function to free a CSV line data structure from memory */
void free_csv_line(csv_line *line) {
    int i;
    for (i = 0; i < line->num_fields; i++) {
        free(line->fields[i]);
    }
    free(line->fields);
    free(line);
}

/* Main function for the CSV reader program */
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <csv file>\n", argv[0]);
        exit(1);
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: unable to open file %s\n", argv[1]);
        exit(1);
    }
    char line[MAX_LINE_LENGTH];
    csv_line *current_line;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        current_line = parse_csv_line(line);
        printf("Line with %d fields:\n", current_line->num_fields);
        int i;
        for (i = 0; i < current_line->num_fields; i++) {
            printf("- %s\n", current_line->fields[i]);
        }
        free_csv_line(current_line);
    }
    fclose(file);
    return 0;
}