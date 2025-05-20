//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_SENTENCE_LENGTH];
    int freq;
} WordFreq;

int compareWords(const void *a, const void *b) {
    return (*(WordFreq*)a).freq - (*(WordFreq*)b).freq;
}

void generateSummary(char* inputText, int numSentences) {
    FILE* fp = fopen(inputText, "r");
    char sentence[MAX_SENTENCE_LENGTH];
    char word[MAX_SENTENCE_LENGTH];
    WordFreq words[MAX_WORDS];
    int numWords = 0;
    int i = 0;

    // Read input file
    while (fscanf(fp, "%s", sentence)!= EOF) {
        char* token = strtok(sentence, " ");
        while (token!= NULL) {
            strcpy(word, token);
            int j;
            for (j = 0; j < numWords; j++) {
                if (strcmp(word, words[j].word) == 0) {
                    words[j].freq++;
                    break;
                }
            }
            if (j == numWords) {
                strcpy(words[numWords].word, word);
                words[numWords].freq = 1;
                numWords++;
                if (numWords == MAX_WORDS) {
                    break;
                }
            }
            token = strtok(NULL, " ");
        }
    }
    fclose(fp);

    // Sort words by frequency
    qsort(words, numWords, sizeof(WordFreq), compareWords);

    // Generate summary
    printf("Summary:\n");
    for (i = 0; i < numWords && i < numSentences; i++) {
        printf("%s (%d)\n", words[i].word, words[i].freq);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <num_sentences>\n", argv[0]);
        return 1;
    }

    char* inputText = argv[1];
    int numSentences = atoi(argv[2]);

    generateSummary(inputText, numSentences);

    return 0;
}