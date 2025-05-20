//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_WORD_SIZE 64
#define MAX_LINE_SIZE 1024

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

typedef struct {
    FILE *file;
    char line[MAX_LINE_SIZE];
    int line_num;
} LineReader;

void *count_words(void *arg) {
    LineReader *reader = (LineReader *) arg;
    WordCount words[MAX_THREADS];

    while (fgets(reader->line, MAX_LINE_SIZE, reader->file)!= NULL) {
        char *word = strtok(reader->line, ",.?!;:");
        int index = 0;

        while (word!= NULL) {
            strcpy(words[index].word, word);
            words[index].count++;
            index++;

            if (index >= MAX_THREADS) {
                break;
            }

            word = strtok(NULL, ",.?!;:");
        }
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        if (strlen(words[i].word) > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <num_threads>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int num_threads = atoi(argv[2]);
    if (num_threads <= 0 || num_threads > MAX_THREADS) {
        printf("Invalid number of threads.\n");
        return 1;
    }

    LineReader readers[num_threads];

    for (int i = 0; i < num_threads; i++) {
        readers[i].file = file;
        readers[i].line_num = 0;
    }

    pthread_t threads[num_threads];

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, count_words, &readers[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(file);
    return 0;
}