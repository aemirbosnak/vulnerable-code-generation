//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_WORD_LENGTH 50
#define DICTIONARY_FILE "dictionary.txt"

typedef struct {
    char word[MAX_WORD_LENGTH+1];
    int is_correct;
} WordInfo;

void *check_word(void *arg) {
    WordInfo *word_info = (WordInfo *) arg;
    FILE *dictionary_file = fopen(DICTIONARY_FILE, "r");
    char line[MAX_WORD_LENGTH+1];
    int word_found = 0;

    while (fgets(line, MAX_WORD_LENGTH+1, dictionary_file)!= NULL) {
        if (strcmp(line, word_info->word) == 0) {
            word_found = 1;
            break;
        }
    }

    if (word_found) {
        word_info->is_correct = 1;
    } else {
        word_info->is_correct = 0;
    }

    fclose(dictionary_file);
    return NULL;
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    char line[MAX_WORD_LENGTH+1];
    int num_threads = 0;
    pthread_t threads[MAX_THREADS];

    while (fgets(line, MAX_WORD_LENGTH+1, input_file)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            WordInfo word_info;
            strcpy(word_info.word, word);
            word_info.is_correct = 0;

            int i;
            for (i = 0; i < num_threads && word_info.is_correct == 0; i++) {
                pthread_join(threads[i], NULL);
            }

            if (word_info.is_correct == 0) {
                pthread_create(&threads[num_threads], NULL, check_word, &word_info);
                num_threads++;
            }

            word = strtok(NULL, " ");
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(input_file);
    return 0;
}