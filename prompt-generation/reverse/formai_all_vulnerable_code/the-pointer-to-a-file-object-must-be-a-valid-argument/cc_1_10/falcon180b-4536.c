//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

WordCount word_counts[MAX_WORDS];
int num_words = 0;

void *count_words(void *arg) {
    FILE *input_file = (FILE *) arg;
    char line[1024];
    char *word;
    int i;

    while (fgets(line, sizeof(line), input_file)!= NULL) {
        word = strtok(line, " \t\r\n\f\v");
        while (word!= NULL) {
            i = 0;
            while (isalnum(word[i]) && i < MAX_WORD_LENGTH - 1) {
                word_counts[num_words].word[i] = tolower(word[i]);
                i++;
            }
            word_counts[num_words].word[i] = '\0';
            word_counts[num_words].count++;
            num_words++;

            if (num_words == MAX_WORDS) {
                break;
            }

            word = strtok(NULL, " \t\r\n\f\v");
        }
    }

    pthread_exit(NULL);
}

void print_word_counts() {
    int i;

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    int i;
    pthread_t threads[10];

    if (argc < 2) {
        printf("Usage: %s FILENAME\n", argv[0]);
        return 1;
    }

    for (i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, count_words, argv[1]);
    }

    for (i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    print_word_counts();

    return 0;
}