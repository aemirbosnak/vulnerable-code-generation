//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    Word *wordA = (Word *)a;
    Word *wordB = (Word *)b;
    return strcmp(wordA->word, wordB->word);
}

int readWords(char *filename, Word *words) {
    FILE *file;
    char line[100];
    int count = 0;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }
    while (fgets(line, 100, file)) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            Word *newWord = (Word *)malloc(sizeof(Word));
            strcpy(newWord->word, word);
            newWord->count = 0;
            words[count++] = *newWord;
            word = strtok(NULL, " ");
        }
    }
    fclose(file);
    qsort(words, count, sizeof(Word), compareWords);
    return count;
}

int isSpam(char *email, Word *words, int count) {
    int i, j, spamCount = 0;
    char *word;
    for (i = 0; i < count; i++) {
        word = words[i].word;
        for (j = 0; j < strlen(email); j++) {
            if (tolower(email[j]) == tolower(word[0])) {
                if (strlen(word) > 1) {
                    if (email[j + 1] == word[1]) {
                        spamCount++;
                        break;
                    }
                } else {
                    spamCount++;
                    break;
                }
            }
        }
    }
    if (spamCount >= 3) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    Word words[MAX_WORDS];
    int count;
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }
    count = readWords(argv[1], words);
    printf("Loaded %d words from file.\n", count);
    char *email = "buy viagra now and get a free ipad";
    if (isSpam(email, words, count)) {
        printf("Email is spam.\n");
    } else {
        printf("Email is not spam.\n");
    }
    return 0;
}