//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int read_csv_file(FILE *file, char *filename);
void print_csv_data(char *filename, char **data);

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <delimiter>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char delimiter = argv[2][0];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    char **data = NULL;
    int num_rows = 0;
    int num_cols = 0;

    if (read_csv_file(file, filename)!= 0) {
        fclose(file);
        return 1;
    }

    print_csv_data(filename, data);

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            free(data[i]);
        }
        free(data[i]);
    }
    free(data);

    fclose(file);
    return 0;
}

int read_csv_file(FILE *file, char *filename) {
    char line[1024];
    char **data = NULL;
    int num_rows = 0;
    int num_cols = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        num_rows++;
        char *token = strtok(line, ",");
        while (token!= NULL) {
            num_cols++;
            char *new_token = strdup(token);
            data = realloc(data, sizeof(char *) * num_cols);
            data[num_cols - 1] = new_token;
            token = strtok(NULL, ",");
        }
    }

    return 0;
}

void print_csv_data(char *filename, char **data) {
    printf("Filename: %s\n", filename);
    printf("Number of rows: %d\n", sizeof(data) / sizeof(data[0]));
    printf("Number of columns: %d\n", sizeof(data[0]) / sizeof(data[0][0]));
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        for (int j = 0; j < sizeof(data[0]) / sizeof(data[0][0]); j++) {
            printf("%s ", data[i][j]);
        }
        printf("\n");
    }
}