//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a word is in the dictionary
bool is_word(char* word) {
    FILE* dictionary = fopen("dictionary.txt", "r");
    char line[100];
    while (fgets(line, sizeof(line), dictionary)!= NULL) {
        char* word_in_dict = strtok(line, " ");
        while (word_in_dict!= NULL) {
            if (strcmp(word_in_dict, word) == 0) {
                fclose(dictionary);
                return true;
            }
            word_in_dict = strtok(NULL, " ");
        }
    }
    fclose(dictionary);
    return false;
}

// Function to check if a word is misspelled
bool is_misspelled(char* word) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return false;
        }
    }
    return is_word(word);
}

// Function to suggest corrections for a misspelled word
void suggest_corrections(char* word) {
    char* corrected_word = (char*) malloc(strlen(word) + 1);
    strcpy(corrected_word, word);
    int i, j;
    for (i = 0; i < strlen(word); i++) {
        for (j = 0; j < 26; j++) {
            if (isalpha(word[i]) && isalpha(word[i] + j) && isalpha(word[i] - j)) {
                corrected_word[i] = word[i] + j;
                if (is_word(corrected_word)) {
                    printf("%s -> %s\n", word, corrected_word);
                    break;
                }
            }
        }
    }
    free(corrected_word);
}

int main() {
    char* word = (char*) malloc(100);
    while (scanf("%s", word)!= EOF) {
        if (is_misspelled(word)) {
            suggest_corrections(word);
        } else {
            printf("%s is spelled correctly.\n", word);
        }
    }
    return 0;
}