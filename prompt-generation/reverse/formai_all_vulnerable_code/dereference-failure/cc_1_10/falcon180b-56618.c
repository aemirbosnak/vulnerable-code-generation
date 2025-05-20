//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 64
#define MAX_VALUE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Field;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *p, *q;
    int line_number = 0;
    int num_fields = 0;
    Field fields[MAX_FIELDS];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <metadata_file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        line_number++;

        // Remove leading and trailing whitespace
        p = line;
        while (isspace(*p)) {
            p++;
        }
        q = p + strlen(p) - 1;
        while (isspace(*q)) {
            q--;
            *q = '\0';
        }

        // Parse line into key-value pairs
        num_fields = 0;
        p = strtok(p, ":");
        while (p!= NULL) {
            if (num_fields >= MAX_FIELDS) {
                fprintf(stderr, "Too many fields on line %d\n", line_number);
                return 1;
            }
            strcpy(fields[num_fields].key, p);
            p = strtok(NULL, ":");
            if (p == NULL) {
                fprintf(stderr, "Missing value on line %d\n", line_number);
                return 1;
            }
            strcpy(fields[num_fields].value, p);
            num_fields++;
            p = strtok(NULL, ":");
        }

        // Print fields
        for (int i = 0; i < num_fields; i++) {
            printf("%s: %s\n", fields[i].key, fields[i].value);
        }
    }

    fclose(fp);
    return 0;
}