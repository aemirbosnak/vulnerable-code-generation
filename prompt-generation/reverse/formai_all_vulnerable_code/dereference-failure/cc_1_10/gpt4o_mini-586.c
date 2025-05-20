//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

#define MAX_THREADS 5
#define BUFFER_SIZE 1024

// Structure to hold thread data
typedef struct {
    char *line;
    int line_num;
} thread_data_t;

// Function to check if a line is a valid C syntax statement
int is_valid_c_syntax(char *line) {
    // Basic validity checks (not comprehensive)
    if (line == NULL || strlen(line) == 0) return 0;
    
    // Check for a semicolon at the end
    if (line[strlen(line) - 1] != ';') return 0;
    
    // Very simple check for function declarations (for demonstration)
    if (strstr(line, "void") != NULL || strstr(line, "int") != NULL || strstr(line, "float") != NULL) {
        return 1;
    }

    return 0;
}

// Thread function for parsing a single line
void* parse_line(void* arg) {
    thread_data_t *data = (thread_data_t *)arg;

    printf("Thread %ld: Parsing line %d: %s", pthread_self(), data->line_num, data->line);
    if (is_valid_c_syntax(data->line)) {
        printf(" - Valid C syntax\n");
    } else {
        printf(" - Invalid C syntax\n");
    }

    free(data->line); // Free the allocated line buffer
    free(data);       // Free the thread data structure
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;
    char buffer[BUFFER_SIZE];

    printf("Enter C code lines. Use 'exit' to finish input:\n");

    while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        // Remove newline character from fgets
        buffer[strcspn(buffer, "\n")] = 0;

        // Exit command
        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        // Check for maximum thread count
        if (thread_count >= MAX_THREADS) {
            printf("Maximum thread limit reached. Please wait for threads to finish.\n");
            for (int i = 0; i < MAX_THREADS; i++) {
                pthread_join(threads[i], NULL);
                thread_count--;
            }
        }

        // Allocate memory for the line and copy it
        thread_data_t *data = malloc(sizeof(thread_data_t));
        data->line = strdup(buffer);
        data->line_num = thread_count + 1;

        // Create a new thread for parsing this line
        if (pthread_create(&threads[thread_count], NULL, parse_line, (void*)data) != 0) {
            fprintf(stderr, "Error creating thread\n");
            free(data->line);
            free(data);
            continue;
        }
        
        thread_count++;
    }

    // Join any remaining threads before exiting
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Finished parsing lines.\n");
    return 0;
}