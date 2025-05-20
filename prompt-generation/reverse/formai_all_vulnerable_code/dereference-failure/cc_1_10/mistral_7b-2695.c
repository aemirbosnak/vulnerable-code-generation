//MISTRAL-7B DATASET v1.0 Category: Text Summarizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50
#define MIN_SENTENCE_LENGTH 10
#define ALPHABET_SIZE 26

typedef struct {
    char word[WORD_LENGTH];
    int freq;
} Word;

typedef struct {
    Word words[MAX_WORDS];
    int num_words;
} TextSummary;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void processText(const char *text, TextSummary *summary) {
    char words[MAX_WORDS][WORD_LENGTH];
    int num_words = 0;
    char currentWord[WORD_LENGTH];
    int currentLength = 0;

    toLowerCase(text);

    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            currentWord[currentLength++] = text[i];

            if (currentLength == WORD_LENGTH) {
                currentWord[currentLength] = '\0';
                int found = 0;

                for (int j = 0; j < summary->num_words; j++) {
                    if (strchr(summary->words[j].word, currentWord[0]) &&
                        strcmp(&summary->words[j].word[1], &currentWord[1]) == 0) {
                        summary->words[j].freq++;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    strcpy(words[num_words++], currentWord);
                    summary->words[num_words - 1].freq = 1;
                }

                currentLength = 0;
            }
        } else if (currentLength > 0) {
            currentLength--;
        }
    }

    summary->num_words = num_words;
}

void printSummary(const TextSummary *summary) {
    printf("Summary:\n");

    for (int i = 0; i < summary->num_words; i++) {
        int score = summary->words[i].freq * (ALPHABET_SIZE / (double)strlen(summary->words[i].word));
        printf("%s: %d (score: %.2f)\n", summary->words[i].word, summary->words[i].freq, score);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    TextSummary summary = {0};
    const char *text = argv[1];

    processText(text, &summary);
    printSummary(&summary);

    return 0;
}