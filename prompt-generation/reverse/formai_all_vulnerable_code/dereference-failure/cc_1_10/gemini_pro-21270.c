//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 100

typedef struct {
    char* word;
    int count;
} WordFreq;

typedef struct {
    WordFreq words[MAX_WORDS];
    int numWords;
} WordFreqList;

int compareWords(const void* a, const void* b) {
    const WordFreq* wa = (const WordFreq*) a;
    const WordFreq* wb = (const WordFreq*) b;
    return (wb->count - wa->count);
}

WordFreqList* summarizeText(char* text, int numWords) {
    char* wordStart = text;
    char* wordEnd;
    int i = 0;

    WordFreqList* list = (WordFreqList*) malloc(sizeof(WordFreqList));
    list->numWords = 0;

    while (wordEnd = strchr(wordStart, ' ')) {
        int len = wordEnd - wordStart;
        if (len > 0) {
            char* word = (char*) malloc(len + 1);
            strncpy(word, wordStart, len);
            word[len] = '\0';

            // Convert to lower case
            for (int i = 0; i < len; i++) {
                word[i] = tolower(word[i]);
            }

            bool found = false;
            for (int j = 0; j < list->numWords; j++) {
                if (strcmp(list->words[j].word, word) == 0) {
                    list->words[j].count++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                list->words[list->numWords].word = word;
                list->words[list->numWords].count = 1;
                list->numWords++;
            }
        }
        wordStart = wordEnd + 1;
    }
    if (*wordStart != '\0') {
        int len = strlen(wordStart);
        if (len > 0) {
            char* word = (char*) malloc(len + 1);
            strncpy(word, wordStart, len);
            word[len] = '\0';

            // Convert to lower case
            for (int i = 0; i < len; i++) {
                word[i] = tolower(word[i]);
            }

            bool found = false;
            for (int j = 0; j < list->numWords; j++) {
                if (strcmp(list->words[j].word, word) == 0) {
                    list->words[j].count++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                list->words[list->numWords].word = word;
                list->words[list->numWords].count = 1;
                list->numWords++;
            }
        }
    }

    qsort(list->words, list->numWords, sizeof(WordFreq), compareWords);

    if (numWords > list->numWords) {
        numWords = list->numWords;
    }

    WordFreqList* result = (WordFreqList*) malloc(sizeof(WordFreqList));
    result->numWords = numWords;
    for (int i = 0; i < numWords; i++) {
        result->words[i] = list->words[i];
    }

    free(list);

    return result;
}

void printSummary(WordFreqList* list) {
    for (int i = 0; i < list->numWords; i++) {
        printf("%s: %d\n", list->words[i].word, list->words[i].count);
    }
}

int main() {
    char* text = "In this poetic realm of mind-bending code, where words dance and syntax weaves its spell, I summon forth a text summarizer, a tool to tame the torrent of words and extract the essence of any written tapestry. Let us delve into the labyrinth of language, where meaning hides amidst the maze of letters and phrases, and watch as we unravel its secrets with a touch of algorithmic magic.";

    WordFreqList* summary = summarizeText(text, 10);

    printf("Summary:\n");
    printSummary(summary);

    free(summary);

    return 0;
}