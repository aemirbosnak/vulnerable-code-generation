//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSV_Record {
    char **data;
    int num_fields;
} CSV_Record;

CSV_Record *read_csv(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    CSV_Record *record = malloc(sizeof(CSV_Record));
    record->data = NULL;
    record->num_fields = 0;

    char buffer[MAX_BUFFER_SIZE];
    int line_num = 0;
    while (fgets(buffer, MAX_BUFFER_SIZE, fp) != NULL) {
        line_num++;
        char *field_start = strchr(buffer, ',');
        if (field_start != NULL) {
            char **new_data = realloc(record->data, (record->num_fields + 1) * sizeof(char *));
            record->data = new_data;
            record->data[record->num_fields++] = strdup(field_start + 1);
        }
    }

    fclose(fp);
    return record;
}

int main() {
    char *filename = "data.csv";
    CSV_Record *record = read_csv(filename);

    if (record) {
        for (int i = 0; i < record->num_fields; i++) {
            printf("%s,", record->data[i]);
        }
        printf("\n");

        free(record->data);
        free(record);
    } else {
        printf("Error reading CSV file.\n");
    }

    return 0;
}