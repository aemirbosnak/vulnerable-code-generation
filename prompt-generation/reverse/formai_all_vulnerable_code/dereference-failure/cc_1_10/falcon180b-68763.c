//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024

// Function to split a line into individual fields based on comma delimiter
char **split_line(char *line) {
    int count = 0;
    char **fields = NULL;
    char *token = strtok(line, ",");

    while (token!= NULL) {
        count++;
        fields = realloc(fields, sizeof(char *) * count);
        fields[count - 1] = strdup(token);
        token = strtok(NULL, ",");
    }

    fields[count - 1] = NULL;
    return fields;
}

// Function to free memory allocated for fields array
void free_fields(char **fields) {
    int i;

    for (i = 0; fields[i]!= NULL; i++) {
        free(fields[i]);
    }
    free(fields);
}

// Function to read CSV file and print its contents
void read_csv_file(FILE *fp) {
    char line[MAX_LINE_SIZE];
    char **fields = NULL;

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        fields = split_line(line);
        printf("Line %zu:\n", ftell(fp) - strlen(line) + 1);
        int i;
        for (i = 0; fields[i]!= NULL; i++) {
            printf("%s\t", fields[i]);
        }
        printf("\n");
        free_fields(fields);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    read_csv_file(fp);

    fclose(fp);
    return 0;
}