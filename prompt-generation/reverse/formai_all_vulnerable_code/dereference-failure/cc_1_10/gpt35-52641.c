//FormAI DATASET v1.0 Category: Spell checking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define MAX_WORD_LENGTH 50
#define MAX_THREADS 5
#define DICTIONARY_FILE "dictionary.txt"

int num_threads = 0;
pthread_mutex_t words_mutex = PTHREAD_MUTEX_INITIALIZER;

struct ThreadParams {
    FILE *input_file;
    FILE *output_file;
    char *word;
};

void *process_word(void *thread_params) {
    struct ThreadParams *params = (struct ThreadParams*) thread_params;
    char *word = params->word;
    FILE *dictionary_file = fopen(DICTIONARY_FILE, "r");
    char dict_word[MAX_WORD_LENGTH];
    int word_found = 0;

    while (fgets(dict_word, MAX_WORD_LENGTH, dictionary_file) != NULL) {
        if (strcmp(dict_word, word) == 0) {
            word_found = 1;
            break;
        }
    }

    fclose(dictionary_file);

    pthread_mutex_lock(&words_mutex);
    if (!word_found) {
        fprintf(params->output_file, "%s", word);
    }
    pthread_mutex_unlock(&words_mutex);

    free(thread_params);
    num_threads--;
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening files\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    pthread_t threads[MAX_THREADS];

    while (fscanf(input_file, "%s", word) != EOF) {
        struct ThreadParams *params = (struct ThreadParams*) malloc(sizeof(struct ThreadParams));
        params->input_file = input_file;
        params->output_file = output_file;
        params->word = strdup(word);

        pthread_create(&threads[num_threads], NULL, &process_word, (void*) params);
        num_threads++;

        if (num_threads == MAX_THREADS) {
            for (int i = 0; i < MAX_THREADS; i++) {
                pthread_join(threads[i], NULL);
            }
            num_threads = 0;
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}