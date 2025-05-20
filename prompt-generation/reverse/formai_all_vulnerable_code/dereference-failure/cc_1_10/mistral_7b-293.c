//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_FIELDS 256
#define MAX_FIELD_LENGTH 1024

char delim[] = ",";
char lines[MAX_LINES][MAX_FIELD_LENGTH];
char **fields;
int num_lines = 0, num_fields = 0;

void readCSVFile(char *filename) {
    FILE *fp;
    char *token;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    while (fgets(lines[num_lines], MAX_FIELD_LENGTH, fp)) {
        num_lines++;
        fields = (char **)realloc(fields, sizeof(char *) * (num_lines + 1));
        fields[num_lines - 1] = strtok(lines[num_lines - 1], delim);

        while ((token = strtok(NULL, delim))) {
            num_fields++;
            fields[num_lines - 1] = (char *)realloc(fields[num_lines - 1],
                                                   strlen(token) + 1);
            strcpy(fields[num_lines - 1] + strlen(fields[num_lines - 1]), token);
        }
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <CSV-file>\n", argv[0]);
        exit(1);
    }

    readCSVFile(argv[1]);

    // Reveal the secrets of the CSV file to our dear detective, Dr. Watson
    for (int i = 0; i < num_lines; i++) {
        for (int j = 0; j < num_fields; j++) {
            printf("%s%s%s", (j > 0) ? "," : "", fields[i][j],
                  (j < num_fields - 1) ? "|" : "\n");
        }
    }

    for (int i = 0; i < num_lines; i++) {
        free(fields[i]);
    }
    free(fields);

    return 0;
}