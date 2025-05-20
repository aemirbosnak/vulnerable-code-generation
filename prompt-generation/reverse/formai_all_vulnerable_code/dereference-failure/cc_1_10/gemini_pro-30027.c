//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Mutex to protect shared data
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Shared data structure to store word counts
struct word_count {
    char *word;
    int count;
};

// Array of word counts
struct word_count *word_counts;

// Number of words in the array
int num_words;

// Function to compare two word counts
int compare_word_counts(const void *a, const void *b) {
    const struct word_count *wc1 = (const struct word_count *)a;
    const struct word_count *wc2 = (const struct word_count *)b;

    return strcmp(wc1->word, wc2->word);
}

// Function to count the words in a string
void *count_words(void *args) {
    char *text = (char *)args;

    // Tokenize the string
    char *token = strtok(text, " ");

    // Loop through the tokens
    while (token != NULL) {
        // Lock the mutex
        pthread_mutex_lock(&mutex);

        // Find the word in the array of word counts
        struct word_count *wc = bsearch(token, word_counts, num_words, sizeof(struct word_count), compare_word_counts);

        // If the word is not found, add it to the array and the word_counts
        if (wc == NULL) {
            word_counts = realloc(word_counts, (num_words + 1) * sizeof(struct word_count));
            wc = &word_counts[num_words++];
            wc->word = strdup(token);
            wc->count = 0;
        }

        // Increment the word count
        wc->count++;

        // Unlock the mutex
        pthread_mutex_unlock(&mutex);

        // Get the next token
        token = strtok(NULL, " ");
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    // Check if the user specified a file to read
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Read the file into a string
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    char *text = malloc(file_size + 1);
    fread(text, 1, file_size, fp);
    text[file_size] = '\0';

    fclose(fp);

    // Create a thread for each word
    pthread_t *threads = malloc(num_words * sizeof(pthread_t));
    for (int i = 0; i < num_words; i++) {
        pthread_create(&threads[i], NULL, count_words, text);
    }

    // Join the threads
    for (int i = 0; i < num_words; i++) {
        pthread_join(threads[i], NULL);
    }

    // Sort the array of word counts
    qsort(word_counts, num_words, sizeof(struct word_count), compare_word_counts);

    // Print the array of word counts
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    // Free the allocated memory
    free(text);
    free(word_counts);
    free(threads);

    return 0;
}