//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int rows;
    int columns;
} csv_data;

csv_data *read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    csv_data *data = (csv_data *)malloc(sizeof(csv_data));
    data->rows = 0;
    data->columns = 0;
    data->data = NULL;

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, ",");
        int i = 0;
        while (token!= NULL) {
            i++;
            if (i > data->columns) {
                data->columns = i;
            }
            if (data->data == NULL) {
                data->data = (char **)malloc(sizeof(char *) * data->columns);
            } else {
                data->data = (char **)realloc(data->data, sizeof(char *) * data->columns);
            }
            data->data[i-1] = (char *)malloc(strlen(token) + 1);
            strcpy(data->data[i-1], token);
            token = strtok(NULL, ",");
        }
        data->rows++;
    }

    fclose(file);
    return data;
}

void print_csv(csv_data *data) {
    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->columns; j++) {
            printf("%s ", data->data[i*data->columns + j]);
        }
        printf("\n");
    }
}

void free_csv(csv_data *data) {
    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->columns; j++) {
            free(data->data[i*data->columns + j]);
        }
    }
    free(data->data);
    free(data);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    csv_data *data = read_csv(argv[1]);
    print_csv(data);
    free_csv(data);

    return 0;
}