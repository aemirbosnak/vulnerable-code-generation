//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSV;

CSV *read_csv(const char *filename) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    CSV *csv = malloc(sizeof(CSV));
    if (!csv) {
        perror("malloc");
        return NULL;
    }

    fp = fopen(filename, "r");
    if (!fp) {
        perror("fopen");
        free(csv);
        return NULL;
    }

    // Get the number of rows
    csv->num_rows = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        csv->num_rows++;
    }

    // Get the number of columns
    rewind(fp);
    read = getline(&line, &len, fp);
    csv->num_cols = 0;
    for (char *p = line; *p; p++) {
        if (*p == ',') {
            csv->num_cols++;
        }
    }
    csv->num_cols++;

    // Allocate memory for the data
    csv->data = malloc(sizeof(char *) * csv->num_rows);
    if (!csv->data) {
        perror("malloc");
        free(csv);
        free(line);
        fclose(fp);
        return NULL;
    }

    // Read the data
    rewind(fp);
    for (int i = 0; i < csv->num_rows; i++) {
        read = getline(&line, &len, fp);
        csv->data[i] = malloc(sizeof(char) * (read + 1));
        if (!csv->data[i]) {
            perror("malloc");
            for (int j = 0; j < i; j++) {
                free(csv->data[j]);
            }
            free(csv->data);
            free(csv);
            free(line);
            fclose(fp);
            return NULL;
        }
        strcpy(csv->data[i], line);
    }

    free(line);
    fclose(fp);

    return csv;
}

void print_csv(const CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s", csv->data[i][j]);
            if (j < csv->num_cols - 1) {
                printf(",");
            }
        }
        printf("\n");
    }
}

int main() {
    CSV *csv = read_csv("data.csv");
    if (!csv) {
        return 1;
    }

    print_csv(csv);

    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);

    return 0;
}