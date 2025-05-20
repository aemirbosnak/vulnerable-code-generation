//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100
#define MAX_THREADS 10

typedef struct {
    char *line;
    int line_number;
} ThreadData;

pthread_mutex_t print_mutex = PTHREAD_MUTEX_INITIALIZER;
int total_rows = 0;
int total_columns = 0;

void *process_record(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    char *line = data->line;
    int column_count = 0;

    char *token = strtok(line, ",");
    while (token != NULL) {
        column_count++;
        token = strtok(NULL, ",");
    }

    pthread_mutex_lock(&print_mutex);
    total_rows++;
    if (column_count > total_columns) {
        total_columns = column_count;
    }
    printf("Processed Line %d: %s (Columns: %d)\n", data->line_number, data->line, column_count);
    pthread_mutex_unlock(&print_mutex);
    
    free(data->line);
    free(data);
    return NULL;
}

void read_csv(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < MAX_THREADS; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset for the next batch of threads
        }

        line[strcspn(line, "\n")] = 0; // Remove the newline character
        ThreadData *data = malloc(sizeof(ThreadData));
        data->line = strdup(line); // Duplicate the line for thread processing
        data->line_number = total_rows + 1; // Assign line number based on global count

        pthread_create(&threads[thread_count++], NULL, process_record, data);
    }

    // Wait for remaining threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_csv(argv[1]);
    printf("Total Rows: %d\n", total_rows);
    printf("Maximum Columns in a Row: %d\n", total_columns);
    
    return EXIT_SUCCESS;
}