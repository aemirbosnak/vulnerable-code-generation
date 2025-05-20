//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LINE_LENGTH 1024
#define MAX_THREADS 10

typedef struct {
    char *line;
    int line_number;
} ThreadData;

void *process_line(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    printf("Thread for line %d: %s", data->line_number, data->line);
    // Here you could add more processing like parsing the CSV fields
    free(data->line);
    free(data);
    return NULL;
}

void create_thread_for_line(const char *line, int line_number) {
    pthread_t thread;
    ThreadData *data = malloc(sizeof(ThreadData));
    data->line = strdup(line);
    data->line_number = line_number;

    if (pthread_create(&thread, NULL, process_line, data) != 0) {
        perror("Failed to create thread");
        free(data->line);
        free(data);
        exit(EXIT_FAILURE);
    }

    // Detach the thread so we do not need to join it later
    pthread_detach(thread);
}

void read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 0;

    while (fgets(line, sizeof(line), file)) {
        create_thread_for_line(line, line_number);
        line_number++;
    }

    fclose(file);
    // Give some time for threads to complete.
    // Note: In a real-world scenario, you might use mutex/condition variable or join.
    sleep(2); // Adjust this depending on your processing time
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    read_csv(argv[1]);
    return 0;
}