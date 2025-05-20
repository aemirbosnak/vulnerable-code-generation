//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 4096
#define MAX_FIELDS 100

typedef struct {
    char **data;
    int num_fields;
    int num_rows;
} CSVData;

CSVData *read_csv(FILE *fp) {
    CSVData *data = malloc(sizeof(CSVData));
    data->num_fields = 0;
    data->num_rows = 0;
    data->data = malloc(MAX_FIELDS * sizeof(char*));

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *token = strtok(line, ",");
        int i = 0;
        while (token!= NULL) {
            data->data[i] = malloc(strlen(token) + 1);
            strcpy(data->data[i], token);
            i++;
            token = strtok(NULL, ",");
        }
        data->num_fields = i;
        data->num_rows++;
    }

    return data;
}

void print_csv(CSVData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_fields; j++) {
            printf("%s ", data->data[j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    CSVData *data = read_csv(fp);
    if (data == NULL) {
        printf("Error reading file\n");
        return 1;
    }

    print_csv(data);

    for (int i = 0; i < data->num_fields; i++) {
        free(data->data[i]);
    }
    free(data->data);
    free(data);

    return 0;
}