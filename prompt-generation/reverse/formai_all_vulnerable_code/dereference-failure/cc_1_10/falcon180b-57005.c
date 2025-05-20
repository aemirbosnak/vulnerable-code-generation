//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 1024

// Function to split a line based on a delimiter
char **split_line(char *line, char delimiter) {
    int count = 0;
    char **fields = (char **)malloc(sizeof(char *) * (MAX_FIELD_LENGTH + 1));
    char *token = strtok(line, delimiter);

    while (token!= NULL) {
        fields[count] = token;
        count++;
        token = strtok(NULL, delimiter);
    }

    fields[count] = NULL;
    return fields;
}

// Function to read a CSV file
void read_csv_file(FILE *fp, char delimiter) {
    char line[MAX_LINE_LENGTH];
    char **fields;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        fields = split_line(line, delimiter);

        for (int i = 0; fields[i]!= NULL; i++) {
            printf("%s ", fields[i]);
        }

        printf("\n");

        for (int i = 0; fields[i]!= NULL; i++) {
            free(fields[i]);
        }
        free(fields);
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <filename> <delimiter>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char delimiter = argv[2][0];

    read_csv_file(fp, delimiter);

    fclose(fp);

    return 0;
}