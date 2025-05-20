//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1024
#define MAX_DICTIONARY_SIZE 10000
#define NUM_THREADS 4

// Structure to hold the line information
typedef struct {
    char *line;
    char **dictionary;
    int dict_size;
    int line_number;
} ThreadData;

// Function prototypes
void *check_spelling(void *arg);
void load_dictionary(const char *filename, char **dictionary, int *size);
int is_word_in_dictionary(const char *word, char **dictionary, int size);
void to_lowercase(char *str);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <text_file> <dictionary_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *text_file = argv[1];
    const char *dictionary_file = argv[2];
    FILE *file = fopen(text_file, "r");

    if (!file) {
        perror("Error opening text file");
        return EXIT_FAILURE;
    }

    char *dictionary[MAX_DICTIONARY_SIZE];
    int dict_size = 0;
    load_dictionary(dictionary_file, dictionary, &dict_size);

    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];

    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    
    while (fgets(line, sizeof(line), file)) {
        thread_data[line_number % NUM_THREADS].line = strdup(line);
        thread_data[line_number % NUM_THREADS].dictionary = dictionary;
        thread_data[line_number % NUM_THREADS].dict_size = dict_size;
        thread_data[line_number % NUM_THREADS].line_number = line_number;

        pthread_create(&threads[line_number % NUM_THREADS], NULL, check_spelling, (void *)&thread_data[line_number % NUM_THREADS]);
        
        // Join the previous thread if we've reached the thread limit
        if (line_number >= NUM_THREADS - 1) {
            pthread_join(threads[(line_number - NUM_THREADS + 1) % NUM_THREADS], NULL);
        }

        line_number++;
    }

    // Join any remaining threads
    for (int i = 0; i < NUM_THREADS && i < line_number; i++) {
        pthread_join(threads[i % NUM_THREADS], NULL);
    }

    fclose(file);
    
    // Free dynamically allocated memory
    for (int i = 0; i < dict_size; i++) {
        free(dictionary[i]);
    }
    
    return EXIT_SUCCESS;
}

void *check_spelling(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    char *line = data->line;
    char *token = strtok(line, " \n");
    printf("Checking line %d: ", data->line_number + 1);

    while (token) {
        char word[MAX_WORD_LENGTH];
        strncpy(word, token, MAX_WORD_LENGTH - 1);
        word[MAX_WORD_LENGTH - 1] = '\0';
        to_lowercase(word);

        if (!is_word_in_dictionary(word, data->dictionary, data->dict_size)) {
            printf("[Misspelled: '%s'] ", word);
        }
        token = strtok(NULL, " \n");
    }

    printf("\n");
    free(line);
    return NULL;
}

void load_dictionary(const char *filename, char **dictionary, int *size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening dictionary file");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    while (fgets(word, sizeof(word), file) && *size < MAX_DICTIONARY_SIZE) {
        word[strcspn(word, "\n")] = '\0'; // Remove newline
        dictionary[(*size)++] = strdup(word);
    }

    fclose(file);
}

int is_word_in_dictionary(const char *word, char **dictionary, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}