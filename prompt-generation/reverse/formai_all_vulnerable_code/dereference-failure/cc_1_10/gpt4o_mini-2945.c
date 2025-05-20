//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_BUFFER 1024
#define NUM_THREADS 2

// Function prototypes
void* translate_to_cat(void* arg);
void read_file(const char* filename);
void print_usage(const char* program_name);

// Structure to hold thread data
typedef struct {
    char** lines;
    int start;
    int end;
} ThreadData;

// Translation function
char* translate_sentence(const char* sentence) {
    char* translated = (char*)malloc(strlen(sentence) * 2); // Allocate memory
    if (!translated) {
        perror("Failed to allocate memory for translation");
        exit(EXIT_FAILURE);
    }

    int j = 0;
    for (int i = 0; sentence[i]; i++) {
        if (strchr("aeiouAEIOU", sentence[i])) {
            // Replace vowels with cat sounds
            translated[j++] = 'm';
            translated[j++] = 'e';
            translated[j++] = 'o';
            translated[j++] = 'w';
        } else {
            translated[j++] = sentence[i];
        }
    }
    translated[j] = '\0'; // Null-terminate the translated string
    return translated;
}

// Multi-threaded translation function
void* translate_to_cat(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    
    for (int i = data->start; i < data->end; i++) {
        char* translated_sentence = translate_sentence(data->lines[i]);
        printf("Translated: %s\n", translated_sentence);
        free(translated_sentence);
    }
    
    pthread_exit(NULL);
}

// Function to read sentences from a file
void read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char** lines = malloc(MAX_BUFFER * sizeof(char*));
    if (!lines) {
        perror("Failed to allocate memory for lines");
        exit(EXIT_FAILURE);
    }
    
    int line_count = 0;
    while (line_count < MAX_BUFFER && fgets(lines[line_count], MAX_BUFFER, file) != NULL) {
        lines[line_count][strcspn(lines[line_count], "\n")] = 0; // Remove newline character
        line_count++;
    }
    
    fclose(file);

    // Create threads for translation
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];

    // Calculate the number of lines for each thread
    int lines_per_thread = line_count / NUM_THREADS;

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].lines = lines;
        thread_data[i].start = i * lines_per_thread;
        thread_data[i].end = (i == NUM_THREADS - 1) ? line_count : (i + 1) * lines_per_thread;

        // Create thread for translation
        pthread_create(&threads[i], NULL, translate_to_cat, (void*)&thread_data[i]);
    }

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free allocated memory for lines
    for (int i = 0; i < line_count; i++) {
        free(lines[i]);
    }
    free(lines);
}

// Usage instructions
void print_usage(const char* program_name) {
    fprintf(stderr, "Usage: %s <filename>\n", program_name);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    read_file(argv[1]); // Read and translate the file
    return EXIT_SUCCESS;
}