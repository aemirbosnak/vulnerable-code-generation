//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

typedef struct SpamWord {
    char word[MAX_WORDS];
    int frequency;
} SpamWord;

SpamWord spamWords[MAX_WORDS];

void loadSpamWords() {
    // Read spam words from a file or other source
    FILE* file = fopen("spam_words.txt", "r");
    if (file) {
        char line[MAX_SENTENCE_LENGTH];
        int i = 0;
        while (fgets(line, MAX_SENTENCE_LENGTH, file) != NULL) {
            SpamWord newWord;
            strcpy(newWord.word, line);
            newWord.frequency = 1;
            spamWords[i++] = newWord;
        }
        fclose(file);
    }
}

int detectSpam(char* sentence) {
    loadSpamWords();

    // Calculate the frequency of each word in the sentence
    int wordCount = 0;
    char* word = strtok(sentence, " ");
    while (word) {
        int i = 0;
        for (SpamWord* wordPtr = spamWords; i < MAX_WORDS; i++) {
            if (strcmp(word, wordPtr->word) == 0) {
                wordPtr->frequency++;
            }
        }
        word = strtok(NULL, " ");
    }

    // Check if any word frequency exceeds the threshold
    for (int i = 0; i < MAX_WORDS; i++) {
        if (spamWords[i].frequency > 5) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char* sentence = "This is a spam email with many repeated words.";
    int isSpam = detectSpam(sentence);

    if (isSpam) {
        printf("The sentence is spam.");
    } else {
        printf("The sentence is not spam.");
    }

    return 0;
}