//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_COLS 1000
#define MAX_ROWS 10000
#define MAX_LINE_LENGTH 1000

// Structure that holds the CSV file data
typedef struct csv_data {
    char* cols[MAX_COLS];
    int num_cols;
} CsvData;

// Structure that holds the CSV file data and the current row to be read
typedef struct csv_reader {
    FILE* file;
    CsvData* data;
    int current_row;
    pthread_mutex_t lock;
} CsvReader;

// Function that reads a single CSV row and stores it in the provided CsvData struct
void read_csv_row(char* line, CsvData* data) {
    char* token = strtok(line, ",");
    int i = 0;

    while (token != NULL) {
        data->cols[i++] = token;
        token = strtok(NULL, ",");
    }

    data->num_cols = i;
}

// Thread function that reads CSV rows from the provided CsvReader struct and stores them in the data array
void* read_csv_rows(void* arg) {
    CsvReader* reader = (CsvReader*) arg;

    while (1) {
        pthread_mutex_lock(&reader->lock);

        if (reader->current_row >= MAX_ROWS) {
            pthread_mutex_unlock(&reader->lock);
            break;
        }

        char line[MAX_LINE_LENGTH];
        fgets(line, MAX_LINE_LENGTH, reader->file);

        if (line == NULL) {
            pthread_mutex_unlock(&reader->lock);
            break;
        }

        read_csv_row(line, &reader->data[reader->current_row++]);

        pthread_mutex_unlock(&reader->lock);
    }

    pthread_exit(NULL);
}

// Function that builds a CsvData array by reading a CSV file in a multi-threaded style
CsvData* build_csv_data(char* filename) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        return NULL;
    }

    CsvData* data = malloc(sizeof(CsvData) * MAX_ROWS);
    CsvReader reader = { file, data, 0, PTHREAD_MUTEX_INITIALIZER };
    pthread_t threads[4];

    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, read_csv_rows, (void*) &reader);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(file);

    return data;
}

// Main function that demonstrates how to use the CSV reader program
int main() {
    CsvData* data = build_csv_data("example.csv");

    if (data == NULL) {
        printf("Failed to read CSV file\n");
        return 1;
    }

    for (int i = 0; i < MAX_ROWS && data[i].num_cols > 0; i++) {
        for (int j = 0; j < data[i].num_cols; j++) {
            printf("%s ", data[i].cols[j]);
        }

        printf("\n");
    }

    free(data);

    return 0;
}