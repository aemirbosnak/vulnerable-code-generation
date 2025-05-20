//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    size_t nrows;
    size_t ncols;
} csv_t;

csv_t *csv_read(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Read the first line to get the number of columns
    char line[1024];
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return NULL;
    }

    size_t ncols = 0;
    char *token = strtok(line, ",");
    while (token != NULL) {
        ncols++;
        token = strtok(NULL, ",");
    }

    // Allocate memory for the CSV data
    csv_t *csv = malloc(sizeof(csv_t));
    if (csv == NULL) {
        fclose(file);
        return NULL;
    }

    csv->data = malloc(sizeof(char *) * ncols);
    if (csv->data == NULL) {
        free(csv);
        fclose(file);
        return NULL;
    }

    for (size_t i = 0; i < ncols; i++) {
        csv->data[i] = malloc(sizeof(char) * 1024);
        if (csv->data[i] == NULL) {
            for (size_t j = 0; j < i; j++) {
                free(csv->data[j]);
            }
            free(csv->data);
            free(csv);
            fclose(file);
            return NULL;
        }
    }

    // Read the rest of the file and fill in the data
    csv->nrows = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        token = strtok(line, ",");
        for (size_t i = 0; i < ncols; i++) {
            strcpy(csv->data[i][csv->nrows], token);
            token = strtok(NULL, ",");
        }
        csv->nrows++;
    }

    fclose(file);
    return csv;
}

void csv_free(csv_t *csv) {
    for (size_t i = 0; i < csv->ncols; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    csv_t *csv = csv_read("data.csv");
    if (csv == NULL) {
        printf("Error reading CSV file\n");
        return 1;
    }

    // Print the CSV data
    for (size_t i = 0; i < csv->nrows; i++) {
        for (size_t j = 0; j < csv->ncols; j++) {
            printf("%s,", csv->data[i][j]);
        }
        printf("\n");
    }

    csv_free(csv);
    return 0;
}