//FormAI DATASET v1.0 Category: Log analysis ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_LINES 1000
#define MAX_THREADS 10

struct thread_data { // Thread data structure
    int start_index;
    int end_index;
    char* log_lines[MAX_LINES];
};

void* thread_function(void* arg) {
    struct thread_data* data = (struct thread_data*) arg;

    // Parse log lines and do some calculations
    int count = 0;
    for (int i = data->start_index; i < data->end_index; i++) {
        if (strstr(data->log_lines[i], "error")) {
            count++;
        }
    }

    printf("Thread %ld found %d errors in log lines %d-%d\n", pthread_self(), count, data->start_index + 1, data->end_index);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    // Read log file
    if (argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE* log_file = fopen(argv[1], "r");
    if (!log_file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char* log_lines[MAX_LINES];
    char* line = NULL;
    size_t len = 0;

    int line_count = 0;
    while ((getline(&line, &len, log_file)) != -1) {
        log_lines[line_count] = line;
        line_count++;
    }

    fclose(log_file);

    // Divide lines among threads
    int num_threads = line_count < MAX_THREADS ? line_count : MAX_THREADS;
    struct thread_data thread_args[num_threads];
    pthread_t threads[num_threads];

    int start_index = 0;
    int end_index = line_count / num_threads;
    for (int i = 0; i < num_threads; i++) {
        thread_args[i].start_index = start_index;
        thread_args[i].end_index = end_index;
        for (int j = start_index; j < end_index; j++) {
            thread_args[i].log_lines[j] = log_lines[j];
        }

        // Create thread and pass in thread data structure as argument
        if (pthread_create(&threads[i], NULL, thread_function, (void*) &thread_args[i])) {
            fprintf(stderr, "Error creating thread\n");
            exit(EXIT_FAILURE);
        }

        start_index = end_index;
        end_index = (i == num_threads - 2) ? line_count : end_index + (line_count / num_threads);
    }

    // Wait for threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free allocated memory
    for (int i = 0; i < line_count; i++) {
        free(log_lines[i]);
    }

    return 0;
}