//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: systematic
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

// Define maximum word length
#define MAX_WORD_LENGTH 20

// Function to check if a word is in the dictionary
bool check_word(char *word) {
    FILE *dictionary = fopen("dictionary.txt", "r");
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, dictionary)!= NULL) {
        if (strcmp(line, word) == 0) {
            fclose(dictionary);
            return true;
        }
    }
    fclose(dictionary);
    return false;
}

// Function to correct a misspelled word
char *correct_word(char *word) {
    char *corrected_word = malloc(sizeof(char) * (MAX_WORD_LENGTH + 1));
    strcpy(corrected_word, word);
    int j = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            corrected_word[j++] = word[i];
        } else {
            corrected_word[j++] = toupper(word[i]);
        }
    }
    corrected_word[j] = '\0';
    return corrected_word;
}

// Function to check spelling of a sentence
void check_sentence(char *sentence) {
    char *word = strtok(sentence, " ");
    while (word!= NULL) {
        if (!check_word(word)) {
            printf("Misspelled word: %s\n", word);
            printf("Did you mean: %s\n", correct_word(word));
        }
        word = strtok(NULL, " ");
    }
}

// Main function
int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    check_sentence(sentence);
    return 0;
}