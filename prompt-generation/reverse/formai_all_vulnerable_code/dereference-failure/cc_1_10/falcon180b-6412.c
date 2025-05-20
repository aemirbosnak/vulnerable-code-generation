//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: shocked
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

CSV* create_csv(FILE *fp) {
    CSV *csv = (CSV*)malloc(sizeof(CSV));
    csv->data = (char**)malloc(MAX_ROW * sizeof(char*));
    csv->row = 0;
    csv->col = 0;

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        int i = 0;
        while (token!= NULL) {
            csv->data[csv->row] = (char*)realloc(csv->data[csv->row], csv->col + strlen(token) + 1);
            strcat(csv->data[csv->row], token);
            csv->col++;
            token = strtok(NULL, ",");
            i++;
        }
        csv->row++;
    }

    return csv;
}

void destroy_csv(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void print_csv(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        printf("%s\n", csv->data[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *fp_in = fopen(argv[1], "r");
    if (fp_in == NULL) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    CSV *csv = create_csv(fp_in);
    fclose(fp_in);

    FILE *fp_out = fopen(argv[2], "w");
    if (fp_out == NULL) {
        printf("Error: Cannot open output file.\n");
        destroy_csv(csv);
        return 1;
    }

    for (int i = 0; i < csv->row; i++) {
        fprintf(fp_out, "%s", csv->data[i]);
    }

    fclose(fp_out);
    destroy_csv(csv);

    return 0;
}