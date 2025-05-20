//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int num_rows;
    int num_cols;
    char **data;
} csv_t;

csv_t *csv_read(const char *filename) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    csv_t *csv;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    csv = malloc(sizeof(csv_t));
    if (csv == NULL) {
        perror("Error allocating memory for csv");
        fclose(fp);
        return NULL;
    }

    csv->num_rows = 0;
    csv->num_cols = 0;
    csv->data = NULL;

    while ((read = getline(&line, &len, fp)) != -1) {
        char *token;
        int num_cols = 0;

        token = strtok(line, ",");
        while (token != NULL) {
            num_cols++;
            token = strtok(NULL, ",");
        }

        if (csv->num_rows == 0) {
            csv->num_cols = num_cols;
            csv->data = malloc(sizeof(char *) * csv->num_rows);
            if (csv->data == NULL) {
                perror("Error allocating memory for csv data");
                fclose(fp);
                free(csv);
                return NULL;
            }
        }

        csv->data = realloc(csv->data, sizeof(char *) * (csv->num_rows + 1));
        if (csv->data == NULL) {
            perror("Error reallocating memory for csv data");
            fclose(fp);
            free(line);
            free(csv);
            return NULL;
        }

        csv->data[csv->num_rows] = malloc(sizeof(char) * (strlen(line) + 1));
        if (csv->data[csv->num_rows] == NULL) {
            perror("Error allocating memory for csv data");
            fclose(fp);
            free(line);
            free(csv);
            return NULL;
        }

        strcpy(csv->data[csv->num_rows], line);
        csv->num_rows++;
    }

    free(line);
    fclose(fp);
    return csv;
}

void csv_free(csv_t *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    csv_t *csv;

    csv = csv_read("data.csv");
    if (csv == NULL) {
        return 1;
    }

    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }

    csv_free(csv);
    return 0;
}