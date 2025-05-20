//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_SENTENCES 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount *) a;
    WordCount *wordB = (WordCount *) b;
    return strcmp(wordA->word, wordB->word);
}

int main() {
    char sentence[MAX_SENTENCES];
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    WordCount *wordArray = NULL;
    int i;

    printf("Enter a sentence or multiple sentences (up to %d words):\n", MAX_SENTENCES);
    fgets(sentence, MAX_SENTENCES, stdin);
    strcat(sentence, "\n"); // add newline character to end of sentence

    // tokenize sentence into words
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        strcpy(word, token);
        // convert word to lowercase
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        // check if word is already in array
        WordCount *wordInArray = bsearch(word, wordArray, wordCount, sizeof(WordCount), compareWords);
        if (wordInArray == NULL) {
            // word not found, add to array
            wordArray = realloc(wordArray, sizeof(WordCount) * ++wordCount);
            strcpy(wordArray[wordCount-1].word, word);
            wordArray[wordCount-1].count = 1;
        } else {
            // word found, increment count
            wordInArray->count++;
        }
        token = strtok(NULL, " ");
    }

    // sort array by word
    qsort(wordArray, wordCount, sizeof(WordCount), compareWords);

    // print word count for each word
    printf("Word\tCount\n");
    for (i = 0; i < wordCount; i++) {
        printf("%s\t%d\n", wordArray[i].word, wordArray[i].count);
    }

    return 0;
}