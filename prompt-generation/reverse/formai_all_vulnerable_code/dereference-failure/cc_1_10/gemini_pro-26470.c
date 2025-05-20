//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

// Structure to hold word and its frequency
typedef struct WordFreq {
    char *word;
    int freq;
} WordFreq;

// Global variables
int num_words = 0;
WordFreq *word_freq_list = NULL;

// Mutex to protect global variables
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to compare WordFreq structures
int compare_word_freq(const void *a, const void *b) {
    WordFreq *word_freq_a = (WordFreq *)a;
    WordFreq *word_freq_b = (WordFreq *)b;

    return strcmp(word_freq_a->word, word_freq_b->word);
}

// Function to add a word to the list
void add_word(char *word) {
    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Check if the word already exists in the list
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word_freq_list[i].word, word) == 0) {
            // Word already exists, so just increment its frequency
            word_freq_list[i].freq++;
            break;
        }
    }

    // If the word does not exist in the list, add it
    if (i == num_words) {
        num_words++;
        word_freq_list = realloc(word_freq_list, num_words * sizeof(WordFreq));
        word_freq_list[num_words - 1].word = strdup(word);
        word_freq_list[num_words - 1].freq = 1;
    }

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);
}

// Function to count the frequency of words in a text file
void *count_words(void *arg) {
    // Get the file name from the argument
    char *file_name = (char *)arg;

    // Open the file
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the file line by line
    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Tokenize the line into words
        char *word = strtok(line, " ");
        while (word != NULL) {
            // Convert the word to lowercase
            for (int i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }

            // Add the word to the list
            add_word(word);

            // Get the next word
            word = strtok(NULL, " ");
        }
    }

    // Close the file
    fclose(fp);

    return NULL;
}

// Function to print the word frequency list
void print_word_freq_list() {
    // Sort the list by word
    qsort(word_freq_list, num_words, sizeof(WordFreq), compare_word_freq);

    // Print the list
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_freq_list[i].word, word_freq_list[i].freq);
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return 1;
    }

    // Create a thread pool
    pthread_t *threads = malloc((argc - 1) * sizeof(pthread_t));

    // Create a thread for each file
    for (int i = 1; i < argc; i++) {
        pthread_create(&threads[i - 1], NULL, count_words, (void *)argv[i]);
    }

    // Wait for all threads to finish
    for (int i = 1; i < argc; i++) {
        pthread_join(threads[i - 1], NULL);
    }

    // Print the word frequency list
    print_word_freq_list();

    // Free the allocated memory
    for (int i = 0; i < num_words; i++) {
        free(word_freq_list[i].word);
    }
    free(word_freq_list);
    free(threads);

    return 0;
}