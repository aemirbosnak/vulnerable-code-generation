//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *field_name;
    int field_num;
} CSVField;

typedef struct {
    int num_fields;
    CSVField *fields;
} CSVHeader;

CSVHeader *read_csv_header(FILE *fp) {
    char line[1024];
    fgets(line, 1024, fp);
    char *token;
    CSVHeader *header = malloc(sizeof(CSVHeader));
    header->num_fields = 0;
    header->fields = NULL;

    token = strtok(line, ",");
    while (token != NULL) {
        CSVField *field = malloc(sizeof(CSVField));
        field->field_name = strdup(token);
        field->field_num = header->num_fields;
        header->num_fields += 1;
        header->fields = realloc(header->fields, header->num_fields * sizeof(CSVField));
        header->fields[header->num_fields - 1] = *field;
        token = strtok(NULL, ",");
    }

    return header;
}

int main(void) {
    FILE *fp;
    char line[1024];
    int i, j;
    char *token;

    fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error: file not found\n");
        exit(1);
    }

    CSVHeader *header = read_csv_header(fp);
    printf("Header:\n");
    for (i = 0; i < header->num_fields; i++) {
        printf("%s (%d)\n", header->fields[i].field_name, header->fields[i].field_num);
    }

    printf("Data:\n");
    while (fgets(line, 1024, fp)) {
        j = 0;
        token = strtok(line, ",");
        while (token != NULL) {
            printf("%s ", token);
            j++;
            token = strtok(NULL, ",");
        }
        printf("\n");
    }
    fclose(fp);
    return 0;
}