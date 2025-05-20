//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct Word {
    char word[MAX_WORD_LENGTH];
    int frequency;
} Word;

Word words[1000];

void analyze_text(char *text) {
    char *word_ptr = text;
    Word *word_list = words;

    while (word_ptr) {
        char word[MAX_WORD_LENGTH];
        int i = 0;

        word_ptr = strsep(word_ptr, " \t\n");

        if (word_ptr) {
            strcpy(word, word_ptr);

            for (i = 0; i < 1000; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].frequency++;
                    break;
                }
            }

            if (i == 1000) {
                Word new_word;
                strcpy(new_word.word, word);
                new_word.frequency = 1;
                words[1000] = new_word;
            }
        }
    }
}

int main() {
    char text[] = "This is a sample text with many words. Some words are repeated several times. The word 'the' is the most repeated word in this text.";

    analyze_text(text);

    for (int i = 0; i < 1000; i++) {
        if (words[i].frequency > 1) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }

    return 0;
}