//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

typedef struct {
    char **data;
    int num_cols;
    int num_rows;
} csv_data;

csv_data *read_csv(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    csv_data *data = malloc(sizeof(csv_data));
    data->data = NULL;
    data->num_cols = 0;
    data->num_rows = 0;

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        char *p = line;
        data->num_cols = 0;
        while ((p = strtok(p, ",")) != NULL) {
            data->data = realloc(data->data, sizeof(char *) * (data->num_cols + 1));
            data->data[data->num_cols++] = strdup(p);
        }
        data->num_rows++;
    }

    fclose(fp);

    return data;
}

void free_csv_data(csv_data *data) {
    for (int i = 0; i < data->num_rows; i++) {
        free(data->data[i]);
    }
    free(data->data);
    free(data);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    csv_data *data = read_csv(argv[1]);
    if (data == NULL) {
        fprintf(stderr, "Error reading CSV file.\n");
        return 1;
    }

    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_cols; j++) {
            printf("%s ", data->data[i][j]);
        }
        printf("\n");
    }

    free_csv_data(data);

    return 0;
}