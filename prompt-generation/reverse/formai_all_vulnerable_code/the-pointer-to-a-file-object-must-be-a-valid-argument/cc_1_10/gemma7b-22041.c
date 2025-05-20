//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: futuristic
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1024

typedef struct SpamWord {
    char word[MAX_WORDS];
    int frequency;
} SpamWord;

SpamWord words[MAX_WORDS];

void loadSpamWords(FILE *fp) {
    int i = 0;
    char line[MAX_WORDS];

    while (fgets(line, MAX_WORDS, fp) != NULL) {
        SpamWord *word = &words[i];
        strcpy(word->word, line);
        word->frequency = 1;
        i++;
    }
}

int detectSpam(char *message) {
    int i = 0;
    for (SpamWord *word = words; word->word[0] != '\0'; i++) {
        if (strstr(message, word->word) != NULL) {
            word->frequency++;
            return 1;
        }
    }

    return 0;
}

int main() {
    FILE *fp = fopen("spam_words.txt", "r");
    loadSpamWords(fp);
    fclose(fp);

    char message[] = "This is a sample message with the words spam and ham.";

    if (detectSpam(message) == 1) {
        printf("Spam detected!");
    } else {
        printf("No spam detected.");
    }

    return 0;
}