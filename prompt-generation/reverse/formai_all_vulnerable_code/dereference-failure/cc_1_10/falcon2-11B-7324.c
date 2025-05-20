//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int row;
    char values[10][20];
    int is_header;
} CSV;

CSV* parseCSV(const char* filename) {
    CSV* csv = (CSV*)malloc(sizeof(CSV));
    csv->is_header = 1;
    csv->row = 0;
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char* value = strtok(line, ",");
        while (value!= NULL) {
            csv->values[csv->row][csv->is_header] = value;
            csv->is_header++;
            csv->row++;
            value = strtok(NULL, ",");
        }
    }
    fclose(file);
    return csv;
}

void displayCSV(CSV* csv) {
    printf("Row %d: ", csv->row);
    for (int i = 0; i < csv->is_header; i++) {
        printf("%s ", csv->values[csv->row][i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    CSV* csv = parseCSV(argv[1]);
    if (csv == NULL) {
        return 1;
    }
    displayCSV(csv);
    free(csv);
    return 0;
}