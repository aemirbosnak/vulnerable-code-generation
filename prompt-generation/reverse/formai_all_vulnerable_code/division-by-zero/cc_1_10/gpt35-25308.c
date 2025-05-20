//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *buffer;
    int start_index;
    int end_index;
} ThreadData;

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

int num_threads;
pthread_mutex_t lock;
WordFrequency *word_frequency_list;
int word_frequency_count = 0;

void *count_word_frequency(void *thread_arg) {
    ThreadData *data = (ThreadData*)thread_arg;

    // Allocate a temporary buffer to hold a single word
    char *word = (char*) malloc(BUFFER_SIZE * sizeof(char));
    int word_index = 0;

    // Loop through each character in the buffer
    for (int i = data->start_index; i < data->end_index; i++) {
        char c = data->buffer[i];

        // If the character is a whitespace or punctuation, we have found a new word
        if (c == ' ' || c == '\n' || c == '.' || c == ',' || c == '!' || c == '?') {
            // null-terminate the word
            word[word_index] = '\0';

            // update the word frequency in the list
            pthread_mutex_lock(&lock);
            for (int j = 0; j < word_frequency_count; j++) {
                WordFrequency *word_frequency = &word_frequency_list[j];
                if (strcmp(word, word_frequency->word) == 0) {
                    word_frequency->frequency++;
                    break;
                }
            }
            pthread_mutex_unlock(&lock);

            // reset the temporary buffer
            word_index = 0;
        } else {
            // add the character to the temporary buffer
            word[word_index++] = c;
        }
    }

    free(word);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <num_threads>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    num_threads = atoi(argv[2]);

    // allocate the buffer to hold the entire file
    char *buffer = (char*) malloc(BUFFER_SIZE * sizeof(char));
    int buffer_index = 0;

    // open the file for reading
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Could not open file: %s\n", filename);
        return 1;
    }

    // read the file into the buffer
    char c = fgetc(f);
    while (!feof(f)) {
        buffer[buffer_index++] = c;
        c = fgetc(f);
    }

    fclose(f);

    pthread_t threads[num_threads];
    ThreadData thread_data[num_threads];

    // initialize the word frequency list and lock
    pthread_mutex_init(&lock, NULL);
    word_frequency_list = (WordFrequency*) malloc(BUFFER_SIZE * sizeof(WordFrequency));

    // create the threads
    int chunk_size = buffer_index / num_threads;
    for (int i = 0; i < num_threads; i++) {
        ThreadData *data = &thread_data[i];
        data->buffer = buffer;
        data->start_index = i * chunk_size;
        data->end_index = (i == num_threads - 1) ? buffer_index : (i + 1) * chunk_size;

        pthread_create(&threads[i], NULL, count_word_frequency, (void*)data);
    }

    // wait for the threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // print out the word frequencies
    for (int i = 0; i < word_frequency_count; i++) {
        WordFrequency *word_frequency = &word_frequency_list[i];
        printf("%s: %d\n", word_frequency->word, word_frequency->frequency);
    }

    // free the memory
    pthread_mutex_destroy(&lock);
    free(buffer);
    free(word_frequency_list);
    
    return 0;
}