//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_FIELDS 10

char **parse_csv_line(char *line, int *num_fields) {
    char *field_start, *field_end;
    char **fields = malloc(MAX_FIELDS * sizeof(char *));
    int i = 0;

    field_start = line;
    while (*field_start) {
        if (i == MAX_FIELDS) {
            fprintf(stderr, "Too many fields in line, ignoring rest\n");
            break;
        }
        field_end = strchr(field_start, ',');
        if (field_end == NULL) {
            field_end = strchr(field_start, '\n');
            if (field_end == NULL) {
                field_end = field_start + strlen(field_start);
            }
        }
        *field_end = '\0';
        fields[i++] = field_start;
        field_start = field_end + 1;
    }
    *num_fields = i;
    return fields;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: csv_reader file.csv\n");
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file %s\n", argv[1]);
        exit(1);
    }

    char line[MAX_LINE];
    int num_fields;
    while (fgets(line, MAX_LINE, fp)) {
        char **fields = parse_csv_line(line, &num_fields);
        for (int i = 0; i < num_fields; i++) {
            printf("%s\n", fields[i]);
        }
        free(fields);
    }

    fclose(fp);
    return 0;
}