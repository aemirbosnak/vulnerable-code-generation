//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 10
#define NUM_THREADS 4
#define MAX_LINE_LENGTH 1024

const char *dictionary[DICTIONARY_SIZE] = {
    "hello",
    "world",
    "this",
    "is",
    "a",
    "spell",
    "checker",
    "program",
    "in",
    "c"
};

// Structure to hold thread arguments
typedef struct {
    char **lines; // Pointer to array of lines
    int start; // Starting index for this thread
    int end; // Ending index for this thread
} ThreadData;

// Function to check if a word exists in the dictionary
int is_spelled_correctly(const char *word) {
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return 1; // Word found in dictionary
        }
    }
    return 0; // Word not found
}

// Function to process a line for spelling checks
void *spell_check(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    char **lines = data->lines;

    for (int i = data->start; i < data->end; i++) {
        char *line = lines[i];
        char *token = strtok(line, " \n");
        while (token) {
            // Remove punctuation
            char clean_word[MAX_WORD_LENGTH];
            int j = 0;
            for (int k = 0; token[k] != '\0'; k++) {
                if (isalpha(token[k]) || token[k] == '\'') {
                    clean_word[j++] = tolower(token[k]);
                }
            }
            clean_word[j] = '\0'; // Null terminate the cleaned word

            // Check spelling
            if (!is_spelled_correctly(clean_word) && strlen(clean_word) > 0) {
                printf("Misspelled word: %s\n", clean_word);
            }
            
            token = strtok(NULL, " \n");
        }
    }
    return NULL;
}

// Split lines into chunks for threading
void split_lines_into_chunks(char *lines[], int num_lines, ThreadData thread_data[], int num_threads) {
    int chunk_size = num_lines / num_threads;
    for (int i = 0; i < num_threads; i++) {
        thread_data[i].lines = lines;
        thread_data[i].start = i * chunk_size;
        thread_data[i].end = (i == num_threads - 1) ? num_lines : (i + 1) * chunk_size;
    }
}

// Main function to drive the spell checker
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char **lines = malloc(MAX_LINE_LENGTH * sizeof(char *));
    int line_count = 0;

    // Read lines from the file
    while (!feof(file) && line_count < MAX_LINE_LENGTH) {
        lines[line_count] = malloc(MAX_LINE_LENGTH);
        if (fgets(lines[line_count], MAX_LINE_LENGTH, file)) {
            line_count++;
        }
    }

    fclose(file);

    // Create threads
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];

    split_lines_into_chunks(lines, line_count, thread_data, NUM_THREADS);

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, spell_check, (void *)&thread_data[i]) != 0) {
            perror("Error creating thread");
            return EXIT_FAILURE;
        }
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free allocated memory
    for (int i = 0; i < line_count; i++) {
        free(lines[i]);
    }
    free(lines);

    return EXIT_SUCCESS;
}