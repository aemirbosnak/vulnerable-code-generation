//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

// Word struct to hold each word
typedef struct {
    char word[MAX_WORD_LEN];
    int frequency;
} Word;

// Function to compare two words
int compareWords(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

// Function to count the frequency of each word
void countWords(char* text, Word* words) {
    char* word = strtok(text, ",.?!;:");
    while (word!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].frequency++;
                break;
            }
        }
        if (i == MAX_WORDS) {
            if (strlen(word) <= MAX_WORD_LEN) {
                strcpy(words[i].word, word);
                words[i].frequency = 1;
            }
        }
        word = strtok(NULL, ",.?!;:");
    }
}

// Function to sort the words by frequency
void sortWords(Word* words) {
    qsort(words, MAX_WORDS, sizeof(Word), compareWords);
}

// Function to print the word cloud
void printWordCloud(Word* words) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].frequency > 0) {
            printf("%s %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char* text = NULL;
    size_t text_size = 0;
    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }
    fseek(file, 0, SEEK_END);
    text_size = ftell(file);
    rewind(file);
    text = malloc(text_size + 1);
    if (text == NULL) {
        printf("Error: could not allocate memory for text\n");
        return 1;
    }
    text_size = fread(text, 1, text_size, file);
    text[text_size] = '\0';
    fclose(file);

    Word words[MAX_WORDS];
    countWords(text, words);
    sortWords(words);
    printWordCloud(words);

    free(text);
    return 0;
}