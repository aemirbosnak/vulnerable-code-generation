//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 100 // maximum length of a line in the file
#define MAX_FIELD_LEN 20 // maximum length of a field in the CSV file
#define MAX_FIELDS 10 // maximum number of fields in a row

// function to read an entire line from a file
char *readLine(FILE *file) {
    char *line = (char *)malloc(MAX_LINE_LEN * sizeof(char));
    fgets(line, MAX_LINE_LEN, file);
    return line;
}

// function to split a line into fields
char **splitLine(char *line) {
    char **fields = (char **)malloc(MAX_FIELDS * sizeof(char *));
    char *field = strtok(line, ",");
    int i = 0;
    while (field != NULL) {
        fields[i++] = strdup(field);
        field = strtok(NULL, ",");
    }
    return fields;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: csv_reader <filename>\n");
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    char *line;
    char **fields;
    while ((line = readLine(file))) {
        fields = splitLine(line);
        for (int i = 0; i < MAX_FIELDS; i++) {
            if (fields[i] != NULL) {
                printf("%s ", fields[i]);
            }
        }
        printf("\n");
        free(line);
        free(fields);
    }

    fclose(file);
    return 0;
}