//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} csv_data;

csv_data *read_csv(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Read the first line to get the number of columns
    char line[1024];
    fgets(line, sizeof(line), fp);
    int num_cols = 0;
    char *ptr = strtok(line, ",");
    while (ptr != NULL) {
        num_cols++;
        ptr = strtok(NULL, ",");
    }

    // Read the rest of the lines to get the number of rows and the data
    csv_data *data = malloc(sizeof(csv_data));
    data->num_rows = 0;
    data->num_cols = num_cols;
    data->data = malloc(sizeof(char *) * num_cols);
    while (fgets(line, sizeof(line), fp) != NULL) {
        data->num_rows++;
        ptr = strtok(line, ",");
        int col = 0;
        while (ptr != NULL) {
            data->data[col] = malloc(strlen(ptr) + 1);
            strcpy(data->data[col], ptr);
            col++;
            ptr = strtok(NULL, ",");
        }
    }

    fclose(fp);

    return data;
}

void free_csv(csv_data *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_cols; j++) {
            free(data->data[i][j]);
        }
        free(data->data[i]);
    }
    free(data->data);
    free(data);
}

int main() {
    csv_data *data = read_csv("data.csv");
    if (data == NULL) {
        return EXIT_FAILURE;
    }

    // Print the data
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_cols; j++) {
            printf("%s ", data->data[i][j]);
        }
        printf("\n");
    }

    free_csv(data);

    return EXIT_SUCCESS;
}