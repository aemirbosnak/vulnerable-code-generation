//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000

typedef struct {
    char **data;
    int row;
    int col;
} CSV;

CSV *create_csv(FILE *fp) {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = (char **)malloc(sizeof(char *) * MAX_ROW);
    csv->row = 0;
    csv->col = 0;

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        int i = 0;
        while (token!= NULL) {
            csv->data[csv->row] = (char *)realloc(csv->data[csv->row], csv->col + strlen(token) + 1);
            strcat(csv->data[csv->row], token);
            csv->col += strlen(token) + 1;
            token = strtok(NULL, ",");
            i++;
        }
        csv->row++;
    }

    return csv;
}

void print_csv(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        for (int j = 0; j < csv->col; j++) {
            printf("%s ", csv->data[i]);
        }
        printf("\n");
    }
}

void free_csv(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Cannot open output file.\n");
        fclose(input_file);
        return 1;
    }

    CSV *csv = create_csv(input_file);
    print_csv(csv);

    fclose(input_file);
    fclose(output_file);

    free_csv(csv);

    return 0;
}