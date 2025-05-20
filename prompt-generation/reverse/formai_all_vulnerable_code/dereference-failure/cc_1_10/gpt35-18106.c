//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_FIELDS 20

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s <input_filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (!file) {
        printf("Unable to open file '%s'\n", filename);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char *field;
    char *fields[MAX_NUM_FIELDS];
    int num_fields = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)) {

        // Remove newline character from line
        line[strcspn(line, "\n")] = '\0';

        // Tokenize line by comma delimiter
        field = strtok(line, ",");

        while (field) {

            // Add field to field list
            fields[num_fields] = malloc(strlen(field) + 1);
            strcpy(fields[num_fields], field);
            num_fields++;

            // Check if too many fields
            if (num_fields > MAX_NUM_FIELDS) {
                printf("Too many fields in line\n");
                return 1;
            }

            // Get next field
            field = strtok(NULL, ",");
        }

        // Print fields in line
        printf("Fields in line: %d\n", num_fields);
        for (int i = 0; i < num_fields; i++) {
            printf("%d: %s\n", i, fields[i]);
            free(fields[i]);
        }

        num_fields = 0;
    }

    fclose(file);

    return 0;
}