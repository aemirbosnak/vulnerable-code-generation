//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define NUM_WORDS 1000
#define SPAM_THRESHOLD 0.8

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *file;
    char line[1000];
    char *token;
    int count = 0;
    Word *words[NUM_WORDS];
    int i = 0;

    // Open the file
    file = fopen("spam.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read in the words
    while (fgets(line, sizeof(line), file)!= NULL) {
        token = strtok(line, " ");
        while (token!= NULL) {
            if (count >= NUM_WORDS) {
                printf("Error: Too many words.\n");
                fclose(file);
                return 1;
            }
            strcpy(words[count]->word, token);
            words[count]->count = 0;
            count++;
            token = strtok(NULL, " ");
        }
    }

    // Sort the words
    qsort(words, count, sizeof(Word), compareWords);

    // Read in the email
    file = fopen("email.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Count the words
    while (fgets(line, sizeof(line), file)!= NULL) {
        token = strtok(line, " ");
        while (token!= NULL) {
            for (i = 0; i < count; i++) {
                if (strcmp(token, words[i]->word) == 0) {
                    words[i]->count++;
                    break;
                }
            }
            token = strtok(NULL, " ");
        }
    }

    // Calculate the spamminess score
    double spamScore = 0.0;
    for (i = 0; i < count; i++) {
        spamScore += (double)words[i]->count / strlen(line);
    }

    // Determine if the email is spam
    if (spamScore >= SPAM_THRESHOLD) {
        printf("Spam detected.\n");
    } else {
        printf("No spam detected.\n");
    }

    fclose(file);
    return 0;
}