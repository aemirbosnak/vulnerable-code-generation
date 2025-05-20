//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int get_csv_field_count(char* line) {
    int count = 0;
    char* ptr = strtok(line, ",");
    while (ptr != NULL) {
        count++;
        ptr = strtok(NULL, ",");
    }
    return count;
}

void read_csv_header(FILE* fp, char** header_fields, int header_field_count) {
    char line[MAX_LINE_LENGTH];
    if (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        char* ptr = strtok(line, ",");
        int i = 0;
        while (ptr != NULL && i < header_field_count) {
            header_fields[i++] = strndup(ptr, strlen(ptr) - 1);
            ptr = strtok(NULL, ",");
        }
    }
}

void read_csv_records(FILE* fp, char*** records, int* record_count, int field_count) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        char* ptr = strtok(line, ",");
        int i = 0;
        (*records)[*record_count] = calloc(field_count, sizeof(char*));
        while (ptr != NULL && i < field_count) {
            (*records)[*record_count][i++] = strndup(ptr, strlen(ptr) - 1);
            ptr = strtok(NULL, ",");
        }
        (*record_count)++;
    }
}


int main() {
    FILE* fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
        printf("No content found\n");
        return 0;
    }

    int field_count = get_csv_field_count(line);
    char** header_fields = calloc(field_count, sizeof(char*));
    read_csv_header(fp, header_fields, field_count);
    int record_count = 0;
    char*** records = malloc(sizeof(char**));

    read_csv_records(fp, records, &record_count, field_count);

    fclose(fp);

    printf("Header fields:\n");
    for (int i = 0; i < field_count; i++) {
        printf("%s ", header_fields[i]);
    }
    printf("\n");
    printf("Total records: %d\n", record_count);
    printf("Records:\n");
    for (int i = 0; i < record_count; i++) {
        for (int j = 0; j < field_count; j++) {
            printf("%s ", records[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < record_count; i++) {
        for (int j = 0; j < field_count; j++) {
            free(records[i][j]);
        }
        free(records[i]);
    }
    free(records);
    for (int i = 0; i < field_count; i++) {
        free(header_fields[i]);
    }
    free(header_fields);

    return 0;
}