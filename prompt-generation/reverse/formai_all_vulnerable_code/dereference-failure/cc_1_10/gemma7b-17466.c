//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_COLS 20

typedef struct CSV_DATA {
    char ***data;
    int num_lines;
    int num_cols;
} CSV_DATA;

CSV_DATA* csv_reader(char* filename) {
    CSV_DATA* csv_data = malloc(sizeof(CSV_DATA));
    csv_data->num_lines = 0;
    csv_data->num_cols = 0;
    csv_data->data = NULL;

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    char line[MAX_LINES];
    char** cols = NULL;
    while (fgets(line, MAX_LINES, file) != NULL) {
        int num_cols = 0;
        char* ptr = line;
        while (ptr && *ptr) {
            cols = realloc(cols, (num_cols + 1) * sizeof(char*));
            cols[num_cols++] = strdup(ptr);
            ptr += strcspn(ptr, ",") + 1;
        }
        csv_data->num_lines++;
        csv_data->data = realloc(csv_data->data, csv_data->num_lines * sizeof(char***));
        csv_data->data[csv_data->num_lines - 1] = cols;
        csv_data->num_cols = num_cols;
    }

    fclose(file);
    return csv_data;
}

int main() {
    char* filename = "data.csv";
    CSV_DATA* csv_data = csv_reader(filename);

    if (csv_data) {
        printf("Number of lines: %d\n", csv_data->num_lines);
        printf("Number of columns: %d\n", csv_data->num_cols);
        for (int i = 0; i < csv_data->num_lines; i++) {
            for (int j = 0; j < csv_data->num_cols; j++) {
                printf("%s ", csv_data->data[i][j]);
            }
            printf("\n");
        }
        free(csv_data);
    } else {
        printf("Error reading CSV file.\n");
    }

    return 0;
}