//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define NUM_BUCKETS 26

typedef struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

typedef struct Bucket {
    Word *words;
    int capacity;
    int size;
} Bucket;

Bucket *createBucket() {
    Bucket *bucket = malloc(sizeof(Bucket));
    bucket->words = calloc(NUM_BUCKETS, sizeof(Word));
    bucket->capacity = NUM_BUCKETS;
    bucket->size = 0;
    return bucket;
}

void insertWord(Bucket *bucket, char *word) {
    int index = tolower(word[0]) - 'a';
    Word *newWord = &bucket->words[index];

    if (newWord->count == 0) {
        strcpy(newWord->word, word);
        newWord->count = 1;
    } else {
        newWord->count++;
    }
}

void processLine(Bucket *bucket, char *line) {
    char *token = strtok(line, " ,.-");
    while (token != NULL) {
        insertWord(bucket, token);
        token = strtok(NULL, " ,.-");
    }
}

void processFile(Bucket *bucket, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        processLine(bucket, line);
    }

    fclose(file);
}

void printResults(Bucket *bucket) {
    for (int i = 0; i < NUM_BUCKETS; i++) {
        Word *word = &bucket->words[i];
        if (word->count > 0) {
            printf("%s: %d\n", word->word, word->count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    Bucket *bucket = createBucket();
    processFile(bucket, argv[1]);
    printResults(bucket);

    free(bucket->words);
    free(bucket);

    return 0;
}