//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: systematic
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
    if (!fp) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    char line[1024];
    int num_rows = 0;
    int num_cols = 0;
    csv_data *csv = malloc(sizeof(csv_data));
    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_cols = 0;

    while (fgets(line, sizeof(line), fp)) {
        num_rows++;
        char *ptr = line;
        while (*ptr != '\0') {
            if (*ptr == ',') {
                num_cols++;
            }
            ptr++;
        }
    }

    csv->data = malloc(sizeof(char *) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        csv->data[i] = malloc(sizeof(char) * (num_cols + 1));
    }

    fseek(fp, 0, SEEK_SET);
    int row = 0;
    int col = 0;
    while (fgets(line, sizeof(line), fp)) {
        char *ptr = line;
        while (*ptr != '\0') {
            if (*ptr == ',') {
                csv->data[row][col] = '\0';
                col++;
            } else {
                csv->data[row][col] = *ptr;
            }
            ptr++;
        }
        csv->data[row][col] = '\0';
        row++;
        col = 0;
    }

    fclose(fp);

    csv->num_rows = num_rows;
    csv->num_cols = num_cols;

    return csv;
}

void print_csv(csv_data *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    csv_data *csv = read_csv(argv[1]);
    if (!csv) {
        return EXIT_FAILURE;
    }

    print_csv(csv);

    return EXIT_SUCCESS;
}