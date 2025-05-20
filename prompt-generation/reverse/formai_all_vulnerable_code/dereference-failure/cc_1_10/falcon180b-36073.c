//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 100
#define MAX_FIELD_NAME_LENGTH 100
#define MAX_FIELD_VALUE_LENGTH 1000

typedef struct {
    char *name;
    char *value;
} field_t;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <metadata file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    int field_count = 0;
    field_t *fields = (field_t *) malloc(MAX_FIELDS * sizeof(field_t));

    char line[MAX_FIELD_VALUE_LENGTH];
    while (fgets(line, MAX_FIELD_VALUE_LENGTH, fp)!= NULL) {
        char *ptr = strchr(line, ':');
        if (ptr == NULL) {
            continue;
        }
        *ptr = '\0';
        char *name = strdup(line);
        char *value = strdup(ptr + 1);

        if (field_count >= MAX_FIELDS) {
            printf("Maximum number of fields reached\n");
            break;
        }

        fields[field_count].name = name;
        fields[field_count].value = value;
        field_count++;
    }

    fclose(fp);

    printf("Field count: %d\n", field_count);

    for (int i = 0; i < field_count; i++) {
        printf("Name: %s\nValue: %s\n", fields[i].name, fields[i].value);
    }

    for (int i = 0; i < field_count; i++) {
        free(fields[i].name);
        free(fields[i].value);
    }
    free(fields);

    return 0;
}