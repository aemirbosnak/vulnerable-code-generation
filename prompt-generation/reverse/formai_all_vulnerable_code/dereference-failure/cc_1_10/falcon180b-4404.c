//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compareWords(const void *a, const void *b) {
    const struct Word *wordA = (const struct Word *) a;
    const struct Word *wordB = (const struct Word *) b;

    return strcmp(wordA->word, wordB->word);
}

void readWords(FILE *file, struct Word words[]) {
    char line[MAX_WORD_LENGTH];
    char *word;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        word = strtok(line, ",.!?;:'\"");

        while (word!= NULL) {
            int i;
            for (i = 0; i < strlen(word); i++) {
                if (!isalnum(word[i])) {
                    word[i] = '\0';
                }
            }

            int found = 0;
            int j;
            for (j = 0; j < MAX_WORDS; j++) {
                if (strcmp(words[j].word, word) == 0) {
                    words[j].count++;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                strcpy(words[i].word, word);
                words[i].count = 1;
                i++;
            }

            word = strtok(NULL, ",.!?;:'\"");
        }
    }
}

int isSpam(struct Word words[], int numWords, char *message) {
    int i;
    int spamCount = 0;

    for (i = 0; i < numWords; i++) {
        int j;
        for (j = 0; j < strlen(message); j++) {
            if (tolower(message[j]) == tolower(words[i].word[0])) {
                int k;
                for (k = 1; k < strlen(words[i].word); k++) {
                    if (tolower(message[j + k])!= tolower(words[i].word[k])) {
                        break;
                    }
                }

                if (k == strlen(words[i].word)) {
                    spamCount++;
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
    if (argc!= 3) {
        printf("Usage: %s <word_file> <message_file>\n", argv[0]);
        return 1;
    }

    FILE *wordFile = fopen(argv[1], "r");
    FILE *messageFile = fopen(argv[2], "r");

    if (wordFile == NULL || messageFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    struct Word words[MAX_WORDS];
    int numWords = 0;

    readWords(wordFile, words);
    fclose(wordFile);

    char message[MAX_WORD_LENGTH];

    while (fscanf(messageFile, "%s", message)!= EOF) {
        int isSpamMessage = isSpam(words, numWords, message);

        if (isSpamMessage) {
            printf("Spam: %s\n", message);
        } else {
            printf("Not spam: %s\n", message);
        }
    }

    fclose(messageFile);

    return 0;
}