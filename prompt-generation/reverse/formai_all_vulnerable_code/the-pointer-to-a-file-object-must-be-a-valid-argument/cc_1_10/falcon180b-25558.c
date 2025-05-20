//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a word is in the dictionary
int is_word(char *word) {
    FILE *dict = fopen("dictionary.txt", "r");
    char line[100];
    while (fgets(line, 100, dict)!= NULL) {
        if (strcmp(line, word) == 0) {
            fclose(dict);
            return 1;
        }
    }
    fclose(dict);
    return 0;
}

// Function to suggest corrections for misspelled words
void suggest_corrections(char *word) {
    FILE *dict = fopen("dictionary.txt", "r");
    char line[100];
    while (fgets(line, 100, dict)!= NULL) {
        if (strcmp(line, word)!= 0) {
            int len = strlen(line);
            int dist = 0;
            for (int i = 0; i < len; i++) {
                if (line[i]!= word[i]) {
                    dist++;
                }
            }
            if (dist == 1) {
                printf("%s\n", line);
            }
        }
    }
    fclose(dict);
}

// Function to spell check a sentence
void spell_check(char *sentence) {
    char word[100];
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        strcpy(word, token);
        if (!is_word(word)) {
            printf("%s is not a valid word\n", word);
            suggest_corrections(word);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);
    spell_check(sentence);
    return 0;
}