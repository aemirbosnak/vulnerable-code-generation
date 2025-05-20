//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000 // Maximum length of each line in the CSV file
#define MAX_FIELD_LENGTH 100 // Maximum length of each field in the CSV file
#define DELIMITER "," // Field delimiter for the CSV file

// Structure to hold a single record
typedef struct {
    char **fields; // Array of fields in the record
    int num_fields; // Number of fields in the record
} record_t;

// Function to parse a line of CSV data into a record
record_t *parse_csv_line(char *line) {
    int num_fields = 0;
    char *field = strtok(line, DELIMITER);
    record_t *record = malloc(sizeof(record_t));
    record->fields = malloc(sizeof(char *));
    while (field != NULL) {
        num_fields++;
        record->fields = realloc(record->fields, sizeof(char *) * num_fields);
        record->fields[num_fields - 1] = malloc(sizeof(char) * MAX_FIELD_LENGTH);
        strcpy(record->fields[num_fields - 1], field);
        field = strtok(NULL, DELIMITER);
    }
    record->num_fields = num_fields;
    return record;
}

int main(int argc, char **argv) {

    char filename[MAX_FIELD_LENGTH + 1];
    printf("Enter CSV file name: ");
    fgets(filename, MAX_FIELD_LENGTH + 1, stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove trailing newline

    FILE *fp;

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH + 1];
    record_t *record;

    printf("Reading data from file %s:\n", filename);

    while (fgets(line, MAX_LINE_LENGTH + 1, fp) != NULL) {
        line[strcspn(line, "\n")] = '\0'; // Remove trailing newline
        record = parse_csv_line(line);
        printf("%d fields: ", record->num_fields);
        for (int i = 0; i < record->num_fields; i++) {
            printf("%s", record->fields[i]);
            if (i < record->num_fields - 1) {
                printf(", ");
            } else {
                printf("\n");
            }
        }
        free(record); // Free memory allocated for the record
    }

    fclose(fp);

    exit(EXIT_SUCCESS);
}