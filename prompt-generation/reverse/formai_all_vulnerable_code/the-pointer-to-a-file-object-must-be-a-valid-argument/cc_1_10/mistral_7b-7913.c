//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define WORD_SEPARATOR " ,.!?:;{}()[]\t\n"
typedef struct Word {
    char *value;
    struct Word *next;
} Word;
Word *current = NULL;
void addWord(char *word) {
    Word *newWord = (Word *)malloc(sizeof(Word));
    newWord->value = strdup(word);
    newWord->next = current;
    current = newWord;
}
void processFile(char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[256];
    int inWord = 0;
    char *word = NULL;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        for (int i = 0; i < strlen(buffer); i++) {
            if (isalpha(buffer[i])) {
                if (!inWord) {
                    word = (char *)malloc(1 * sizeof(char));
                    word[0] = tolower(buffer[i]);
                    addWord(word);
                    inWord = 1;
                } else {
                    Word *last = current;
                    while (current != NULL && strcmp(current->value, "") < 0 && strcmp(current->value, word) > 0) {
                        last = current;
                        current = current->next;
                    }
                    if (current == NULL) {
                        char *newWord = (char *)malloc((strlen(word) + strlen(last->value) + 2) * sizeof(char));
                        strcpy(newWord, last->value);
                        strcat(newWord, word);
                        free(last->value);
                        last->value = newWord;
                    }
                    free(word);
                }
            } else if (inWord) {
                if (strlen(buffer + i) > 0 && strchr(WORD_SEPARATOR, buffer[i + 1]) != NULL) {
                    char *newWord = (char *)malloc((strlen(word) + 1) * sizeof(char));
                    strcpy(newWord, word);
                    addWord(newWord);
                    inWord = 0;
                    i++;
                }
            }
        }
        if (inWord) {
            char *newWord = (char *)malloc((strlen(word) + 1) * sizeof(char));
            strcpy(newWord, word);
            addWord(newWord);
        }
        free(word);
    }
    fclose(file);
}
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    processFile(argv[1]);
    Word *current = NULL;
    while (current != NULL) {
        printf("%s\n", current->value);
        Word *temp = current;
        current = current->next;
        free(temp->value);
        free(temp);
    }
    return 0;
}