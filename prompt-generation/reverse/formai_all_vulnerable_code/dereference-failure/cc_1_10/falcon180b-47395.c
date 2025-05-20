//Falcon-180B DATASET v1.0 Category: Database querying ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1024

typedef struct {
    char *data;
    int rows;
    int cols;
} Data;

Data read_data(FILE *fp) {
    Data data = {0};
    char line[MAX_DATA_SIZE];
    int rows = 0, cols = 0;

    fgets(line, MAX_DATA_SIZE, fp);
    while (line[0]!= '\0') {
        rows++;
        int len = strlen(line);
        if (cols == 0) {
            cols = len;
        } else if (len!= cols) {
            printf("Error: Invalid data format.\n");
            exit(1);
        }
        data.data = realloc(data.data, sizeof(char) * (rows * cols + 1));
        strcat(data.data, line);
        fgets(line, MAX_DATA_SIZE, fp);
    }

    data.rows = rows;
    data.cols = cols;
    return data;
}

void print_data(Data data) {
    for (int i = 0; i < data.rows; i++) {
        printf("%s", data.data + i * data.cols);
    }
}

int main() {
    FILE *fp;
    char filename[MAX_DATA_SIZE];
    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    Data data = read_data(fp);
    fclose(fp);

    printf("Enter the column name to search: ");
    char column[MAX_DATA_SIZE];
    scanf("%s", column);

    char *result = strstr(data.data, column);
    if (result == NULL) {
        printf("No data found.\n");
    } else {
        printf("Data found:\n");
        print_data(data);
    }

    free(data.data);
    return 0;
}