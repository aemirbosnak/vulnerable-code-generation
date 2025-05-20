//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_WORD_LENGTH 100

struct word {
    char word[MAX_WORD_LENGTH];
    int is_correct;
};

void *check_word(void *arg) {
    struct word *word = arg;
    FILE *dictionary;
    char ch;
    int i = 0;

    dictionary = fopen("dictionary.txt", "r");

    if (dictionary == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    while ((ch = fgetc(dictionary))!= EOF) {
        if (isalpha(ch)) {
            word->word[i++] = tolower(ch);
        }
    }

    word->word[i] = '\0';
    fclose(dictionary);

    if (strcmp(word->word, "") == 0) {
        word->is_correct = 1;
    } else {
        word->is_correct = 0;
    }

    pthread_exit(0);
}

int main() {
    FILE *input_file;
    char line[MAX_WORD_LENGTH];
    int num_threads = 0;
    pthread_t threads[MAX_THREADS];
    struct word words[MAX_THREADS];

    input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL) {
        if (num_threads >= MAX_THREADS) {
            for (int i = 0; i < MAX_THREADS; i++) {
                pthread_join(threads[i], NULL);
            }
            num_threads = 0;
        }

        strcpy(words[num_threads].word, line);
        pthread_create(&threads[num_threads], NULL, check_word, &words[num_threads]);
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(input_file);

    return 0;
}