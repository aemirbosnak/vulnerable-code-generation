//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 4096
#define MAX_FIELDS 100
#define DELIMITER ","

void process_line(char **fields, int num_fields);

int main(int argc, char **argv)
{
    FILE *csv_file;
    char line[MAX_LINE_LENGTH];
    char *token;
    char **fields;
    int num_fields;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    csv_file = fopen(argv[1], "r");
    if (!csv_file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (getline(&line, sizeof(line), csv_file) > 0) {
        num_fields = 0;
        fields = malloc(MAX_FIELDS * sizeof(char *));

        token = strtok(line, DELIMITER);
        while (token) {
            if (num_fields >= MAX_FIELDS) {
                fprintf(stderr, "Too many fields in line: %s\n", line);
                break;
            }
            fields[num_fields] = token;
            num_fields++;
            token = strtok(NULL, DELIMITER);
        }

        process_line(fields, num_fields);
        free(fields);
    }

    fclose(csv_file);
    exit(EXIT_SUCCESS);
}

void process_line(char **fields, int num_fields)
{
    int i;
    for (i = 0; i < num_fields; i++) {
        printf("Field %d: %s\n", i + 1, fields[i]);
    }
}