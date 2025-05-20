//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_FIELD_SIZE 50

typedef struct {
    char *fields[10];
    int count;
} Row;

typedef struct {
    Row *data;
    int count;
} CSV;

CSV* read_csv(char *filename) {
    FILE *fp;
    char buffer[MAX_BUFFER_SIZE];
    CSV *csv = (CSV*)malloc(sizeof(CSV));
    csv->data = (Row*)malloc(sizeof(Row) * MAX_BUFFER_SIZE);
    csv->count = 0;

    fp = fopen(filename, "r");
    if (!fp) {
        perror("Error opening file!");
        exit(1);
    }

    while (fgets(buffer, MAX_BUFFER_SIZE, fp)) {
        char *start = buffer;
        char *token;

        csv->data[csv->count].count = 0;

        while ((token = strsep(&start, ",")) != NULL) {
            csv->data[csv->count].fields[csv->data[csv->count].count] = (char*)malloc(sizeof(char) * MAX_FIELD_SIZE);
            strncpy(csv->data[csv->count].fields[csv->data[csv->count].count], token, MAX_FIELD_SIZE);
            csv->data[csv->count].count++;
        }

        csv->count++;
    }

    fclose(fp);

    return csv;
}

int main() {
    CSV *csv = read_csv("example.csv");

    int i, j;
    for (i = 0; i < csv->count; i++) {
        for (j = 0; j < csv->data[i].count; j++) {
            printf("%s", csv->data[i].fields[j]);
            if (j < csv->data[i].count - 1) {
                printf(",");
            }
        }
        printf("\n");
    }

    for (i = 0; i < csv->count; i++) {
        for (j = 0; j < csv->data[i].count; j++) {
            free(csv->data[i].fields[j]);
        }
    }

    free(csv->data);
    free(csv);

    return 0;
}