//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARIABLES 1000
#define MAX_VARIABLE_LENGTH 100

typedef struct {
    char name[MAX_VARIABLE_LENGTH];
    char value[MAX_VARIABLE_LENGTH];
} Variable;

void addVariable(Variable *variables, int count, char *name, char *value) {
    if (count >= MAX_VARIABLES) {
        printf("Error: Too many variables.\n");
        exit(1);
    }

    strncpy(variables[count].name, name, MAX_VARIABLE_LENGTH);
    strncpy(variables[count].value, value, MAX_VARIABLE_LENGTH);

    count++;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s file.c metadata_file.txt\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    Variable variables[MAX_VARIABLES];
    int count = 0;

    FILE *metadata = fopen(argv[2], "w");
    if (metadata == NULL) {
        printf("Error: Could not open metadata file.\n");
        return 1;
    }

    while ((read = getline(&line, &len, file))!= -1) {
        char *comment = strstr(line, "//");
        if (comment!= NULL) {
            *comment = '\0';
            comment += 2;

            char *name = strtok(comment, " \t\r\n");
            char *value = strtok(NULL, " \t\r\n");

            if (name!= NULL && value!= NULL) {
                addVariable(variables, count, name, value);
            }
        }
    }

    fprintf(metadata, "Variable count: %d\n", count);
    for (int i = 0; i < count; i++) {
        fprintf(metadata, "Name: %s\nValue: %s\n", variables[i].name, variables[i].value);
    }

    fclose(file);
    fclose(metadata);

    return 0;
}