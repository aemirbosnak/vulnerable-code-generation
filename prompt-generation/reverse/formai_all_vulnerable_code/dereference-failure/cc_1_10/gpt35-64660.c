//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LINE_LEN 1024 // Maximum length of a single line in CSV file
#define MAX_COLS 256 // Maximum number of columns in CSV file
#define MAX_ROWS 1024 // Maximum number of rows in CSV file

struct csv_reader_args {
    char *filename;
    pthread_mutex_t *mutex;
    int *rows;
    int *cols;
    char ***data;
};

void *csv_reader(void *args) {
    struct csv_reader_args *csv_args = (struct csv_reader_args *) args;
    char *filename = csv_args->filename;
    FILE *file = fopen(filename, "r");
    char line[MAX_LINE_LEN];
    int row = 0, col = 0;
    while (fgets(line, MAX_LINE_LEN, file) != NULL) {
        pthread_mutex_lock(csv_args->mutex);
        char *token = strtok(line, ",");
        while (token != NULL) {
            csv_args->data[row][col++] = strdup(token);
            token = strtok(NULL, ",");
        }
        csv_args->cols[row] = col;
        col = 0;
        row++;
        pthread_mutex_unlock(csv_args->mutex);
    }
    *(csv_args->rows) = row;
    fclose(file);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename.csv\n", argv[0]);
        return 1;
    }
    char *filename = argv[1];
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    int rows = 0, cols[MAX_ROWS] = {0};
    char **data[MAX_ROWS];
    for (int i = 0; i < MAX_ROWS; i++) {
        data[i] = (char **) malloc(MAX_COLS * sizeof(char *));
        for (int j = 0; j < MAX_COLS; j++) {
            data[i][j] = NULL;
        }
    }
    struct csv_reader_args csv_args = {filename, &mutex, &rows, cols, (char ***) data};
    pthread_t thread;
    pthread_create(&thread, NULL, csv_reader, &csv_args);
    pthread_join(thread, NULL);
    printf("CSV file %s has %d rows:\n", filename, rows);
    for (int i = 0; i < rows; i++) {
        printf("Row %d has %d columns:", i, cols[i]);
        for (int j = 0; j < cols[i]; j++) {
            printf(" %s", data[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            free(data[i][j]);
        }
        free(data[i]);
    }
    return 0;
}