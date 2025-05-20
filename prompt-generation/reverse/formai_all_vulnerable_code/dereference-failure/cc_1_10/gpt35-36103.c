//FormAI DATASET v1.0 Category: Text processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_LINES 100 // Maximum number of lines in text file
#define MAX_LINE_LEN 100 // Maximum length of each line in text file

typedef struct {
    int start; // Starting line number to process
    int end; // Ending line number to process
    char** lines; // Array of lines in text file
} thread_data;

void* process_lines(void* arg) {
    thread_data* data = (thread_data*) arg;

    for (int i = data->start; i <= data->end; i++) {
        // Process each line
        char* line = data->lines[i];
        printf("Processing line %d: %s\n", i, line);
    }

    pthread_exit(NULL);
}

int main() {
    char** lines = malloc(MAX_LINES * sizeof(char*)); // Array of lines in text file
    int num_lines = 0; // Number of lines in text file

    // Read text file
    FILE* file = fopen("example.txt", "r");
    if (file) {
        char line[MAX_LINE_LEN];
        while (fgets(line, MAX_LINE_LEN, file) != NULL && num_lines < MAX_LINES) {
            lines[num_lines] = malloc((strlen(line) + 1) * sizeof(char));
            strcpy(lines[num_lines], line);
            num_lines++;
        }
        fclose(file);
    }
    else {
        printf("Could not open file!\n");
        exit(1);
    }

    // Initialize threads
    pthread_t thread1, thread2;
    thread_data data1 = {0, num_lines / 2 - 1, lines};
    thread_data data2 = {num_lines / 2, num_lines - 1, lines};

    // Start threads
    pthread_create(&thread1, NULL, process_lines, (void*) &data1);
    pthread_create(&thread2, NULL, process_lines, (void*) &data2);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Free memory
    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}